#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

class CEAT {
	sf::SoundBuffer jumpSoundBuffer;
	sf::Sound jumpSound;
public:
	CEAT ();
	void playJumpSound ();
};