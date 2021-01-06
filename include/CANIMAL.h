#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/COBJECT.h"
#include "../include/Constants.h"
#include <Windows.h>

using namespace std;

class CANIMAL : public COBJECT {
private:
    friend class CGAME;
public:
    CANIMAL(string textureFile, float x, float y, float speed);
    CANIMAL(int index, int windowX);
    CANIMAL(float x, float y);
    CANIMAL(float x, float y, bool direction);
    void move(float x, float y);
    void trafficStop(bool state);
};