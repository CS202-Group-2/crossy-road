#include "../include/CCAR.h"

void CCAR::move(float x, float y, sf::RenderWindow &window) {
	if (!isStopping) COBJECT::move(x, y, window);

}

CCAR::CCAR(string textureFile, float x, float y, float speed) {
	type = Constants::GetInstance().VEHICLE;

	// Last character is '0' - backwards, or '1' - forwards.
	direction = textureFile[textureFile.size() - 1] - '0';

	mX = x;
	mY = y;
	initY = y;
	speedMult = speed;
	this->textureFile = textureFile;

	if (!texture.loadFromFile(textureFile + ".png")) {
		cout << "Cannot find car texture." << endl;
		return;
	}

	setupTexture();
}

CCAR::CCAR(int index, int windowX) {
	direction = rand() % 2;
	type = Constants::GetInstance().VEHICLE;
	int choice = rand() % Constants::GetInstance().NUMBER_OF_CARS;
	textureFile = "assets/graphics/c_" + to_string(choice) + "_" + to_string(direction);
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
		cout << "Cannot find car texture." << endl;
		return;
	}
	setupTexture();
}

//CCAR::CCAR(float x, float y) : COBJECT(x, y) {
//	//srand(time(NULL));
//	//int choice = std::default_random_engine
//	int choice = rand() % 4;
//	textureFile = "car" + to_string(choice);
//	switch (choice) {
//	case 0:
//		textureFile = "Car";
//		break;
//	case 1:
//		textureFile = "Car2";
//		break;
//	case 2:
//		textureFile = "Bus";
//		break;
//	case 3:
//		textureFile = "Truck";
//		break;
//	}
//	if (x > 100) textureFile += "_back.png";
//	else textureFile += "_front.png";
//	type = Constants::GetInstance ().VEHICLE;
//
//	if (!texture.loadFromFile(textureFile)) {
//		cout << "Cannot find texture file" << endl;
//		return;
//	}
//	sprite.setTexture(texture);
//	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
//		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);
//	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
//
//	//sprite.rotate(Constants::GetInstance().ALPHA/(3.14)*180 - 90);
//	//speedMult = rand() % 2 + 1;
//}
//
//CCAR::CCAR(float x, float y, bool direction) : CCAR(x, y) {
//	this->direction = direction;
//}

void CCAR::trafficStop(bool state) {
	//cout << "state " << std::boolalpha << state << endl;
	isStopping = state;
}
