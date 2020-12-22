#pragma once

#include <iostream>
#include "CVEHICLE.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>

using namespace std;

class CCAR : public CVEHICLE {
private:
    friend class CGAME;
    
public:
    CCAR(float x, float y);
    void move(float x, float y, sf::RenderWindow &window, vector<CTRAFFIC> traffics);
    void drawVehicle(sf::RenderWindow &window);
    void tell ();
    void crash ();
};