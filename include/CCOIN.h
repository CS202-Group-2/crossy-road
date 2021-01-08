#pragma once
#include "COBJECT.h"

class CCOIN : public COBJECT {
private:
public:
	CCOIN(float x, float y, int index);
	//bool update(float x, float y, sf::RenderWindow& window, CPEOPLE& player, int index);
	void crashSound();
	void trafficStop(bool state);
};