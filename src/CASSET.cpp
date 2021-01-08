#include "../include/CASSET.h"

CASSET::CASSET() {
	initTexture("Bus_back");
	initTexture("Bus_front");
	initTexture("Bush");
	initTexture("Car2");
	initTexture("Car2_back");
	initTexture("Car2_front");
	initTexture("Car_back");
	initTexture("Car_front");
	initTexture("Chicken_back");
	initTexture("Chicken_front");
	initTexture("Coin");
	initTexture("CrossyRoadTitle");
	initTexture("Duck_back");
	initTexture("Duck_front");
	initTexture("Grass");
	initTexture("Pause");
	initTexture("Rail");
	initTexture("Road");
	initTexture("TitleGame");
	initTexture("Traffic");
	initTexture("Traffic_green");
	initTexture("Traffic_red");
	initTexture("Traffic_yellow");
	initTexture("Truck_back");
	initTexture("Truck_front");
	initTexture("a_0_0");
	initTexture("a_0_1");
	initTexture("a_1_0");
	initTexture("a_1_1");
	initTexture("a_2_0");
	initTexture("a_2_1");
	initTexture("a_3_0");
	initTexture("a_3_1");
	initTexture("a_4_1");
	initTexture("b_0");
	initTexture("b_1");
	initTexture("b_2");
	initTexture("b_3");
	initTexture("b_4");
	initTexture("b_5");
	initTexture("c_0_0");
	initTexture("c_0_1");
	initTexture("c_1_0");
	initTexture("c_1_1");
	initTexture("c_2_0");
	initTexture("c_2_1");
	initTexture("c_3_0");
	initTexture("c_3_1");
	initTexture("logo");
	initTexture("dietext");
	initTexture("highscore");
	initTexture("yourscore");
	initTexture("beaths");
	initTexture("try");
	initTexture("boy", true);
	initTexture("die_boy", true);
	initTexture("girl", true);
	initTexture("die_girl", true);

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

void CASSET::initTexture(string textureFilename, bool isPlayer) {
	string filepath = isPlayer
		? "assets/player/" + textureFilename + ".png"
		: "assets/graphics/" + textureFilename + ".png";
	if (!textureMap[textureFilename].loadFromFile(filepath)) {
		cout << "Cannot load " << filepath << endl;
		return;
	}
	textureMap[textureFilename].setSmooth(true);
	cout << filepath << " loaded successfully" << endl;
}