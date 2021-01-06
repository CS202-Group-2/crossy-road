#pragma once

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/COBJECT.h"
#include "../include/Constants.h"
#include <Windows.h>

using namespace std;

class CCAR : public COBJECT {
private:
    friend class CGAME;
    bool isStopping = false;
public:
    CCAR(string textureFile, float x, float y, float speed);
    CCAR(int index, int windowX);
    CCAR(float x, float y);
    CCAR(float x, float y, bool direction);
    void move(float x, float y, sf::RenderWindow &window);
    void trafficStop(bool state);
};