#include "game.h"

/**** LAB 1 - given functions ****/
void print_game_state(GameState *gs){
    printf("*** Game State ***\n");
    printf("Score=%d\n", gs->score);
    print_board(gs);
}

void print_options(){
    printf("Options:\n");
    printf("\t%d. Move left\n", MOVE_LEFT);
    printf("\t%d. Move right\n", MOVE_RIGHT);
    printf("\t%d. Rotate clockwise\n", ROTATE_CW);
    printf("\t%d. Rotate counter clockwise\n", ROTATE_CCW);
    printf("\t%d. None\n", NONE);
    printf("\t%d. Show best move\n", SHOW_BEST_MOVE);
    printf("\t%d. Quit game\n", QUIT_GAME);
}

bool is_valid_option(int option){
    return ((MOVE_LEFT <= option) && (option<=QUIT_GAME));
}


void print_line(int columns){
    for(int c=-1; c<MIN_COLUMNS+1; ++c) 
    	printf("-");    
    printf("\n");
}

void print_board(GameState *game_state){
    Piece *piece = &game_state->current_piece.p;
    int p_row_size = piece->rows;
    int p_col_size = piece->cols;
    int current_row = game_state->current_piece.at_row;
    int current_col = game_state->current_piece.at_col;
    print_line(MIN_COLUMNS);
    for(int r = 0; r < MIN_ROWS; ++r){
        if(r == 4) print_line(MIN_COLUMNS);
        printf("|");
        for(int c=0; c < MIN_COLUMNS; ++c){
            if((game_state->board[r][c] == '.') &&
               (current_row <= r) && (r < current_row + p_row_size) && 
               (current_col <= c) && (c < current_col + p_col_size)){
                printf("%c", piece->board[r-current_row][c-current_col]);
            }
            else printf("%c", game_state->board[r][c]);
        }
        printf("|\n");
    }
    print_line(MIN_COLUMNS);
    printf("\n");
}

void get_new_random_piece(GameState *game_state){
    // Random piece
    switch (rand()%MAX_NUM_PIECES){
    case 0:
        game_state->current_piece.p = make_I();
        break;    
    case 1:
        game_state->current_piece.p = make_J();
        break;
    case 2:
        game_state->current_piece.p = make_L();
        break;
    case 3:
        game_state->current_piece.p = make_O();
        break;
    case 4:
        game_state->current_piece.p = make_S();
        break;
    case 5:
        game_state->current_piece.p = make_T();
        break;
    case 6:
        game_state->current_piece.p = make_Z();
        break;
    default:
        break;
    }

    // Random orientation
    int rotations = rand()%3;
    for(int r = 0; r < rotations; ++r)
        rotate_clockwise(&(game_state->current_piece.p));

    // Random location
    game_state->current_piece.at_row = 4 - game_state->current_piece.p.rows;
    game_state->current_piece.at_col = rand() % (MIN_COLUMNS + 1 - game_state->current_piece.p.cols);
}

void block_current_piece(GameState *game_state){
    Piece *piece = &game_state->current_piece.p;
    int row = game_state->current_piece.at_row;
    int col = game_state->current_piece.at_col;
    for(int i=0; i<piece->rows; ++i)
        for(int j=0; j<piece->cols; ++j)
            if(piece->board[i][j] == '#')
                game_state->board[row+i][col+j] = 'X';
}

bool is_collision(GameState *gs, PieceInfo *piece_info){
    Piece *piece = &piece_info->p;
    int p_row_size = piece->rows;
    int p_col_size = piece->cols;
    int row = piece_info->at_row;
    int col = piece_info->at_col;

    if((row < 0) || (col < 0) || (row+p_row_size-1 >= MIN_ROWS) || (col+p_col_size-1 >= MIN_COLUMNS))
    	return true; // piece is out of the grid bounds
    
    for(int i=0; i<piece->rows; ++i)
        for(int j=0; j<piece->cols; ++j)
            if((piece->board[i][j] == '#') && (gs->board[row+i][col+j] == 'X'))
            	return true; // piece collides with another structure in the board
    
    return false;
}

int remove_completed_lines(GameState *game_state){
    int lines = 0;
    bool completed_line;
    for(int r=4; r<MIN_ROWS; ++r){
        completed_line = true;
        for(int c=0; c<MIN_COLUMNS; ++c){
            if(game_state->board[r][c] != 'X'){
                completed_line = false; 
                break;
            }
        }
        if(completed_line){
            ++lines;
            // Move all rows above, once down
            for(int r2=r; r2>3; --r2){
                for(int c=0; c<MIN_COLUMNS; ++c){
                    game_state->board[r2][c] = game_state->board[r2-1][c];
                }
            }
        }
    }
    return lines;
}

/********************************************************/
/******* LAB 2 - functions to program (start here) ******/
/********************************************************/

void make_board(GameState *game_state){
    // ALLOCATE memory for de board
    if(game_state->board == NULL){
        game_state->board = (char**)malloc(sizeof(char*)*game_state->rows);
        for (int i = 0; i < game_state->rows; i++){
            game_state->board[i] = (char*)malloc(sizeof(char)*game_state->columns);
        }
    }
    //reallocate 
    else{
        game_state->board = (char**)realloc(game_state->board, sizeof(char*)*game_state->rows);
        for (int i = 0; i < game_state->rows; i++){
            game_state->board[i] = (char*)malloc(sizeof(char)*game_state->columns);
        }
    }
}

