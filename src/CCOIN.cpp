#include "../include/CCOIN.h"

CCOIN::CCOIN(float x, float y, int index) : COBJECT(x, y) {
	this->index = index;
	type = Constants::GetInstance().INTERACTABLE;
	textureFile = "assets/graphics/Coin.png";
	if (!texture.loadFromFile(textureFile)) {
		cout << "Cannot find texture file" << endl;
		return;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);

	sprite.setScale(sf::Vector2f(0.3f, 0.3f));
	
}

void CCOIN::crashSound() {}
void CCOIN::trafficStop(bool state) {}