#include "../include/CCAR.h"

void CCAR::move(float x, float y, sf::RenderWindow &window) {
	COBJECT::move(x, y, window);
	
}

void CCAR::drawObject(sf::RenderWindow &window) {
	COBJECT::drawObject(window);
}

CCAR::CCAR(float x, float y) : COBJECT(x, y) {
	//srand(time(NULL));
	textureFile = "Car.png";
	type = Constants::GetInstance ().VEHICLE;

	if (!texture.loadFromFile(textureFile)) {
		cout << "Cannot find texture file" << endl;
		return;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);
	
	sprite.setScale(sf::Vector2f(0.2f, 0.2f));
	sprite.rotate(Constants::GetInstance().ALPHA/(3.14)*180 - 90);
	//speedMult = rand() % 2 + 1;
}

void CCAR::tell () {
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile ("assets/sound/car.wav")) {
		cout << "Cannot load bird" << endl;
	}
	sf::Sound sound;
	sound.setBuffer (buffer);
	sound.play ();
	cout << "sound car" << endl;
}