void free_game_state(GameState *game_state){
    if (game_state->board != NULL){
        for (int i = 0; i < game_state->rows; i++){
            free(game_state->board[i]);
        }
        free(game_state->board);
    }
}

void set_default_game_state(GameState *gs){
    gs->score = 0;

    for (int i = 0; i < gs->rows; i++){
        for (int j = 0; i < gs->columns; i++){
            gs->board[i][j] = '.';
        }
    }

    get_new_random_piece(gs);
}

void restart_game_state(GameState *gs){
    do {
        printf("Introdueix el nombre de files (mínim %d): ", MIN_ROWS);
        scanf("%i", &gs->rows);

        if (gs->rows < MIN_ROWS) {
            printf("[ERROR!]: Les dimensions han de ser més grans que %d.\n", MIN_ROWS);
        }
    }while(gs->rows < MIN_ROWS);
    
    do{
        printf("Introdueix el nombre de files (mínim %d): ", MIN_COLUMNS);
        scanf("%i", &gs->columns);

        if (gs->rows < MIN_COLUMNS) {
            printf("[ERROR!]: Les dimensions han de ser més grans que %d.\n", MIN_COLUMNS);
        }

    }while (gs->rows < MIN_COLUMNS);

    make_board(gs);
    set_default_game_state(gs);
}

/********************************************************/
/******* LAB 2 - functions to program (end here) ********/
/********************************************************/


/********************************************************/
/******* LAB 1 - functions to program (start here) ******/
/********************************************************/

void init_game_state(GameState *game_state){
    game_state->score = 0;
    game_state->board = NULL;
    game_state->rows = MIN_ROWS;
    game_state->columns = MIN_COLUMNS;
    make_board(game_state);
    for(int i = 0; i < MIN_ROWS; i++){
        for(int j = 0; j < MIN_COLUMNS; j++){
            game_state->board[i][j] = '.'; 
        }
    }

    get_new_random_piece(game_state);
}


bool is_terminal(GameState *gs){
    // Recorrem les quatre primeres files per veure si hi ha alguna peça bloquejada ('X')
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < MIN_COLUMNS; j++){
            if (gs->board[i][j] == 'X'){
                return true; // Si trobem una peça bloquejada en les files superiors, el joc acaba
            }
        }
    }
    return false; // Si no hi ha peces bloquejades a dalt, el joc continua
}

void move_piece(GameState *gs, PieceInfo *piece_info, int option){
    PieceInfo temp_piece = *piece_info;  // Es crea una còpia temporal de la peça actual

    if (option == MOVE_LEFT){
        temp_piece.at_col--;  // Mou la peça una columna a l'esquerra
        if (!is_collision(gs, &temp_piece)){  // Comprova si hi ha col·lisió
            piece_info->at_col--;  // Si no hi ha col·lisió, es confirma el moviment
        }
    }
    else if (option == MOVE_RIGHT){  
        temp_piece.at_col++;  // Incrementa la columna (possiblement incorrecte per rotació)
        if (!is_collision(gs, &temp_piece)){  
            piece_info->at_col++;  // Aplica el canvi si no hi ha col·lisió
        }
    }
}

// Funció per girar la peça
void rotate_piece(GameState *gs, PieceInfo *piece_info, int option){
    PieceInfo temp_piece = *piece_info;  // Es crea una còpia temporal per provar la rotació

    if (option == ROTATE_CW){
        rotate_clockwise(&temp_piece.p);  // Gira la peça en sentit horari
        if (!is_collision(gs, &temp_piece)){  
            piece_info->p = temp_piece.p;  // Aplica la rotació si és vàlida
        }
    }
    else if (option == ROTATE_CCW){
        rotate_counter_clockwise(&temp_piece.p);  // Gira la peça en sentit antihorari
        if (!is_collision(gs, &temp_piece)){  
            piece_info->p = temp_piece.p;  // Aplica la rotació si no hi ha col·lisió
        }
    }
}

/********************************************************/
/******* LAB 1 - functions to program (end here) ********/
/********************************************************/


void run_turn(GameState *game_state, int option){
	PieceInfo *p_inf = &(game_state->current_piece);
	if(option == MOVE_LEFT || option == MOVE_RIGHT) 
		move_piece(game_state, p_inf, option);
	else if(option == ROTATE_CW || option == ROTATE_CCW)
		rotate_piece(game_state, p_inf, option);
    else if(option == NONE){} // do nothing
    else{ printf("[ERROR] Invalid option %d.\n", option); exit(-3); }

	// Move down if possible, otherwise block the piece and remove
    // the completed lines, aggregating them to the current score.
    // If it is not in a terminal state, add a new random piece to the board.
	p_inf->at_row++;
	if(is_collision(game_state, p_inf)){
		p_inf->at_row--;
		block_current_piece(game_state);
        game_state->score += remove_completed_lines(game_state);
        if(!is_terminal(game_state))
            get_new_random_piece(game_state);
	}
}
