
/*
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "CTRAFFIC.h"
#include <vector>
#include "../include/Constants.h"
using namespace std;

class CVEHICLE {
protected:
    float mX = 0, mY = 0;
    friend class CGAME;
    string textureFile = "vehicle.jpg";
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock clock;
    float speedMult = 2.0f;
public:
    CVEHICLE(float x, float y);
    void update(float x, float y, sf::RenderWindow& window, vector<CVEHICLE*>& vehicles);
    int checkCollision(vector<CVEHICLE*>& vehicles);
    virtual void move(float x, float y, sf::RenderWindow &window);
    virtual void drawVehicle(sf::RenderWindow& window);
  //  virtual void tell () = 0;
    virtual void crash ();
};
*/