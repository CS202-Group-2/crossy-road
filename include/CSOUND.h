#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
#include "CSOUNDEFFECT.h"
using namespace std;

class CSOUND : public CSOUNDEFFECT {
public:
	CSOUND();
	void playSound();
};