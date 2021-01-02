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
	object = factory->initObject(index,  window);
	factory->initBackground(index, textureLane, laneBackground, window);
}

void CLANE::updatePosObject(float x, float y, sf::RenderWindow &window, CPEOPLE &player, CTRAFFIC &traffic) {
	window.draw(laneBackground);
	if (object->checkOutWindow(window)) {
		delete object;
		object = factory->initObject(index, this->window);
	}
	object->trafficStop(traffic.checkStop());
	object->update(1, 1, window, player);
}