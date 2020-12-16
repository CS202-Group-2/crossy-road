#include "../include/CVEHICLE.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

void CVEHICLE::move(int x, int y) {
	//srand(time(NULL));
	mX = x + (rand()%10+1);
	mY = y;
}