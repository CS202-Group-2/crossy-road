#pragma once
#include <SFML/Audio.hpp>

class CSOUNDEFFECT {
protected:
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
public:
	virtual void playSound() = 0;
};