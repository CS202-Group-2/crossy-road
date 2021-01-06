#ifndef _CLANE_H_
#define _CLANE_H_

#include <iostream>
#include "COBJECTFACTORY.h"
#include "CCOINFACTORY.h"
#include "CPEOPLE.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"
#include "CTRUCK.h"
#include "CCAR.h"
#include "COBJECT.h"
#include "CDINAUSOR.h"
#include "CBIRD.h"
#include "Constants.h"
#include "CTRAFFIC.h"

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
    //vector<COBJECT*> blocks;
    COBJECTFACTORY* factory;
    sf::Sprite laneBackground;
    sf::Texture textureLane;
    sf::RenderWindow* window;
public:
    CLANE(int index, COBJECTFACTORY *factory, sf::RenderWindow *window);
    ~CLANE();
    void initObject();
    bool updatePosObject(float x, float y, sf::RenderWindow &window, CPEOPLE &player, CTRAFFIC &traffic);
    void shiftLane();
    void shiftBackground();
    bool checkBlock(float x, float y);
    void saveLane(ofstream& out);

};

#endif