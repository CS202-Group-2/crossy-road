#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

class CGAMEOVER {
	sf::SoundBuffer jumpSoundBuffer;
	sf::Sound jumpSound;
public:
	CGAMEOVER ();
	void playJumpSound ();
};