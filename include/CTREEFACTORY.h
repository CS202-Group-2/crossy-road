#pragma once
#include "COBJECTFACTORY.h"
#include "CTREE.h"

class CTREEFACTORY : public COBJECTFACTORY {
public:
    void initBackground(int index, sf::Texture& textureLane);
    virtual COBJECT* initObject(int index, sf::RenderWindow* window);
    //virtual void shiftBackground(int index, sf::Sprite& laneBackground);
};



//void CCOINFACTORY::shiftBackground(int index, sf::Sprite& laneBackground) {}