#ifndef _CLANE_H_
#define _CLANE_H_

#include <iostream>
#include "COBJECTFACTORY.h"
#include "CCOINFACTORY.h"
#include "CTREEFACTORY.h"
#include "CPEOPLE.h"
#include "CCAR.h"
#include "CANIMAL.h"
#include "COBJECT.h"
#include "Constants.h"
#include "CTRAFFIC.h"
#include "CTRANSITION.h"
#include "CGAMEOVERFIG.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <wtypes.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <vector>
#include <SFML//Graphics.hpp>
#include "CSOUNDFACTORY.h"

using namespace std;

class CLANE {
protected:
    int index;
    friend class CGAME;
    COBJECT* object;
    COBJECT* coin;
    vector<COBJECT*> blocks;
    COBJECTFACTORY* factory;
    sf::Sprite laneBackground;
    sf::Texture textureLane;
    sf::RenderWindow* window;
    bool isGrass;
    string background;

    CGAMEOVERFIG* gameoverFig;

public:
    CLANE(int index, string background, sf::RenderWindow* window, COBJECTFACTORY* factory, vector<pair<float, float>>& bushes, 
        string textureFile = "none", float objX = -1e9, float objY = -1e9, float objSpeed = -1e9, 
        float coinX = -1e9, float coinY = -1e9);
    CLANE(int index, COBJECTFACTORY* factory, sf::RenderWindow* window, bool isGrass = false, int level = 0);
    ~CLANE();
    void initObject(int level);
    bool updatePosObject(float x, float y, sf::RenderWindow &window, CPEOPLE &player, 
        CTRAFFIC &traffic, int level, int rand, CSOUNDFACTORY* soundFactory, COLLISION_TYPE* collision = 0);
    void shiftLane();
    void shiftBackground();
    bool checkBlock(float x, float y);
    void saveLane(ofstream& out);
    void setupLaneBackground();
    bool eatCoin();
};

#endif