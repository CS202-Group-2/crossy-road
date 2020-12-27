#include "../include/COBJECT.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

COBJECT::COBJECT(float x, float y) {
	mX = x; mY = y;

}

void COBJECT::move(float x, float y, sf::RenderWindow& window) {
	//srand(time(NULL));
	mX = fmod((mX + x * speedMult), window.getSize().x);
	mY = fmod((mY + y * speedMult), window.getSize().y);
	//cout << mX << endl;

}

void COBJECT::drawObject(sf::RenderWindow& window) {
	sprite.setPosition(sf::Vector2f(mX, mY));
	window.draw(sprite);
}
//  0: no collision
//  1: collides with other obstacles -> push back
// -1: collides with player -> gameover

int COBJECT::checkCollision(vector<COBJECT*>& objects) {
	for (int i = 0; i < objects.size(); ++i) {
		//sf::FloatRect otherRect = vehicles[i]->sprite.getGlobalBounds();
		if (objects[i] != nullptr && objects[i] != this && mY == objects[i]->mY && objects[i]->type == this->type && 
			mX + sprite.getGlobalBounds().width / 2 >= objects[i]->sprite.getGlobalBounds().left
			&& mX + sprite.getGlobalBounds().width / 2 <= objects[i]->sprite.getGlobalBounds().left
			+ objects[i]->sprite.getGlobalBounds().width) {

			// cout << "mX: " << mX << endl;
			// mX -= vehicles[i]->sprite.getGlobalBounds().width /2;
			return 1;
		}
	}
	return 0;
	//if (sprite.getGlobalBounds().intersects(player))
}

void COBJECT::update(float x, float y, sf::RenderWindow& window, vector<COBJECT*>& objects) {
	int oldX = mX, oldY = mY;
	move(x, y, window);
	if (checkCollision(objects) == 1) {
		mX = fmod((oldX), window.getSize().x);
		mY = oldY;
	}
	drawObject(window);
}