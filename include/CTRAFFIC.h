#pragma once
#include "COBJECT.h"
#include <SFML/Graphics.hpp>

class CTRAFFIC {
private:
	sf::Clock clock;
	sf::Texture* texture;
	sf::Sprite sprite;
	float curTime = 0;
	float timeTrafficStop = Constants::GetInstance().MAX_TRAFFIC_STOP;
	int color = 0; // 1: green, 0: yellow, -1: red
public:
	CTRAFFIC(float startTime);
	bool checkStop();
	sf::Sprite getSprite();
	void drawTraffic(sf::RenderWindow *window);
	void updateTimeTrafficStop();
};