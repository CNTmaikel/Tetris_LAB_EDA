#include "session.h"

//------------------- REINICI SESSIO DEL JOC -------------------

void restart_session_game_state(Session *session){

    init_game_state(&session->current_game_state);  // Iniciem el estat actual del joc

}

//--------------------------------------------------------------

//-------------------- INICI SESSIO DEL JOC --------------------

void init_session(Session *session){

    session->best_score = 0;                    // Iniciem la millor puntuació a 0
    restart_session_game_state(session);        // Reiniciem el joc actual

}

//--------------------------------------------------------------