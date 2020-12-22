#include "../include/CVEHICLE.h"
#include "../include/CTRUCK.h"

void CTRUCK::move(float x, float y, sf::RenderWindow& window, vector<CTRAFFIC> traffics) {
	CVEHICLE::move(x * speedMult, y * speedMult, window, traffics);
}

void CTRUCK::drawVehicle(sf::RenderWindow& window) {
	CVEHICLE::drawVehicle(window);
}

CTRUCK::CTRUCK(float x, float y) : CVEHICLE(x, y) {
	//srand(time(NULL));
	textureFile = "Truck.png";
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