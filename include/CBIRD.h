#pragma once

#include <iostream>
#include <stdlib.h>    
#include <time.h> 
#include <SFML/Graphics.hpp>
#include "../include/COBJECT.h"
#include "../include/Constants.h"
#include <SFML/audio.hpp>
#include <Windows.h>

using namespace std;

class CBIRD : public COBJECT {
private:
    friend class CGAME;

public:
    CBIRD(float x, float y);
    void move(float x, float y);
    void drawObject(sf::RenderWindow& window);
};