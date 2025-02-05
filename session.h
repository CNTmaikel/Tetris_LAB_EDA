#ifndef _SESSION_H_
#define _SESSION_H_ 

#include "game.h"

/// LAB 1 - data structure
typedef struct{

    int best_score;                     // Guardem la millor puntuacio
    GameState current_game_state;       // Guardem el estat actual de la partida

} Session;

/// LAB 1 - functions

void restart_session_game_state(Session *session);
void init_session(Session *session);

#endif