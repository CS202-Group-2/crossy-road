#pragma once
#include "../include/COBJECT.h"

class CTREE : public COBJECT {
public:
	CTREE(float x, float y, int index, int bushType = -1);
	//bool update(float x, float y, sf::RenderWindow& window, CPEOPLE& player, int index);
	void trafficStop(bool state);
};