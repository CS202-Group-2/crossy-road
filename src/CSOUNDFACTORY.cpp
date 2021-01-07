#include "../include/CSOUNDFACTORY.h"

CSOUNDFACTORY::CSOUNDFACTORY () {
    this->soundSystem = new CSOUND ();
    this->soundJump = new CJUMP ();
    this->soundCoin = new CEAT ();
    this->soundLose = new CGAMEOVER ();
}

void CSOUNDFACTORY::playSound (int state) {
    if (muted) return;
    switch (state) {
    case 1: //background sound
        soundSystem->playBackgroundSound ();
        break;
    case 2: //jump of player
        soundJump->playJumpSound ();
        break;
    case 3: //coin 
        soundCoin->playJumpSound ();
        break;
    case 4: //game over
        soundLose->playJumpSound ();
        //cout << "haha" << endl;
        break;
    }
}

CSOUNDFACTORY::~CSOUNDFACTORY () {
    delete soundSystem;
    delete soundJump;
    delete soundLose;
    delete soundCoin;
}