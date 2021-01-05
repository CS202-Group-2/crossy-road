#pragma once
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "../include/COBJECT.h"
#include "../include/Constants.h"

class COBJECTFACTORY {
protected:

public:
	virtual void initBackground(int index, sf::Texture& textureLane, sf::Sprite& laneBackground, sf::RenderWindow* window);
	virtual COBJECT* initObject(int index, sf::RenderWindow* window) = 0;
	virtual void shiftBackground(int index, sf::Sprite& laneBackground) = 0;
};