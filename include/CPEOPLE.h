#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "CTRANSITION.h"
#include <fstream>
#include <math.h>
using namespace std;

class CPEOPLE {
private:
    friend class CGAME;
    friend class COBJECT;
    float mX, mY;
    bool mState;
    int index;
    string textureFile = "Player.png";
    int gender, side, score, level;

    sf::Texture mTexture;
    sf::Sprite mSprite;
    sf::RenderWindow* mWindow;
public:
    static int FIG_WIDTH, FIG_HEIGHT;
    static float FIG_SCALE;
    static int RIGHT, LEFT, UP, DOWN;
    static int MALE, FEMALE;
    static float MOVEABLE_DIST;

    CPEOPLE(sf::RenderWindow* window, int gender, int side = UP, int x = -1, int y = -1, int index = 0);

    bool canMoveDown();
    bool canMoveUp();
    bool canMoveRight();
    bool canMoveLeft();

    void setGender(int gender);
    void setSide(int side = UP);
    void addScore(int amount);

    void render();

    void moveUp();
    void moveLeft();
    void moveRight();
    void moveDown();
    //bool isImpact(const COBJECT*&);
    bool isImpact(const COBJECT*&);
    bool isFinish();
    bool isDead();

    void resetPlayer();

    void savePlayer(int score, int level);
};
