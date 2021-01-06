#pragma once
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "../include/COBJECT.h"
#include "../include/COBJECTFACTORY.h"
#include "../include/CTREEFACTORY.h"
#include "../include/CCAR.h"
#include "../include/Constants.h"

class CGRASSFACTORY : public COBJECTFACTORY {
protected:

public:
	virtual void initBackground(int index, sf::Texture& textureLane);
	virtual COBJECT* initObject(int index, sf::RenderWindow* window);
};
