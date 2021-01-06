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
	virtual void initBackground(int index, sf::Texture& textureLane, bool& isGrass);
	virtual COBJECT* initObject(int index, sf::RenderWindow* window);
};