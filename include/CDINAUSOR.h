#pragma once

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "../include/COBJECT.h"
#include "../include/Constants.h"
#include <Windows.h>

using namespace std;

class CDINAUSOR : public COBJECT {
private:
    friend class CGAME;

public:
    CDINAUSOR(float x, float y);
    void move(float x, float y, sf::RenderWindow& window);
    void drawObject(sf::RenderWindow& window);
};