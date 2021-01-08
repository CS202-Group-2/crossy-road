#include "../include/CANIMAL.h"

void CANIMAL::move(float x, float y) {
	COBJECT::move(x, y);
}

// THIS IS FOR LOADING SAVED GAME.
CANIMAL::CANIMAL(string textureFile, float x, float y, float speed) {
	type = Constants::GetInstance().ANIMAL;

	// Last character is '0' - backwards, or '1' - forwards.
	direction = textureFile[textureFile.size() - 1] - '0';

	mX = x;
	mY = y;
	initY = y;
	speedMult = speed;
	this->textureFile = textureFile;
	/*this->soundFile = "assets/sound/";
	soundFile += textureFile[2];
	soundFile += ".wav";*/
	soundFilename = textureFile[2];
	setupSound();

	if (!texture.loadFromFile("assets/graphics/" + textureFile + ".png")) {
		cout << "Cannot find animal texture." << endl;
		return;
	}

	setupTexture();
}

CANIMAL::CANIMAL(int index, int windowX, int level) : COBJECT(level) {
	direction = (rand() % 100) < 50;
	type = Constants::GetInstance().ANIMAL;
	int choice = rand() % Constants::GetInstance().NUMBER_OF_ANIMALS;

	this->soundFilename = to_string(choice);
	setupSound();

	textureFile = "a_" + to_string(choice) + "_" + to_string(direction);
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
		cout << "Cannot find animal texture." << endl;
		return;
	}
	setupTexture();
}


void CANIMAL::trafficStop(bool state) {
	// Animals don't stop.
}
