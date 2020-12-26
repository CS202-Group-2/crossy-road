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
	const int MAX_NUMBER_OF_LANES = 8;
	const int MAX_NUMBER_OF_VEHICLES_EACH_LANE = 1;
	const float TIME_BETWEEN_TRAFFIC = 10;
	const float MAX_TRAFFIC_STOP = 5;
	const int NUMBER_OF_MENU_ITEMS = 3;
	const string SAVE_FILE;
	const float DISTANCE_BETWEEN_LANES = 200;
	const float PADDING_TOP = 200;
	const float DISTANCE_BETWEEN_OBSTACLES = 300;

	// Constants(Constants const&) = delete;
	//void operator=(Constants const&) = delete;

};
