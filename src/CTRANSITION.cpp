#include "../include/CTRANSITION.h"

CTRANSITION::CTRANSITION() :
	laneX(0), laneY(0), objectX(0), objectY(0),
	maxLaneX(0), maxLaneY(0), maxObjectX(0), maxObjectY(0) {}

CTRANSITION& CTRANSITION::offset() {
	static CTRANSITION instance;
	return instance;
}

float CTRANSITION::getLaneX() {
	return activated ? laneX : 0;
}

float CTRANSITION::getLaneY() {
	return activated ? laneY : 0;
}

float CTRANSITION::getObjectX() {
	return activated ? objectX : 0;
}

float CTRANSITION::getObjectY() {
	return activated ? objectY : 0;
}

void CTRANSITION::reset(int times) {
	//reset time here
	cout << "reset\n";
	maxLaneX = laneX + constLaneX * times; //const offset
	maxLaneY = laneY + constLaneY * times;
	maxObjectX = objectX + constObjectX * times;
	maxObjectY = objectY + constObjectY * times;
	clock.restart();
}

void CTRANSITION::update(bool isSlow) {
	laneX = getOffset(maxLaneX, isSlow);
	laneY = getOffset(maxLaneY, isSlow);
	objectX = getOffset(maxObjectX, isSlow);
	objectY = getOffset(maxObjectY, isSlow);
}

float CTRANSITION::getOffset(float maxOffset, bool isSlow) {
	return maxOffset * pow(isSlow ? slowBase : base, clock.getElapsedTime().asSeconds());
}