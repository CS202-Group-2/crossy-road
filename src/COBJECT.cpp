#include "../include/COBJECT.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

COBJECT::COBJECT() {
	initSpeedMult();
}

COBJECT::COBJECT(float x, float y) {
	this->mX = x;
	this->mY = y;
	initY = y;
	initSpeedMult();
}

void COBJECT::initSpeedMult() {
	speedMult = (float) (rand() % 200) / 100 + 2;

	bool xFactor = (rand() % 100 < 20);
	if (xFactor) speedMult = 30;
	cout << speedMult << endl;
}

COBJECT::COBJECT(float x, float y, int index) : COBJECT(x, y) {
	this->index = index;
	initSpeedMult();
}

void COBJECT::move(float x, float y) {
	//srand(time(NULL));
	if (direction) {
		cout << speedMult << endl;
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
	sprite.setPosition(sf::Vector2f(mX + CTRANSITION::offset().getObjectX(), 
									mY + CTRANSITION::offset().getObjectY()));
	if (checkOutWindow (window) == 0) window.draw (sprite);
}


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

int COBJECT::update(float x, float y, sf::RenderWindow& window, CPEOPLE& player, int index) {
	int oldX = mX, oldY = mY;
	if (type != Constants::GetInstance().INTERACTABLE) move(x, y);
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
		else if (type == Constants::GetInstance().BLOCK) {
			return -1;
		}
	}
	drawObject(window);
	return 1;
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


bool COBJECT::checkBlock(float x, float y) {
	return (x >= sprite.getGlobalBounds().left && x <= sprite.getGlobalBounds().left
		+ sprite.getGlobalBounds().width);
}

string COBJECT::getTextureFile() {
	return textureFile;
}

void COBJECT::setupTexture() {
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
}
