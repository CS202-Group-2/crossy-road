#include "../include/CCARFACTORY.h"

COBJECT* CCARFACTORY::initObject(int index, sf::Texture& textureLane, sf::Sprite& laneBackground, sf::RenderWindow* window) {
    if (!textureLane.loadFromFile("Road.png")) {
        return nullptr;
    }
    laneBackground.setTexture(textureLane);
    double scaleX = (window->getSize().x * 2 + 100) / laneBackground.getGlobalBounds().width;
    laneBackground.setScale(scaleX, scaleX);
    //double scaleY = 100 / laneBackground.getGlobalBounds().height;
   // laneBackground.setScale(scaleY, scaleY);
    laneBackground.setPosition(0, (index - 1) * Constants::GetInstance().LANE_WIDTH);
    
    COBJECT* object = new CCAR(-100, (index - 1) * Constants::GetInstance().LANE_WIDTH + 25);
    return object;
}