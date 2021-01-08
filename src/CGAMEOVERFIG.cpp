#include "../include/CGAMEOVERFIG.h"

CGAMEOVERFIG::CGAMEOVERFIG(int index) {
	this->index = index;
	type = Constants::GetInstance().DIE_FIG;
	activated = false;
	textureFile = "die_";
	
	/*if (!this->boyTexture.loadFromFile(textureFile + "boy.png")) {
		cout << "Cannot load " << textureFile << " in GAMEOVERFIG\n";
		return;
	}
	if (!this->girlTexture.loadFromFile(textureFile + "girl.png")) {
		cout << "Cannot load " << textureFile << " in GAMEOVERFIG\n";
		return;
	}*/
	boyTexture = &CASSET::GetInstance().textureMap[textureFile + "boy.png"];
	girlTexture = &CASSET::GetInstance().textureMap[textureFile + "girl.png"];
	//texture->setSmooth(true);
}

void CGAMEOVERFIG::activateFig(int gender, float x, float y) {
	activated = true;
	if (gender == CPEOPLE::MALE)
		sprite.setTexture(*boyTexture);
	else
		sprite.setTexture(*girlTexture);
	sprite.setScale(CPEOPLE::DIE_SCALE, CPEOPLE::DIE_SCALE);
	sprite.setPosition(x, y);
	this->mX = x;
	this->mY = y;
	this->initY = y;
	this->speedMult = 0;
}

void CGAMEOVERFIG::trafficStop(bool state) {

}

bool CGAMEOVERFIG::isActivated() {
	return activated;
}

void CGAMEOVERFIG::hide() {
	activated = false;
	sprite.setColor(sf::Color::Transparent);
}