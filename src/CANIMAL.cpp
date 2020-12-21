#include "../include/CANIMAL.h"

void CANIMAL::move(int x, int y) {
	//srand(time(NULL));
	mX = x + (rand () % 10 + 1);
	mY = y;
}

void CANIMAL::tell() {
    
}