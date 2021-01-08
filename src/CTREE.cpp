#include "../include/CTREE.h"

CTREE::CTREE(float x, float y, int index) : COBJECT(x, y) {
	this->index = index;
	type = Constants::GetInstance().BLOCK;
	int choice = rand() % 6;
	textureFile = "assets/graphics/b_" + to_string(choice) + ".png";
	if (!texture.loadFromFile(textureFile)) {
		cout << "Cannot find texture file" << endl;
		return;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height);

	sprite.setScale(sf::Vector2f(0.7f, 0.7f));

}

void CTREE::tell() {}
void CTREE::trafficStop(bool state) {}