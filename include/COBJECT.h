#ifndef _COBJECT_H_
#define _COBJECT_H_

#pragma once

#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/CPEOPLE.h"
#include <string>
#include "../include/CTRAFFIC.h"
#include "Constants.h"
#include "CTRANSITION.h"
#include "CSOUNDFACTORY.h"
#include "CASSET.h"

using namespace std;

class COBJECT {
protected:
    float mX = 0, mY = 0;
    friend class CGAME;
    friend class CLANE;
    string textureFile;

    sf::SoundBuffer *buffer;
    sf::Sound objSound;
    string soundFilename;

    sf::Texture texture;
    sf::Sprite sprite;

    bool interacted = false;

    // To make the crash sound play only once.
    bool soundPlay = false;

    bool direction; // true: forward, false: backward
    float initY = 0;
    float speedMult;// = 5.0f;
    int type, index;
    string sound;
    string getTextureFile();
    void setupTexture();

    bool tilted;
    COBJECT();
    COBJECT(int level);
public:
    static COLLISION_TYPE collisionType;

    COBJECT(float x, float y);
    COBJECT(float x, float y, int index);
    void initSpeedMult(int level = 0);
    virtual int update(float x, float y, sf::RenderWindow& window, CPEOPLE& player, 
        int index, int rand, CSOUNDFACTORY* soundFactory, COLLISION_TYPE* collision = 0);
    void shiftObject();
    bool checkOutWindow (sf::RenderWindow& window);
    virtual void move(float x, float y);
    virtual void drawObject(sf::RenderWindow& window);
    virtual void trafficStop(bool state) = 0;
    void crashSound();
    void setupSound();
    bool checkCollision(CPEOPLE& player, int index, COLLISION_TYPE* collision = 0);
    bool checkBlock(float x, float y);
    
};

#endif
