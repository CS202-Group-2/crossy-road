#pragma once
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "../include/CSOUND.h"
#include "../include/Constants.h"
#include "../include/CSOUND.h"
#include "../include/CJUMP.h"
#include "../include/CEAT.h"
#include "../include/CGAMEOVER.h"

class CSOUNDFACTORY {
protected:
	CSOUND* soundSystem;
	CJUMP* soundJump;
	CEAT* soundCoin;
	CGAMEOVER* soundLose;
public:
	CSOUNDFACTORY ();
	void playSound (int state);
	~CSOUNDFACTORY ();
};