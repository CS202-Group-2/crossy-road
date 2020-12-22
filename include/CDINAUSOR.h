#pragma once

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <SFML/Graphics.hpp>
#include "CANIMAL.h"

using namespace std;

class CDINAUSOR : public CANIMAL {
private:
    friend class CGAME;

public:
    CDINAUSOR(float x, float y);
    void move(float x, float y, sf::RenderWindow& window);
    void drawAnimal(sf::RenderWindow& window);
};