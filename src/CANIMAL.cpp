#include "../include/CANIMAL.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

CANIMAL::CANIMAL(float x, float y) {
	mX = x; mY = y;

}

void CANIMAL::move(float x, float y, sf::RenderWindow& window) {
	//srand(time(NULL));
	mX = fmod((mX + x * speedMult), window.getSize().x);
	mY = fmod((mY + y * speedMult), window.getSize().y);
	//cout << mX << endl;

}

void CANIMAL::drawAnimal(sf::RenderWindow& window) {
	sprite.setPosition(sf::Vector2f(mX, mY));
	window.draw(sprite);
}
//  0: no collision
//  1: collides with other obstacles -> push back
// -1: collides with player -> gameover

int CANIMAL::checkCollision(vector<CANIMAL*>& animals) {
	for (int i = 0; i < animals.size(); ++i) {
		//sf::FloatRect otherRect = vehicles[i]->sprite.getGlobalBounds();
		if (animals[i] != nullptr && animals[i] != this && mY == animals[i]->mY &&
			mX + sprite.getGlobalBounds().width / 2 >= animals[i]->sprite.getGlobalBounds().left
			&& mX + sprite.getGlobalBounds().width / 2 <= animals[i]->sprite.getGlobalBounds().left
			+ animals[i]->sprite.getGlobalBounds().width) {

			// cout << "mX: " << mX << endl;
			// mX -= vehicles[i]->sprite.getGlobalBounds().width /2;
			return 1;
		}
	}
	return 0;
	//if (sprite.getGlobalBounds().intersects(player))
}

void CANIMAL::update(float x, float y, sf::RenderWindow& window, vector<CANIMAL*>& animals) {
	int oldX = mX, oldY = mY;
	move(x, y, window);
	if (checkCollision(animals) == 1) {
		mX = fmod((oldX), window.getSize().x);
		mY = oldY;
	}
	drawAnimal(window);
}