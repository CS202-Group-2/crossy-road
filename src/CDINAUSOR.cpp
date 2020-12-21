#include "../include/CDINAUSOR.h"

CDINAUSOR::CDINAUSOR(int x, int y) {
    this->mX = x;
    this->mY = y;
}

void CDINAUSOR::move(int x, int y) {
    CANIMAL::move (x, y);
}

void CDINAUSOR::tell() {
    //play sound
}