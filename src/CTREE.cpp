#include "../include/CTREE.h"

CTREE::CTREE(float x, float y, int index, int bushType) : COBJECT(x, y) {
	this->index = index;
	type = Constants::GetInstance().BLOCK;
	soundFilename = "bush";
	setupSound();

	//textureFile = "Bush.png";
	int choice;
	if (bushType == -1) {
		choice = rand() % 6;
	}
	else {
		choice = bushType;
	}
	textureFile = "b_" + to_string(choice);
	/*if (!texture.loadFromFile(textureFile)) {
		cout << "Cannot find texture file" << endl;
		return;
	}*/
	texture = &CASSET::GetInstance().textureMap[textureFile];
	//texture->setSmooth(true);
	sprite.setTexture(*texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height);

	sprite.setScale(sf::Vector2f(0.7f, 0.7f));

}

void CTREE::trafficStop(bool state) {}
