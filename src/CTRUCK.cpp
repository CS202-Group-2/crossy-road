#include "../include/CTRUCK.h"

void CTRUCK::move(float x, float y, sf::RenderWindow& window) {
	COBJECT::move(x , y , window);
}

void CTRUCK::drawObject(sf::RenderWindow& window) {
	COBJECT::drawObject(window);
}

CTRUCK::CTRUCK(float x, float y) : COBJECT(x, y) {
	//srand(time(NULL));
	textureFile = "Truck.png";
	type = Constants::GetInstance ().VEHICLE;

	if (!texture.loadFromFile(textureFile)) {
		cout << "Cannot find texture file" << endl;
		return;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);

	sprite.setScale(sf::Vector2f(-1.5f, -1.5f));
	sprite.rotate(-90);
	//speedMult = rand() % 2 + 1;
}

void CTRUCK::tell () {
	bool canTell = PlaySound("assets/sound/truck.wav", NULL, SND_SYNC);
	if (canTell) cout << "True";
}