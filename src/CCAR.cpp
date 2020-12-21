#include "../include/CVEHICLE.h"
#include "../include/CCAR.h"

CCAR::CCAR (int x, int y) {
	this->mX = x;
	this->mY = y;
}

void CCAR::move(int x, int y) {
	CVEHICLE::move(x, y);
}

void CCAR::tell () {
	cout << "Car sound" << endl;
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile ("assets/sound/car+driveby2.wav")) {
		cout << "Cannot load car sound" << endl;
	}
	sf::Sound sound;
	sound.setBuffer (buffer);
	sound.play ();
}

void CCAR::crash () {
	CVEHICLE::crash ();
}