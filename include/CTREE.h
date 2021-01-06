#pragma once
#include "../include/COBJECT.h"

class CTREE : public COBJECT {
public:
	CTREE(float x, float y, int index);
	//bool update(float x, float y, sf::RenderWindow& window, CPEOPLE& player, int index);
	void tell();
	void trafficStop(bool state);
};