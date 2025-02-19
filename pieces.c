#include "pieces.h"

//------------------------ INICIIAR PEÇA ----------------------
void init_piece(Piece *p){

    p -> name = '-';                                //Posem un caracter per defecte per initzialitzar 
    for (int i = 0; i<PIECE_SIZE; i++){             //Inicialitzem el tauler del tetris amb '.'
        for(int j=0; j<PIECE_SIZE; j++){
            p -> board[i][j] = '.';
        }
    }

    // Iniciamlitzem les dimensions de la peca a 0
    p -> rows = 0;                         
    p -> cols = 0;

}
//-------------------------------------------------------------

//--------------------- IMPRIMIR PEÇA -------------------------
void print_piece(Piece p){

    printf("Name: %c; Size: %dx%d\n", p.name, p.rows, p.cols);      // Imprimim les caracteristiques de la peça
    
    // Imprimir la peça en el tauler
    for(int i=0; i<PIECE_SIZE; ++i){    
        for(int j=0; j<PIECE_SIZE; ++j){
            printf("%c", p.board[i][j]);
        }
        printf("\n");
    }

}
//-------------------------------------------------------------

//-------------------- ROTACIÓ HORARIA ------------------------
void rotate_clockwise(Piece *p){

    Piece temp;                 // Creem una peça temporal per guardar la rotacio
    init_piece(&temp);          // Inicialitzem la copia temporal

    // Rotem el tauler en el sentit horari

    for (int i = 0; i < p->rows; i++) {
        for (int j = 0; j < p->cols; j++) {
            temp.board[j][p->rows - 1 - i] = p->board[i][j];
        }
    }

    // Actualitzem el tauler original amb els valors rotats
    for (int i = 0; i < p->cols; i++) {
        for (int j = 0; j < p->rows; j++) {
            p->board[i][j] = temp.board[i][j];
        }
    }

    // Intercambiem las dimensions de la peça
    int temp_dim = p->rows;
    p->rows = p->cols;
    p->cols = temp_dim;
}

//-------------------------------------------------------------

//------------------ ROTACIÓ ANTIHORARIA ----------------------

void rotate_counter_clockwise(Piece *p){

    //Rotar 3 vegades clockwise
    rotate_clockwise(p);
    rotate_clockwise(p);
    rotate_clockwise(p);
}

//-------------------------------------------------------------

//-------------------------- PEÇA O ---------------------------

Piece make_O(){

    Piece piece;                // Creem una peça
    init_piece(&piece);         // Inicialitzem la peça
    piece.name = 'O';           // Li assignem el nom O
    
    // Definim les seves dimensions
    piece.rows = 2; 
    piece.cols = 2;

    // Dibuixem la peça com correspon
    piece.board[0][0] = '#';
    piece.board[0][1] = '#';
    piece.board[1][0] = '#';
    piece.board[1][1] = '#';

    return piece;               // Retornem la peça O

}

//-------------------------------------------------------------

//-------------------------- PEÇA I ---------------------------

Piece make_I(){

    Piece piece;                // Creem una peça
    init_piece(&piece);         // Inicialitzem la peça
    piece.name = 'I';           // Li assignem el nom I

    // Definim les seves dimensions
    piece.rows = 4;
    piece.cols = 1;

    // Dibuixem la peça com correspon
    piece.board[0][0] = '#';
    piece.board[1][0] = '#';
    piece.board[2][0] = '#';
    piece.board[3][0] = '#';

    return piece;               // Retornem la peça I
}

//-------------------------------------------------------------

//-------------------------- PEÇA S ---------------------------

Piece make_S(){

    Piece piece;                // Creem una peça
    init_piece(&piece);         // Inicialitzem la peça
    piece.name = 'S';           // Li assignem el nom S
    
    // Definim les seves dimensions
    piece.rows = 2;
    piece.cols = 3;
    
    // Dibuixem la peça com correspon
    piece.board[0][0] = '#';
    piece.board[0][1] = '#';
    piece.board[0][2] = '#';
    piece.board[1][1] = '#';

    return piece;               // Retornem la peça S
}

//-------------------------------------------------------------

//-------------------------- PEÇA Z ---------------------------

Piece make_Z(){
    
    Piece piece;                // Creem una peça 
    init_piece(&piece);         // Inicialitzem la peça
    piece.name = 'Z';           // Li assignem el nom 0

    // Definim les seves dimensions
    piece.rows = 2;
    piece.cols = 3;
    
    // Dibuixem la peça com correspon
    piece.board[0][0] = '#';
    piece.board[0][1] = '#';
    piece.board[1][1] = '#';
    piece.board[1][2] = '#';

    return piece;               // Retornem la peça Z
}

//-------------------------------------------------------------

//-------------------------- PEÇA L ---------------------------

Piece make_L(){
    
    Piece piece;                // Creem una peça
    init_piece(&piece);         // Inicialitzem la peça
    piece.name = 'L';           // Li assignem el nom L
    
    // Definim les seves dimensions
    piece.rows = 3;
    piece.cols = 2;
    
    // Dibuixem la peça com correspon
    piece.board[0][0] = '#';
    piece.board[1][0] = '#';
    piece.board[2][0] = '#';
    piece.board[2][1] = '#';

    return piece;               // Retornem la peça L
}

//-------------------------------------------------------------

//-------------------------- PEÇA J ---------------------------

Piece make_J(){

    Piece piece;                // Creem la peça
    init_piece(&piece);         // Inicialitzem la peça
    piece.name = 'J';           // Li assignem el nom J

    // Definim les seves dimensions
    piece.rows = 2;
    piece.cols = 3;

    // Dibuixem la peça com correspon
    piece.board[0][1] = '#';
    piece.board[1][1] = '#';
    piece.board[2][1] = '#';
    piece.board[2][0] = '#';

    return piece;               // Retornem la peça J
}

//-------------------------------------------------------------

//-------------------------- PEÇA T ---------------------------

Piece make_T(){
    
    Piece piece;                // Creem una peça 
    init_piece(&piece);         // Inicialitzem la peça
    piece.name = 'T';           // Li assignem el nom T       

    // Definim les seves dimensions
    piece.rows = 2;
    piece.cols = 3;

    // Dibuixem la peça com correspon
    piece.board[0][0] = '#';
    piece.board[0][1] = '#';
    piece.board[1][1] = '#';
    piece.board[1][2] = '#';

    return piece;               // Retornem la peça T
}

//-------------------------------------------------------------