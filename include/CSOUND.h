#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

class CSOUND {
	sf::SoundBuffer backgroundSoundBuffer;
	sf::Sound backgroundSound;
public:
	CSOUND();
	void playBackgroundSound();
};