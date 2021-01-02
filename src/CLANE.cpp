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
	object = factory->initObject(index, textureLane, laneBackground, window);
}

void CLANE::updatePosObject(float x, float y, sf::RenderWindow &window, CPEOPLE &player) {
	window.draw(laneBackground);
	object->update(1, 1, window, player);
	
}