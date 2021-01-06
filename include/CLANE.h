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
    bool isGrass = true;
public:
    CLANE(int index, sf::RenderWindow* window, COBJECTFACTORY* factory, string textureFile = "none", float objX = -1e9, float objY = -1e9, float objSpeed = -1e9, float coinX = -1e9, float coinY = -1e9);
    CLANE(int index, COBJECTFACTORY *factory, sf::RenderWindow *window, bool isGrass = false);
    ~CLANE();
    void initObject();
    bool updatePosObject(float x, float y, sf::RenderWindow &window, CPEOPLE &player, CTRAFFIC &traffic);
    void shiftLane();
    void shiftBackground();
    bool checkBlock(float x, float y);
    void saveLane(ofstream& out);
    void setupLaneBackground();
};

#endif