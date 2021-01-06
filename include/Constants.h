#pragma once
#include <iostream>
#include <string>
using namespace std;

class Constants {
private:
	Constants() {};
	Constants(const Constants& other) {};
	Constants& operator=(const Constants&) {};
public:
	
	static Constants& GetInstance() {
		static Constants instance;
		return instance;
	}
	const double PI = 3.141592653589793238463;
	const int SCREEN_WIDTH = 432;
	const int SCREEN_LENGTH = 768;
	const float LANE_WIDTH = 100;
	const int MAX_NUMBER_OF_LANES = 30; // 432 : 768
	const int MAX_NUMBER_OF_VEHICLES_EACH_LANE = 1;
	const int MAX_TREE_PER_LANE = 1;
	const float TIME_BETWEEN_TRAFFIC = 10;
	const float MAX_TRAFFIC_STOP = 3;
	const int NUMBER_OF_MENU_ITEMS = 3;
	const int NUMBER_OF_OPTION_ITEMS = 4;
	const string SAVE_FILE;
	const float DISTANCE_BETWEEN_LANES = 100;
	const float PADDING_TOP = 200;
	const float DISTANCE_BETWEEN_OBSTACLES = 300;
	const double ALPHA = 15 * PI / 180, BETA = 75 * PI / 180;
	const double PLAYER_STEP = 100;
	const double PLAYER_STEP_HORIZONTAL = 25;
	const int FPS = 60;
	const int ANIMAL = 1, VEHICLE = 2, INTERACTABLE = 3, BLOCK = 4;
	const int NUMBER_OF_CARS = 4, NUMBER_OF_ANIMALS = 2;
	
	// Constants(Constants const&) = delete;
	//void operator=(Constants const&) = delete;

};
