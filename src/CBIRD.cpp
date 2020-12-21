#include "../include/CBIRD.h"

CBIRD::CBIRD (int x, int y) {
    this->mX = x;
    this->mY = y;
}

void CBIRD::move(int x, int y) {
    CANIMAL::move (x, y);
}

void CBIRD::tell() {
    //play sound
}