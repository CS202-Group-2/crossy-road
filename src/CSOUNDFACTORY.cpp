#include "../include/CSOUNDFACTORY.h"

CSOUNDFACTORY::CSOUNDFACTORY () {
    this->soundSystem = new CSOUND ();
    this->soundJump = new CJUMP ();
}

void CSOUNDFACTORY::playSound (int state) {
    switch (state) {
    case 1:
        soundSystem->playBackgroundSound ();
        break;
    case 2:
        soundJump->playJumpSound ();
        break;
    case 3: //coin 
        //
        break;
    case 4: //game over
        //
        break;
    }
}