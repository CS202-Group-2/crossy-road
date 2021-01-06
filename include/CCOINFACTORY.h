#pragma once
#include "COBJECTFACTORY.h"
#include "CCOIN.h"

class CCOINFACTORY : public COBJECTFACTORY {
public:
	void initBackground(int index, sf::Texture& textureLane, bool& isGrass);
	virtual COBJECT* initObject(int index, sf::RenderWindow* window);
	//virtual void shiftBackground(int index, sf::Sprite& laneBackground);
};

