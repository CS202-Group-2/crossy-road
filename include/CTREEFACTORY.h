#pragma once
#include "COBJECTFACTORY.h"
#include "CTREE.h"

class CTREEFACTORY : public COBJECTFACTORY {
public:
    COBJECT* initObject(int index, sf::RenderWindow* window, int level);
    void initBackground(int index, sf::Texture& textureLane, bool& isGrass);
    //virtual void shiftBackground(int index, sf::Sprite& laneBackground);
};



//void CCOINFACTORY::shiftBackground(int index, sf::Sprite& laneBackground) {}