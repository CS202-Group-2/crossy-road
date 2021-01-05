#include "../include/CCAR.h"

void CCAR::move(float x, float y, sf::RenderWindow &window) {
	if (!isStopping) COBJECT::move(x, y, window);
	
}

void CCAR::drawObject(sf::RenderWindow &window) {
	COBJECT::drawObject(window);
}

CCAR::CCAR(float x, float y) : COBJECT(x, y) {
	//srand(time(NULL));
	//int choice = std::default_random_engine
	int choice = rand() % 4;
	switch (choice) {
	case 0:
		textureFile = "Car";
		break;
	case 1:
		textureFile = "Car2";
		break;
	case 2:
		textureFile = "Bus";
		break;
	case 3:
		textureFile = "Truck";
		break;
	}
	if (x > 100) textureFile += "_back.png";
	else textureFile += "_front.png";
	type = Constants::GetInstance ().VEHICLE;

	if (!texture.loadFromFile(textureFile)) {
		cout << "Cannot find texture file" << endl;
		return;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));

	//sprite.rotate(Constants::GetInstance().ALPHA/(3.14)*180 - 90);
	//speedMult = rand() % 2 + 1;
}

CCAR::CCAR(float x, float y, bool direction) : CCAR(x, y) {
	this->direction = direction;
}

void CCAR::trafficStop(bool state) {
	//cout << "state " << std::boolalpha << state << endl;
	isStopping = state;
}