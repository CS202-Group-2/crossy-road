#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

class CJUMP {
	sf::SoundBuffer jumpSoundBuffer;
	sf::Sound jumpSound;
public:
	CJUMP ();
	void playJumpSound ();
};