#include "../include/CBIRD.h"

void CBIRD::move(float x, float y, sf::RenderWindow& window) {
	COBJECT::move(x , y , window);
}

void CBIRD::drawObject(sf::RenderWindow& window) {
	COBJECT::drawObject(window);
	//tell ();
}

CBIRD::CBIRD(float x, float y) : COBJECT(x, y) {
	//srand(time(NULL));
	textureFile = "Bird.png";
	type = Constants::GetInstance ().ANIMAL;
	if (!texture.loadFromFile(textureFile)) {
		cout << "Cannot find texture file" << endl;
		return;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	//sprite.setScale(sf::Vector2f(-1.0f, 1.0f));
	//sprite.rotate(-90);
	//speedMult = rand() % 2 + 1;
}

void CBIRD::tell () {
	cout << "Bird sound" << endl;
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile ("assets/sound/bird.wav")) {
		cout << "Cannot load bird" << endl;
	}
	sf::Sound sound;
	sound.setBuffer (buffer);
	sound.play ();
}