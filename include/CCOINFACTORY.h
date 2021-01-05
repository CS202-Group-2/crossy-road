#pragma once
#include "COBJECTFACTORY.h"
#include "CCOIN.h"

class CCOINFACTORY : public COBJECTFACTORY {
public:
	virtual void initBackground(int index, sf::Texture& textureLane, sf::Sprite& laneBackground, sf::RenderWindow* window);
	virtual COBJECT* initObject(int index, sf::RenderWindow* window);
	virtual void shiftBackground(int index, sf::Sprite& laneBackground);
};