#pragma once
#include "COBJECTFACTORY.h"
#include "CCOIN.h"

class CCOINFACTORY : public COBJECTFACTORY {
public:
	void initBackground(int index, sf::Texture*& textureLane, bool& isGrass, string& background);
	COBJECT* initObject(int index, sf::RenderWindow* window, int level);
	//virtual void shiftBackground(int index, sf::Sprite& laneBackground);
	bool isGrass();
};

