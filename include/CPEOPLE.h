#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "CASSET.h"
#include "CTRANSITION.h"
#include <fstream>
#include <math.h>
using namespace std;

enum class COLLISION_TYPE { FROM_BOTTOM, FROM_TOP, FROM_SIDE };

class CPEOPLE {
private:
    friend class CGAME;
    friend class CLANE;
    friend class COBJECT;
    float mX, mY;
    bool mState;
    int index;
    string textureFile = "Player.png";
    int gender, side, score, level;
    sf::Sound screamSound;
    sf::SoundBuffer* buffer;
    sf::Texture* mTexture;
    sf::Texture* dieTexture;
    sf::Sprite mSprite;
    sf::RenderWindow* mWindow;
public:
    static int FIG_WIDTH, FIG_HEIGHT, DIE_WIDTH, DIE_HEIGHT;
    static float FIG_SCALE, DIE_SCALE;
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

    void setDie(COLLISION_TYPE type);
    void scream();
    void disappear();
    void render(bool isGameOver);

    void moveUp();
    void moveLeft();
    void moveRight();
    void moveDown();

    bool isImpact(const COBJECT*&);
    bool isFinish();
    bool isDead();

    void resetPlayer();

    void savePlayer(int score, int level);
};
