#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
#include "CSOUNDEFFECT.h"
using namespace std;

class CEAT : public CSOUNDEFFECT {
public:
	CEAT ();
	void playSound ();
};