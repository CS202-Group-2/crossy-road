#include "../include/CLANE.h"

CLANE::CLANE(int index, COBJECTFACTORY* factory, sf::RenderWindow * window) {
	this->index = index;
	this->factory = factory;
	this->window = window;
	this->initObject();
	
}

CLANE::~CLANE() {
	delete object;
	delete factory;
}

void CLANE::initObject() {
	object = factory->initObject(index, window);
	factory->initBackground(index, textureLane);

	laneBackground.setTexture(textureLane);
	double scaleX = (window->getSize().x * 2 + 100) / laneBackground.getGlobalBounds().width;
	laneBackground.setScale(scaleX, scaleX);
	laneBackground.setPosition(0, (index - 2) * Constants::GetInstance().LANE_WIDTH);
}

bool CLANE::updatePosObject(float x, float y, sf::RenderWindow &window, CPEOPLE &player, CTRAFFIC &traffic) {
	window.draw(laneBackground);
	if (object->checkOutWindow(window)) {
		
		delete object;
		object = factory->initObject(index, this->window);
	}
	//object->trafficStop(traffic.checkStop());
	if (!object->update(x, y, window, player, index)) return false;
	return true;
}

void CLANE::shiftLane() {
	index++;
	object->shiftObject();
	this->shiftBackground();
}

void CLANE::shiftBackground() {
	laneBackground.setPosition(0, (index - 2) * Constants::GetInstance().LANE_WIDTH);
}