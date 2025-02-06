#ifndef _GAME_H_
#define _GAME_H_

#include "common.h"
#include "utils.h"
#include "pieces.h"

/// ToDo in LAB 1 - define macros MAX_ROWS and MAX_COLUMNS //FET
#define MAX_ROWS 12
#define MAX_COLUMNS 6

typedef struct{
    // ToDo in LAB 1 - define data structure FET!!
    Piece p; // La peça actual que s'està movent
    int at_row; // Posició actual de la peça en files
    int at_col; // Posició actual de la peça en columnes

} PieceInfo;

typedef struct{
    // ToDo in LAB 1 - define data structure FET!!!
    int score; // Puntuació del jugador
    char board[MAX_ROWS][MAX_COLUMNS]; // Matriu que representa el tauler de joc
    PieceInfo current_piece; // Informació de la peça en moviment

} GameState;

/// Implemented functions
void print_game_state(GameState *gs);
void print_options();
bool is_valid_option(int option);
void print_line();
void print_board(GameState *game_state);
void get_new_random_piece(GameState *game_state);
void block_current_piece(GameState *game_state);
bool is_collision(char board[MAX_ROWS][MAX_COLUMNS], PieceInfo *piece_info);

/**** LAB 1 - functions to program (start here) ****/
void init_game_state(GameState *game_state); // Inicialitza el joc amb una puntuació de 0 i el tauler buit
bool is_terminal(char board[MAX_ROWS][MAX_COLUMNS]); // Comprova si el joc ha acabat (una peça bloquejada en les 4 files superiors)
void move(char board[MAX_ROWS][MAX_COLUMNS], PieceInfo *piece_info, int option); // Mou la peça a l'esquerra o a la dreta
void rotate(char board[MAX_ROWS][MAX_COLUMNS], PieceInfo *piece_info, int option); // Gira la peça en el sentit indicat
/**** LAB 1 - functions to program (end here) ****/

/// Implemented functions
void run_turn(GameState *game_state, int option);


#endif
