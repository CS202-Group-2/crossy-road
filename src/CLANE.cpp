#include "../include/CLANE.h"

CLANE::CLANE(int index, COBJECTFACTORY* factory, sf::RenderWindow * window, bool isGrass) {
	this->index = index;
	this->isGrass = isGrass;
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

	factory->initBackground(index, textureLane, isGrass);
	setupLaneBackground();
}

void CLANE::setupLaneBackground() {
	textureLane.setSmooth(true);
	laneBackground.setTexture(textureLane);
	double scaleX = (window->getSize().x * 2 + 100) / laneBackground.getGlobalBounds().width;
	laneBackground.setScale(scaleX, scaleX);
	laneBackground.setPosition(0, (index - 3) * Constants::GetInstance().LANE_WIDTH);
}

CLANE::~CLANE() {
	delete object;
	delete factory;
	delete coin;
	for (int i = 0; i < blocks.size(); ++i) if(blocks[i] != nullptr) delete blocks[i];
}

void CLANE::initObject() {
	factory->initBackground(index, textureLane, isGrass);
	CCOINFACTORY* coinFactory = new CCOINFACTORY();
	CTREEFACTORY* treeFactory = new CTREEFACTORY();
	COBJECT* tree = nullptr;
	if (isGrass) {
		//cout << "Acas" << endl;
		
		float x = rand() % (window->getSize().x - 25) + 25;
		for (int i = 0; i < Constants::GetInstance().MAX_TREE_PER_LANE; ++i) {
			tree = treeFactory->initObject(index, window);
			blocks.push_back(tree);
		}
		
	}
	// delete tree;
	delete treeFactory;
	

	
	//CTREEFACTORY* treeFactory = new CTREEFACTORY();
	coin = coinFactory->initObject(index, window);

	object = factory->initObject(index, window);
	int initialMove = rand() % 500;
	if (object != nullptr) object->move(initialMove, initialMove);
	
	delete coinFactory;
	setupLaneBackground();
}

bool CLANE::updatePosObject(float x, float y, sf::RenderWindow &window, CPEOPLE &player, CTRAFFIC &traffic) {
	window.draw(laneBackground);
	shiftBackground();

	if (object == nullptr) return true;
	if (object->checkOutWindow(window)) {

		delete object;
		object = factory->initObject(index, this->window);
	}
	object->trafficStop(traffic.checkStop());
	if (coin != nullptr)
		coin->update(x, y, window, player, index);
	for (int i = 0; i < blocks.size(); ++i)
		if (blocks[i] != nullptr) blocks[i]->update(x, y, window, player, index);
	if (!object->update(x, y, window, player, index)) return false;
	return true;
}

void CLANE::shiftLane() {
	index++;
	//this->shiftBackground();
	if (object != nullptr) object->shiftObject();
	if (coin != nullptr) coin->shiftObject();
	for (int i = 0; i < blocks.size(); ++i) blocks[i]->shiftObject();
}

bool CLANE::checkBlock(float x, float y) {
	//for (int i = 0; i < blocks.size(); ++i) if (blocks[i]->checkBlock(x, y)) return true;
	return false;
}

void CLANE::shiftBackground() {
	//laneBackground.setPosition(CTRANSITION::offset().getLaneX() + (index - 3) * Constants::GetInstance().LANE_WIDTH * cos(Constants::GetInstance().BETA),
	//						   CTRANSITION::offset().getLaneY() + (index - 3) * Constants::GetInstance().LANE_WIDTH * sin(Constants::GetInstance().BETA));
	float offsetX = Constants::GetInstance().LANE_WIDTH / (tan(Constants::GetInstance().ALPHA) + tan(Constants::GetInstance().BETA));
	float offsetY = offsetX * tan(Constants::GetInstance().ALPHA);
	laneBackground.setPosition(CTRANSITION::offset().getLaneX() - (index - 3) * offsetX,
							   CTRANSITION::offset().getLaneY() + (index - 3) * (- offsetY + Constants::GetInstance().LANE_WIDTH));
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
