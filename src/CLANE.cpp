#include "../include/CLANE.h"

CLANE::CLANE(int index, COBJECTFACTORY* factory, sf::RenderWindow * window) {
	this->index = index;
	this->factory = factory;
	this->window = window;
	this->initObject();
}

// For loading saved game.
CLANE::CLANE(int index, sf::RenderWindow* window, COBJECTFACTORY* factory, string textureFile, float objX, float objY, float objSpeed, float coinX, float coinY) {
	this->index = index;
	this->window = window;
	this->factory = factory;
	if (coinX != -1e9)
		this->coin = new CCOIN(coinX, coinY, index);
	else
		this->coin = nullptr;
	if (textureFile != "none") {
		if (textureFile[0] == 'a')
			this->object = new CANIMAL(textureFile, objX, objY, objSpeed);
		else
			this->object = new CCAR(textureFile, objX, objY, objSpeed);
	}
	else
		this->object = nullptr;
	factory->initBackground(index, textureLane);
	setupLaneBackground();
}

void CLANE::setupLaneBackground() {
	laneBackground.setTexture(textureLane);
	double scaleX = (window->getSize().x * 2 + 100) / laneBackground.getGlobalBounds().width;
	laneBackground.setScale(scaleX, scaleX);
	laneBackground.setPosition(0, (index - 3) * Constants::GetInstance().LANE_WIDTH);
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
	setupLaneBackground();
}

bool CLANE::updatePosObject(float x, float y, sf::RenderWindow &window, CPEOPLE &player, CTRAFFIC &traffic) {
	window.draw(laneBackground);

	if (object == nullptr) return true;
	if (object->checkOutWindow(window)) {
		
		delete object;
		object = factory->initObject(index, this->window);
	}
	object->trafficStop(traffic.checkStop());
	if (coin != nullptr)
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
	laneBackground.move(0-laneBackground.getGlobalBounds().left, (index - 3) * Constants::GetInstance().LANE_WIDTH - laneBackground.getGlobalBounds().top);
	//laneBackground.setPosition(0, (index - 3) * Constants::GetInstance().LANE_WIDTH);
	//object->shiftObject();
	//coin->shiftObject();
	//factory->shiftBackground(index, laneBackground);
}

void CLANE::saveLane(ofstream& out) {
	out << index << " ";
	if (object != nullptr)
		out << object->getTextureFile() << " " << object->mX << " " << object->mY << " " << object->speedMult << " ";
	else
		out << "none ";
	if (coin != nullptr && coin->sprite.getColor() != sf::Color::Transparent)
		out << "Coin " << coin->mX << " " << coin->mY;
	else
		out << "none";
	out << endl;
}