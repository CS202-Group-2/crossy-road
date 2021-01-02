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
	const int MAX_NUMBER_OF_LANES = 1;
	const int MAX_NUMBER_OF_VEHICLES_EACH_LANE = 2;
	const float TIME_BETWEEN_TRAFFIC = 10;
	const float MAX_TRAFFIC_STOP = 5;
	const int NUMBER_OF_MENU_ITEMS = 3;
	const string SAVE_FILE;
	const float DISTANCE_BETWEEN_LANES = 100;
	const float PADDING_TOP = 200;
	const float DISTANCE_BETWEEN_OBSTACLES = 300;
	const double ALPHA = 30 * PI / 180, BETA = 40 * PI / 180;
	const double PLAYER_STEP = 15;
	const int FPS = 60;
	const int ANIMAL = 1, VEHICLE = 2;
	// Constants(Constants const&) = delete;
	//void operator=(Constants const&) = delete;

};
