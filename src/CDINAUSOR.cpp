#include "../include/CDINAUSOR.h"

void CDINAUSOR::move(float x, float y, sf::RenderWindow& window) {
	COBJECT::move(x , y, window);
}

void CDINAUSOR::drawObject(sf::RenderWindow& window) {
	COBJECT::drawObject(window);
}

CDINAUSOR::CDINAUSOR(float x, float y) : COBJECT(x, y) {
	//srand(time(NULL));
	textureFile = "Dinosaur.png";
	type = Constants::GetInstance ().ANIMAL;

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

void CDINAUSOR::tell () {
	bool canTell = PlaySound ("assets/sound/dino.wav", NULL, SND_SYNC);
	if (canTell) cout << "True";
}