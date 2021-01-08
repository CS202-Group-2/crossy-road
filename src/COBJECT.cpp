#include "../include/COBJECT.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

COBJECT::COBJECT() {
	tilted = false;
}

COBJECT::COBJECT(int level) {
	initSpeedMult(level);
	tilted = false;
}

COBJECT::COBJECT(float x, float y) {
	this->mX = x;
	this->mY = y;
	initY = y;
	initSpeedMult();
	tilted = false;
}

float logXFactor(int level) {
	return log(1 + (float) level / 3) / log(1.25);
}

void COBJECT::initSpeedMult(int level) {
	/*int m = max((int)(10 * log((float)level / 2) / log(2)), 2) * 100;

	speedMult = max((float)(rand() % m) / 100, (float)2);*/


	speedMult = (float) (rand() % 350) / 100 + 2;

	bool xFactor = ((rand() % 1000) < 10 * logXFactor(level));
	if (xFactor) speedMult = 20;
	//cout << speedMult << endl;

	speedMult /= Constants::GetInstance().FPS / 30;
}

COBJECT::COBJECT(float x, float y, int index) : COBJECT(x, y) {
	this->index = index;
	initSpeedMult();
}

void COBJECT::move(float x, float y) {
	//srand(time(NULL));
	if (direction) {
		//cout << speedMult << endl;
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


bool COBJECT::checkCollision(CPEOPLE& player, int index, COLLISION_TYPE* collision) {
	if (player.index != index) {
		return false;
	}
	bool res = player.mSprite.getGlobalBounds().intersects(this->sprite.getGlobalBounds());
	if (res && collision != 0) {
		sf::FloatRect playerRect = player.mSprite.getGlobalBounds();
		sf::FloatRect objectRect = sprite.getGlobalBounds();
		if (playerRect.top <= objectRect.top
			&& playerRect.top + playerRect.height > objectRect.top
			&& playerRect.left >= objectRect.left
			&& playerRect.left + playerRect.width <= objectRect.left + objectRect.width)
			*collision = COLLISION_TYPE::FROM_TOP;
		else if (playerRect.top <= sprite.getGlobalBounds().top + sprite.getGlobalBounds().height
			&& playerRect.top + playerRect.height > sprite.getGlobalBounds().top + sprite.getGlobalBounds().height)
			*collision = COLLISION_TYPE::FROM_BOTTOM;
		else
			*collision = COLLISION_TYPE::FROM_SIDE;
	}
	return res;
}

// Detect if player is standing close on the moving way of object.
bool COBJECT::checkCloseInteraction(CPEOPLE& player, int index) {
	if (player.index != index)
		return false;
	float offX = mX, offY = mY;
	if (this->direction) {
		offX += CLOSE_DIST * cos(Constants::GetInstance().ALPHA);
		offY += CLOSE_DIST * sin(Constants::GetInstance().ALPHA);
	}
	else {
		offX -= CLOSE_DIST * cos(Constants::GetInstance().ALPHA);
		offY -= CLOSE_DIST * sin(Constants::GetInstance().ALPHA);
	}
	sf::FloatRect futureMovement(offX, offY, 
		sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
	return futureMovement.intersects(player.mSprite.getGlobalBounds());
}

int COBJECT::update(float x, float y, sf::RenderWindow& window, CPEOPLE& player,
	int index, int rand, CSOUNDFACTORY* soundFactory, COLLISION_TYPE* collision) {
	int oldX = mX, oldY = mY;
	if (type != Constants::GetInstance().INTERACTABLE && type != Constants::GetInstance().BLOCK)
		move(x, y);

	// Random coin movement
	if (type == Constants::GetInstance().INTERACTABLE && rand % 30 == 0) {
		if (tilted) {
			move(0, 30);
			tilted = false;
		}
		else {
			move(0, -30);
			tilted = true;
		}
	}
	if (type == Constants::GetInstance().VEHICLE
		&& !playWarningSound && checkCloseInteraction(player, index)) {
		playWarningSound = true;
		sf::Sound sound;
		sound.setBuffer(CASSET::GetInstance().soundBufferMap["car-alarm"]);
		sound.play();
	}

	if (checkCollision(player, index, collision)) {
		//cout << "Hit by " << type << endl;
		if (type != Constants::GetInstance().INTERACTABLE && !soundPlay) {
			soundPlay = true;
			crashSound();
		}
		if (type == Constants::GetInstance().VEHICLE || type == Constants::GetInstance().ANIMAL) {
			drawObject(window);
			return 0;
		}
		else if (type == Constants::GetInstance().INTERACTABLE && interacted == false) {
			player.addScore(100);
			sprite.setColor(sf::Color::Transparent);
			interacted = true;
			soundFactory->playSound(3);
			//cout << "Earned aksjddhkajsfhkshdflkshdklfhskdlfh" << endl;
		}
		else if (type == Constants::GetInstance().BLOCK) {

		}
	}
	else
		soundPlay = false;
	drawObject(window);
	return 1;
}

void COBJECT::shiftObject() {
	mX = mX - Constants::GetInstance().LANE_WIDTH * cos(Constants::GetInstance().BETA);
	mY = mY + Constants::GetInstance().LANE_WIDTH * sin(Constants::GetInstance().BETA) - 2;
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

void COBJECT::setupTexture() {;
	//texture->setSmooth(true);
	sprite.setTexture(*texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
}

void COBJECT::setupSound() {
	/*if (!buffer.loadFromFile(soundFile)) {
		cout << "Cannot load " << soundFile << " from object\n";
		return;
	}*/
	buffer = &CASSET::GetInstance().soundBufferMap[soundFilename];
	objSound.setBuffer(*buffer);
	objSound.setVolume(100);
	objSound.setLoop(false);
}

void COBJECT::crashSound() {
	objSound.play();
}
