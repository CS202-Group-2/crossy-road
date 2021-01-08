#pragma once
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "../include/COBJECT.h"
#include "../include/COBJECTFACTORY.h"
#include "../include/CANIMAL.h"
#include "../include/Constants.h"

class CANIMALFACTORY : public COBJECTFACTORY {
protected:

public:
	void initBackground(int index, sf::Texture* & textureLane, bool& isGrass, string& background);
	COBJECT* initObject(int index, sf::RenderWindow* window, int level);
	bool isGrass();
};