#include "../include/CASSET.h"

CASSET::CASSET() {


	initSoundBuffer("0");
	initSoundBuffer("1");
	initSoundBuffer("2");
	initSoundBuffer("3");
	initSoundBuffer("bird");
	initSoundBuffer("bush");
	initSoundBuffer("c");
	initSoundBuffer("car");
	initSoundBuffer("car-alarm");
	initSoundBuffer("coin");
	initSoundBuffer("dino");
	initSoundBuffer("gameover");
	initSoundBuffer("jump");
	initSoundBuffer("ohnogameover");
	initSoundBuffer("powerup");
	initSoundBuffer("scream");
	initSoundBuffer("truck");
}

void CASSET::initSoundBuffer(string soundFilename) {
	if (!soundBufferMap[soundFilename].loadFromFile("assets/sound/" + soundFilename + ".wav")) {
		cout << "Cannot load assets/sound/" << soundFilename << ".wav\n";
		return;
	}
	cout << "assets/sound/" << soundFilename << ".wav loaded successfully\n";
}

void CASSET::initTexture(string textureFilename) {
	if (!textureMap[textureFilename].loadFromFile("assets/graphics/" + textureFilename + ".png")) {
		cout << "Cannot load assets/graphics/" + textureFilename + ".png" << endl;
		return;
	}
	cout << "assets/graphics/" + textureFilename + ".png loaded successfully\n";
}