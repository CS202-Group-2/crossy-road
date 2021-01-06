#pragma once
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "../include/COBJECT.h"
#include "../include/COBJECTFACTORY.h"
#include "../include/CCAR.h"
#include "../include/Constants.h"

class CCARFACTORY : public COBJECTFACTORY {
protected:
	
public:
	void initBackground(int index, sf::Texture& textureLane, bool& isGrass);
	COBJECT* initObject(int index, sf::RenderWindow* window, int level);
};