#include "../include/COBJECT.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

COBJECT::COBJECT() {}

COBJECT::COBJECT(float x, float y) {
	this->mX = x;
	this->mY = y;
	initY = y;
	speedMult = rand() % 2 + 1;

}

COBJECT::COBJECT(float x, float y, int index) : COBJECT(x, y) {
	this->index = index;
}

void COBJECT::move(float x, float y, sf::RenderWindow& window) {
	//srand(time(NULL));
	if (direction) {
		mX = mX + x * speedMult * cos(Constants::GetInstance().ALPHA);
		mY = mY + y * speedMult * sin(Constants::GetInstance().ALPHA);
	}
	else {
		mX = mX - x * speedMult * cos(Constants::GetInstance().ALPHA);
		mY = mY - y * speedMult * sin(Constants::GetInstance().ALPHA);
	}

	//cout << mX << endl;

}

void COBJECT::drawObject(sf::RenderWindow& window) {
	sprite.setPosition(sf::Vector2f(mX, mY));
	if (checkOutWindow (window) == 0) window.draw (sprite);
}
//  0: no collision
//  1: collides with other obstacles -> push back
// -1: collides with player -> gameover
//  2: check traffic

/*
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
*/

bool COBJECT::checkCollision(CPEOPLE& player, int index) {
	if (player.index != index) {
		return false;
	}
	return player.mSprite.getGlobalBounds().intersects(this->sprite.getGlobalBounds());
	//int padding = type == Constants::GetInstance().INTERACTABLE ? 0 : 25;
	////else cout << "Same line" << endl;
	//return (player.mSprite.getPosition().x >= sprite.getGlobalBounds().left 
	//	&& player.mSprite.getPosition().x + padding <= sprite.getGlobalBounds().left
	//	+ sprite.getGlobalBounds().width - padding);
}

bool COBJECT::update(float x, float y, sf::RenderWindow& window, CPEOPLE& player, int index) {
	int oldX = mX, oldY = mY;
	if (type != Constants::GetInstance().INTERACTABLE) move(x, y, window);
	if (checkCollision(player, index)) {
		// TODO: implement onCollision
		if (type == Constants::GetInstance().VEHICLE || type == Constants::GetInstance().ANIMAL)
			return false;
		else if (type == Constants::GetInstance().INTERACTABLE && interacted == false) {
			player.addScore(100);
			sprite.setColor(sf::Color::Transparent);
			interacted = true;
			//cout << "Earned aksjddhkajsfhkshdflkshdklfhskdlfh" << endl;
		}
	}
	drawObject(window);
	return true;
}

void COBJECT::shiftObject() {
	mX = mX - Constants::GetInstance().LANE_WIDTH * cos(Constants::GetInstance().BETA);
	mY = mY + Constants::GetInstance().LANE_WIDTH * sin(Constants::GetInstance().BETA) - 1;
}

bool COBJECT::checkOutWindow (sf::RenderWindow& window) {
	//cout << window.getSize ().x << " " << window.getSize ().y << endl;
	//cout << mX << endl;

	if (direction && (sprite.getPosition().x >= window.getSize().x + 200 || sprite.getPosition().y >= window.getSize().y + 200)) return 1;
	else if (!direction && (sprite.getPosition().x <= -200 || sprite.getPosition().y <= -200)) return 1;
	return 0;
}

string COBJECT::getTextureFile() {
	return textureFile;
}

void COBJECT::setupTexture() {
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
}
