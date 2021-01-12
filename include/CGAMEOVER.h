#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
#include "CSOUNDEFFECT.h"
using namespace std;

class CGAMEOVER : public CSOUNDEFFECT {
public:
	CGAMEOVER ();
	void playSound ();
};