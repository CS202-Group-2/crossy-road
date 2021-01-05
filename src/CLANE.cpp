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
	delete coin;
}

void CLANE::initObject() {
	CCOINFACTORY* coinFactory = new CCOINFACTORY();
	coin = coinFactory->initObject(index, window);
	object = factory->initObject(index, window);
	factory->initBackground(index, textureLane);
	delete coinFactory;
	laneBackground.setTexture(textureLane);
	double scaleX = (window->getSize().x * 2 + 100) / laneBackground.getGlobalBounds().width;
	laneBackground.setScale(scaleX, scaleX);
	laneBackground.setPosition(0, (index - 2) * Constants::GetInstance().LANE_WIDTH);
}

bool CLANE::updatePosObject(float x, float y, sf::RenderWindow &window, CPEOPLE &player, CTRAFFIC &traffic) {
	window.draw(laneBackground);

	if (object == nullptr) return true;
	if (object->checkOutWindow(window)) {
		
		delete object;
		object = factory->initObject(index, this->window);
	}
	object->trafficStop(traffic.checkStop());
	coin->update(x, y, window, player, index);
	if (!object->update(x, y, window, player, index)) return false;
	return true;
}

void CLANE::shiftLane() {
	index++;
	this->shiftBackground();
	if (object != nullptr) 
		object->shiftObject();
	if (coin != nullptr) coin->shiftObject();
	
}

void CLANE::shiftBackground() {
	laneBackground.setPosition(0, (index - 3) * Constants::GetInstance().LANE_WIDTH);
	//object->shiftObject();
	//coin->shiftObject();
	//factory->shiftBackground(index, laneBackground);
}

void CLANE::saveLane(ofstream& out) {
	out << index << " ";
	if (object != nullptr)
		out << object->getTextureFile() << " " << object->mX << " " << object->mY << " " << object->speedMult << " ";
	else
		out << "none";
	if (coin != nullptr)
		out << "Coin " << coin->mX << " " << coin->mY;
	else
		out << "none";
	out << endl;
}