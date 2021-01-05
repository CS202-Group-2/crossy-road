#pragma once
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "../include/CSOUND.h"
#include "../include/COBJECTFACTORY.h"
#include "../include/CCAR.h"
#include "../include/Constants.h"
#include "../include/CSOUND.h";
#include "../include/CJUMP.h"

class CSOUNDFACTORY {
protected:
	CSOUND* soundSystem;
	CJUMP* soundJump;
public:
	CSOUNDFACTORY ();
	void playSound (int state);
};