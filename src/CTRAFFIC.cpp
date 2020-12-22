#include "../include/CTRAFFIC.h"
#include "../include/Constants.h"

CTRAFFIC::CTRAFFIC(float startTime) {
	clock.restart();
	curTime = startTime;
}

bool CTRAFFIC::checkStop() {
	if (clock.getElapsedTime().asSeconds() >= Constants::GetInstance().TIME_BETWEEN_TRAFFIC
		&& clock.getElapsedTime().asSeconds() <= Constants::GetInstance().TIME_BETWEEN_TRAFFIC
		+ Constants::GetInstance().MAX_TRAFFIC_STOP) {
		return true;
	}
	else if (clock.getElapsedTime().asSeconds() >= Constants::GetInstance().MAX_TRAFFIC_STOP) {
		clock.restart();
		return false;
	}
	return false;
}

sf::Sprite CTRAFFIC::getSprite() {
	return sprite;
}

void CTRAFFIC::drawTraffic() {
	if (!texture.loadFromFile("Traffic.png")) {
		cout << "Failed to load traffic" << endl;
		return;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().left + sprite.getLocalBounds().width / 2.0f,
		sprite.getLocalBounds().top + sprite.getLocalBounds().height / 2.0f);
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
}