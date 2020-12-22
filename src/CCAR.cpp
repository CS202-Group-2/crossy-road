#include "../include/CVEHICLE.h"
#include "../include/CCAR.h"

void CCAR::move(float x, float y, sf::RenderWindow &window, vector<CTRAFFIC> traffics) {
	CVEHICLE::move(x*speedMult, y*speedMult, window, traffics);
}

void CCAR::drawVehicle(sf::RenderWindow &window) {
	CVEHICLE::drawVehicle(window);
}

CCAR::CCAR(float x, float y) : CVEHICLE(x, y) {
	//srand(time(NULL));
	textureFile = "Car.png";
	if (!texture.loadFromFile(textureFile)) {
		cout << "Cannot find texture file" << endl;
		return;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);
	
	sprite.setScale(sf::Vector2f(0.2f, 0.2f));
	sprite.rotate(-90);
	//speedMult = rand() % 2 + 1;
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