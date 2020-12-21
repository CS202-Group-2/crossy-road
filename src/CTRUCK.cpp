#include "../include/CTRUCK.h"

void CTRUCK::move(int x, int y) {
	CVEHICLE::move(x,y);
}

CTRUCK::CTRUCK(int x, int y) {
	this->mX = x;
	this->mY = y;
}

void CTRUCK::tell () {
	cout << "Truck sound" << endl;
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile ("assets/sound/truck-sound.wav")) {
		cout << "Cannot load truck" << endl;
	}
	sf::Sound sound;
	sound.setBuffer (buffer);
	sound.play ();
}

void CTRUCK::crash () {
	CVEHICLE::crash ();
}