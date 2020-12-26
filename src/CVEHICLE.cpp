#include "../include/CVEHICLE.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <SFML/Audio.hpp>

CVEHICLE::CVEHICLE(float x, float y) {
	mX = x; mY = initY = y;
	sprite.setPosition(sf::Vector2f(mX, mY));
}

void CVEHICLE::move(float x, float y, sf::RenderWindow &window, vector<CTRAFFIC> traffics) {
	//srand(time(NULL));
	for (int i = 0; i < traffics.size(); ++i) {
		if (traffics[i].checkStop());
	}
	//mX = clamp(mX + x * speedMult * 0.766 + y * speedMult * 0.643, 0, )
	//mY = fmod((mY + x * speedMult * 0.866 + y * speedMult * 0.5), window.getSize().y);
	//cout << mX << endl;
	if (sprite.getPosition().x > window.getSize().x || sprite.getPosition().y > window.getSize().y) {
		// cout << "Vehicle destroyed" << endl;
		isOutOfBound = true;
		return;
	}
	sprite.move(x * speedMult * 0.766 + y * speedMult * 0.643, 
		x * speedMult * 0.866 + y * speedMult * 0.5);
	//mX += x * speedMult;
	//mY += y * speedMult;
	//if (mX >= window.getSize().x) sprite.setPosition(0, initY);

	//cout << x * speedMult * sin(ALPHA) << " : " << y * speedMult * cos(ALPHA) << endl;
	
}

void CVEHICLE::drawVehicle(sf::RenderWindow &window) {
	//sprite.setPosition(sf::Vector2f(mX, mY));
	window.draw(sprite);
}
//  0: no collision
//  1: collides with other obstacles -> push back
// -1: collides with player -> gameover

int CVEHICLE::checkCollision(vector<CVEHICLE*>& vehicles) {
	for (int i = 0; i < vehicles.size(); ++i) {
		//sf::FloatRect otherRect = vehicles[i]->sprite.getGlobalBounds();
		if (vehicles[i] != nullptr && vehicles[i] != this && mY == vehicles[i]->mY && 
			mX + sprite.getGlobalBounds().width / 2  >= vehicles[i]->sprite.getGlobalBounds().left
			&& mX + sprite.getGlobalBounds().width / 2  <= vehicles[i]->sprite.getGlobalBounds().left
			+ vehicles[i]->sprite.getGlobalBounds().width) {
			
			// cout << "mX: " << mX << endl;
			// mX -= vehicles[i]->sprite.getGlobalBounds().width /2;
			return 1;
		}
	}
	/*
	for (int i = 0; i < animals.size(); ++i) {
		if (sprite.getGlobalBounds().intersects(animals[i]->sprite.getGlobalBounds())) {
			mX = vehicles[i]->sprite.getGlobalBounds().left - 20;
		}
	}
	*/
	return 0;
	//if (sprite.getGlobalBounds().intersects(player))
}

void CVEHICLE::update(float x, float y, sf::RenderWindow& window, vector<CVEHICLE*>& vehicles, vector<CTRAFFIC> traffics) {
	int oldX = mX, oldY = mY;
	move(x, y, window, traffics);
	//if (checkCollision(vehicles) == 1) {
	//	mX = fmod((oldX), window.getSize().x);
	//	mY = oldY;
	//}
	drawVehicle(window);
}

void CVEHICLE::crash () {
	cout << "Crash sound" << endl;
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile ("assets/sound/Car+Crash.wav")) {
		cout << "Cannot load vehicle sound" << endl;
	}
	sf::Sound sound;
	sound.setBuffer (buffer);
	sound.play ();
}