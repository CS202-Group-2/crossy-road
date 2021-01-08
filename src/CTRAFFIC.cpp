#include "../include/CTRAFFIC.h"
#include "../include/Constants.h"

CTRAFFIC::CTRAFFIC(float startTime) {
	clock.restart();
	curTime = startTime;
}

void CTRAFFIC::updateTimeTrafficStop() {
	timeTrafficStop = (float) (rand() % 1000) / 1000 + 2;
	if (rand() % 1000 >= 750) timeTrafficStop = 0.8; //25%

	cout << timeTrafficStop << endl;
}

bool CTRAFFIC::checkStop() {
	//cout << clock.getElapsedTime().asSeconds() << endl;
	if (clock.getElapsedTime().asSeconds() >= Constants::GetInstance().TIME_BETWEEN_TRAFFIC
		&& clock.getElapsedTime().asSeconds() <= Constants::GetInstance().TIME_BETWEEN_TRAFFIC + timeTrafficStop) {
		color = -1;
		return true;
	}
	else if (clock.getElapsedTime().asSeconds() >= Constants::GetInstance().TIME_BETWEEN_TRAFFIC + timeTrafficStop) {
		clock.restart();
		updateTimeTrafficStop();
		return false;
	}
	else if (clock.getElapsedTime().asSeconds() < Constants::GetInstance().TIME_BETWEEN_TRAFFIC - 3) color = 1;
	else color = 0;
	return false;
}

sf::Sprite CTRAFFIC::getSprite() {
	return sprite;
}

void CTRAFFIC::drawTraffic(sf::RenderWindow *window) {
	switch (color) {
	case -1:
		/*if (!texture.loadFromFile("assets/graphics/Traffic_red.png")) {
			cout << "Failed to load traffic" << endl;
			return;
		}*/
		texture = &CASSET::GetInstance().textureMap["Traffic_red"];
		break;
	case 0:
		/*if (!texture.loadFromFile("assets/graphics/Traffic_yellow.png")) {
			cout << "Failed to load traffic" << endl;
			return;
		}*/
		texture = &CASSET::GetInstance().textureMap["Traffic_yellow"];
		break;
	case 1:
		/*if (!texture.loadFromFile("assets/graphics/Traffic_green.png")) {
			cout << "Failed to load traffic" << endl;
			return;
		}*/
		texture = &CASSET::GetInstance().textureMap["Traffic_green"];
		break;
	}
	//texture.setSmooth(true);
	sprite.setTexture(*texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	sprite.setPosition(window->getSize().x / 2.0f, sprite.getLocalBounds().height / 2.0f - 50);
	window->draw(sprite);
}