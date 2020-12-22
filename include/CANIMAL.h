#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class CANIMAL {
protected:
    float mX = 0, mY = 0;
    friend class CGAME;
    string textureFile = "animal.jpg";
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock clock;
    float speedMult = 2.0f;
public:
    CANIMAL(float x, float y);
    void update(float x, float y, sf::RenderWindow& window, vector<CANIMAL*>& animals);
    int checkCollision(vector<CANIMAL*>& animals);
    virtual void move(float x, float y, sf::RenderWindow& window);
    virtual void drawAnimal(sf::RenderWindow& window);
};