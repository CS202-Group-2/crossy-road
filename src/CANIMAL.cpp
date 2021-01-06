#include "../include/CANIMAL.h"

void CANIMAL::move(float x, float y, sf::RenderWindow& window) {
	COBJECT::move(x, y, window);
}

CANIMAL::CANIMAL(int index, int windowX) {
	direction = rand() % 2;
	type = Constants::GetInstance().ANIMAL;
	int choice = rand() % Constants::GetInstance().NUMBER_OF_ANIMALS;
	textureFile = "assets/graphics/a_" + to_string(choice) + "_" + to_string(direction);
	if (direction) {
		mX = -100;
		mY = (index - 3) * Constants::GetInstance().LANE_WIDTH;
	}
	else {
		mX = windowX + 100;
		mY = windowX * tan(Constants::GetInstance().ALPHA) + (index - 2) * Constants::GetInstance().LANE_WIDTH - 25;
	}
	initY = mY;
	speedMult = rand() % 2 + 1;
	if (!texture.loadFromFile(textureFile + ".png")) {
		cout << "Cannot find animal texture." << endl;
		return;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
}

CANIMAL::CANIMAL(float x, float y) : COBJECT(x, y) {
	//srand(time(NULL));
	int choice = rand() % 4;
	textureFile = "car" + to_string(choice);
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
	type = Constants::GetInstance().VEHICLE;

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

CANIMAL::CANIMAL(float x, float y, bool direction) : CANIMAL(x, y) {
	this->direction = direction;
}

void CANIMAL::trafficStop(bool state) {
	// Animals don't stop.
}

