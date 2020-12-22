#include "../include/CDINAUSOR.h"
#include "../include/CANIMAL.h"

void CDINAUSOR::move(float x, float y, sf::RenderWindow& window) {
	CANIMAL::move(x * speedMult, y * speedMult, window);
}

void CDINAUSOR::drawAnimal(sf::RenderWindow& window) {
	CANIMAL::drawAnimal(window);
}

CDINAUSOR::CDINAUSOR(float x, float y) : CANIMAL(x, y) {
	//srand(time(NULL));
	textureFile = "Dinosaur.png";
	if (!texture.loadFromFile(textureFile)) {
		cout << "Cannot find texture file" << endl;
		return;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);
	sprite.setScale(sf::Vector2f(-0.2f, 0.2f));
	//sprite.setScale(sf::Vector2f(-1.0f, 1.0f));
	//sprite.rotate(-90);
	//speedMult = rand() % 2 + 1;
}