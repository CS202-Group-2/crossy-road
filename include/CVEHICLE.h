#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "CTRAFFIC.h"
#include <math.h>
#include "../Constants.h"

using namespace std;

class CVEHICLE {
protected:
    float mX = 0, mY = 0;
    friend class CGAME;
    string textureFile = "vehicle.jpg";
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock clock;
    float initY = 0;
    float speedMult = 1.0f;
    bool isOutOfBound = false;
public:
    CVEHICLE(float x, float y);
    void update(float x, float y, sf::RenderWindow& window, vector<CVEHICLE*>& vehicles, vector<CTRAFFIC> traffics);
    int checkCollision(vector<CVEHICLE*>& vehicles);
    virtual void move(float x, float y, sf::RenderWindow &window, vector<CTRAFFIC> traffics);
    virtual void drawVehicle(sf::RenderWindow& window);
    virtual void tell () = 0;
    virtual void crash ();
    bool IsOutOfBound() { return isOutOfBound; };
};