#pragma once

#include <iostream>
#include "CVEHICLE.h"
#include "CANIMAL.h"
#include <SFML/Graphics.hpp>

using namespace std;

class CPEOPLE {
private:
    friend class CGAME;
    int mX, mY;
    bool mState; 
    string textureFile = "Player.png";
    sf::Texture texture;
    sf::Sprite sprite;
public:
    CPEOPLE();
    void moveUp(int);
    void moveLeft(int);
    void moveRight(int);
    void moveDown(int);
    bool isImpact(const CVEHICLE*&);
    bool isImpact(const CANIMAL*&);
    bool isFinish();
    bool isDead();
    sf::Sprite& getSprite() {
        return sprite;
    }
};