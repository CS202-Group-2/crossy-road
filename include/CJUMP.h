#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
#include "CSOUNDEFFECT.h"
using namespace std;

class CJUMP : public CSOUNDEFFECT {
public:
	CJUMP ();
	void playSound();
};