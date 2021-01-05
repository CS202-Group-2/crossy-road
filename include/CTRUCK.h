#pragma once

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <SFML/audio.hpp>
#include "../include/COBJECT.h"
#include "../include/Constants.h"
#include <Windows.h>

using namespace std;

class CTRUCK : public COBJECT {
private:
    friend class CGAME;
public:
    CTRUCK(float x, float y);
    void move(float x, float y, sf::RenderWindow& window);
    void drawObject(sf::RenderWindow& window);
    void tell ();
};