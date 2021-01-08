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

void CTRANSITION::reset() {
	//reset time here
	cout << "reset\n";
	maxLaneX = laneX + constLaneX; //const offset
	maxLaneY = laneY + constLaneY;
	maxObjectX = objectX + constObjectX;
	maxObjectY = objectY + constObjectY;
	clock.restart();
}

void CTRANSITION::stopAll() {
	laneX = 0, laneY = 0, objectX = 0, objectY = 0,
		maxLaneX = 0, maxLaneY = 0, maxObjectX = 0, maxObjectY = 0;
	clock.restart();
}

void CTRANSITION::update() {
	laneX = getOffset(maxLaneX);
	laneY = getOffset(maxLaneY);
	objectX = getOffset(maxObjectX);
	objectY = getOffset(maxObjectY);
}

float CTRANSITION::getOffset(float maxOffset) {
	return maxOffset * pow(base, clock.getElapsedTime().asSeconds());
}