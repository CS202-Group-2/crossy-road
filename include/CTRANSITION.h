#pragma once
#include "Constants.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <wtypes.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class CTRANSITION
{
private:
	bool activated = true;
	float laneX, laneY, objectX, objectY;
	float maxLaneX, maxLaneY, maxObjectX, maxObjectY;
	
	const float base = 0.1;
	const float constLaneX = Constants::GetInstance().LANE_WIDTH / (tan(Constants::GetInstance().ALPHA) + tan(Constants::GetInstance().BETA));
	const float constLaneY = Constants::GetInstance().LANE_WIDTH / (tan(Constants::GetInstance().ALPHA) + tan(Constants::GetInstance().BETA)) * tan(Constants::GetInstance().ALPHA) 
						   - Constants::GetInstance().LANE_WIDTH;
	const float constObjectX = Constants::GetInstance().LANE_WIDTH* cos(Constants::GetInstance().BETA);
	const float constObjectY = 1 - Constants::GetInstance().LANE_WIDTH * sin(Constants::GetInstance().BETA);
	sf::Clock clock;

	CTRANSITION();
	CTRANSITION(const CTRANSITION& x) {}
	float getOffset(float maxOffset);

public:
	static CTRANSITION& offset();
	void update();
	void reset();
	float getLaneX();
	float getLaneY();
	float getObjectX();
	float getObjectY();

};

