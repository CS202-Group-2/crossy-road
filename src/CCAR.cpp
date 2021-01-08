#include "../include/CCAR.h"

void CCAR::move(float x, float y) {
	if (!isStopping) COBJECT::move(x, y);

}

// THIS IS FOR LOADING SAVED GAME.
CCAR::CCAR(string textureFile, float x, float y, float speed) {
	type = Constants::GetInstance().VEHICLE;
	soundFilename = "car";
	cout << soundFilename << endl;
	setupSound();

	// Last character is '0' - backwards, or '1' - forwards.
	direction = textureFile[textureFile.size() - 1] - '0';

	mX = x;
	mY = y;
	initY = y;
	speedMult = speed;
	this->textureFile = textureFile;

	if (!texture.loadFromFile("assets/graphics/" + textureFile + ".png")) {
		cout << "Cannot find car texture." << endl;
		return;
	}

	setupTexture();
}

CCAR::CCAR(int index, int windowX, int level) : COBJECT(level) {
	direction = (rand() % 100) < 50;
	type = Constants::GetInstance().VEHICLE;
	soundFilename = "car";
	setupSound();
	int choice = rand() % Constants::GetInstance().NUMBER_OF_CARS;
	textureFile = "c_" + to_string(choice) + "_" + to_string(direction);
	if (direction) {
		mX = -100;
		mY = (index - 3) * Constants::GetInstance().LANE_WIDTH;
	}
	else {
		mX = windowX + 100;
		mY = windowX * tan(Constants::GetInstance().ALPHA) + (index - 2) * Constants::GetInstance().LANE_WIDTH - 25;
	}
	initY = mY;
	if (!texture.loadFromFile("assets/graphics/" + textureFile + ".png")) {
		cout << "Cannot find car texture." << endl;
		return;
	}
	setupTexture();
}

void CCAR::trafficStop(bool state) {
	//cout << "state " << std::boolalpha << state << endl;
	isStopping = state;
}