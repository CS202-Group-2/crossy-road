#ifndef _COBJECT_H_
#define _COBJECT_H_

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/CPEOPLE.h"
#include <string>
#include "../include/CTRAFFIC.h"
#include "Constants.h"
#include "CTRANSITION.h"

using namespace std;

class COBJECT {
protected:
    float mX = 0, mY = 0;
    friend class CGAME;
    friend class CLANE;
    string textureFile;

    sf::Texture texture;
    sf::Sprite sprite;

    bool interacted = false;
    bool direction; // true: forward, false: backward
    float initY = 0;
    float speedMult = 5.0f;
    int type, index;
    string sound;
    string getTextureFile();
    COBJECT();
public:
    COBJECT(float x, float y);
    COBJECT(float x, float y, int index);
    void update(float x, float y, sf::RenderWindow& window, vector<COBJECT*>& objects, CPEOPLE& player);
    virtual bool update(float x, float y, sf::RenderWindow& window, CPEOPLE& player, int index);
    void shiftObject();
    //int checkCollision(vector<COBJECT*>& objects, CPEOPLE& player, vector< CTRAFFIC> traffics);
    int checkCollision(vector<COBJECT*>& objects, CPEOPLE& player);
    bool checkOutWindow (sf::RenderWindow& window);
    virtual void move(float x, float y, sf::RenderWindow& window);
    virtual void drawObject(sf::RenderWindow& window);
    virtual void trafficStop(bool state) = 0;
    bool checkCollision(CPEOPLE& player, int index);
};

#endif
