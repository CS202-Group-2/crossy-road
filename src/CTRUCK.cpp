#include "../include/CTRUCK.h"

void CTRUCK::move(int x, int y) {
	CVEHICLE::move(x,y);
}

CTRUCK::CTRUCK(int x, int y) {
	this->mX = x;
	this->mY = y;
}