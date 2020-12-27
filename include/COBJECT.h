
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class COBJECT {
protected:
    float mX = 0, mY = 0;
    friend class CGAME;
    string textureFile = "animal.jpg";
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock clock;
    float speedMult = 2.0f;
    int type;
public:
    COBJECT(float x, float y);
    void update(float x, float y, sf::RenderWindow& window, vector<COBJECT*>& objects);
    int checkCollision(vector<COBJECT*>& objects);
    virtual void move(float x, float y, sf::RenderWindow& window);
    virtual void drawObject(sf::RenderWindow& window);
};