#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Constants.h"
#include "CVEHICLE.h"
#include "CANIMAL.h"
#include <fstream>
#include <math.h>

using namespace std;

class CPEOPLE {
private:
    friend class CGAME;
    int mX, mY;
    bool mState; 
    string textureFile = "Player.png";
    int gender, side;

    sf::Texture mTexture;
    sf::Sprite mSprite;
    sf::RenderWindow* mWindow;
public:
    static int FIG_WIDTH, FIG_HEIGHT;
    static double FIG_SCALE;
    static int RIGHT, LEFT, UP, DOWN;
    static int MALE, FEMALE;
    static double MOVEABLE_DIST;


    CPEOPLE(sf::RenderWindow* window, int gender, int side = UP, int x = -1, int y = -1);

    bool canMoveDown();
    bool canMoveUp();
    bool canMoveRight();
    bool canMoveLeft();

    void setGender(int gender);
    void setSide(int side = UP);

    void render();

    void moveUp();
    void moveLeft();
    void moveRight();
    void moveDown();
    bool isImpact(const CVEHICLE*&);
    bool isImpact(const CANIMAL*&);
    bool isFinish();
    bool isDead();
    sf::Sprite& getSprite() {
        return mSprite;
    }

    void savePlayer();
};