#include "../include/COBJECT.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

COBJECT::COBJECT(float x, float y) {
	this->mX = x; 
	this->mY = y;

}

void COBJECT::move(float x, float y, sf::RenderWindow& window) {
	//srand(time(NULL));
	mX = mX + x * speedMult * cos (Constants::GetInstance ().ALPHA);
	mY = mY + y * speedMult * sin (Constants::GetInstance ().ALPHA);
	//cout << mX << endl;

}

void COBJECT::drawObject(sf::RenderWindow& window) {
	sprite.setPosition(sf::Vector2f(mX, mY));
	if (checkOutWindow (window) == 0) window.draw (sprite);
	else  cout << "out window" << endl;
}
//  0: no collision
//  1: collides with other obstacles -> push back
// -1: collides with player -> gameover
//  2: check traffic

int COBJECT::checkCollision(vector<COBJECT*>& objects, CPEOPLE& player, vector<CTRAFFIC> traffics) {
	for (int i = 0; i < objects.size(); ++i) {
		//sf::FloatRect otherRect = vehicles[i]->sprite.getGlobalBounds();
		if (objects[i] != nullptr && objects[i] != this && mY == objects[i]->mY && objects[i]->type == this->type) {
			if (sprite.getGlobalBounds ().intersects (objects[i]->sprite.getGlobalBounds ())) {
				return 1;
			}
		}
	}
	for (int i = 0; i < traffics.size (); ++i) {
		if (sprite.getGlobalBounds ().intersects (traffics[i].getSprite().getGlobalBounds()) && traffics[i].checkStop() && 
			mX + sprite.getGlobalBounds().width / 2 <= traffics[i].getSprite().getGlobalBounds().left && mY > traffics[i].getSprite().getGlobalBounds().top + traffics[i].getSprite ().getGlobalBounds ().height / 2) {
			return 2;
		}
	}
	//collide with people
	if (sprite.getGlobalBounds().intersects (player.mSprite.getGlobalBounds())) {
		return -1;
	}
	return 0;
}

void COBJECT::update (float x, float y, sf::RenderWindow& window, vector<COBJECT*>& objects, CPEOPLE& player, vector<CTRAFFIC> traffics) {
	int oldX = mX, oldY = mY;
	move (x, y, window);
	if (checkCollision (objects, player, traffics) == 1) {
		mX = fmod ((oldX), window.getSize ().x);
		mY = oldY;
	}
	else if (checkCollision (objects, player, traffics) == -1) {
		//game over
	}
	else if (checkCollision (objects, player, traffics) == 2) {
		//stop the nearest vehicle 
		move (0, 0, window);
	}
	drawObject(window);
}

bool COBJECT::checkOutWindow (sf::RenderWindow& window) {
	//cout << window.getSize ().x << " " << window.getSize ().y << endl;
	//cout << mX << endl;
	if (sprite.getPosition().x >= window.getSize().x || sprite.getPosition().y >= window.getSize ().y) return 1;
	return 0;
}