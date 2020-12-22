#pragma once
#include <SFML/Graphics.hpp>

class CTRAFFIC {
private:
	sf::Clock clock;
	sf::Texture texture;
	sf::Sprite sprite;
	float curTime = 0;
public:
	CTRAFFIC(float startTime);
	bool checkStop();
	sf::Sprite getSprite();
	void drawTraffic();
};