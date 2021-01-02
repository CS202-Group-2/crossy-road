#include "../include/CCARFACTORY.h"

COBJECT* CCARFACTORY::initObject(int index, sf::RenderWindow* window) {
    //srand(time(NULL));
    int dir = rand() % 2;
    COBJECT* object = nullptr;
    if (dir == 0) object = new CCAR(-100, (index - 2) * Constants::GetInstance().LANE_WIDTH + 25, true);
    else object = new CCAR(window->getSize().x+100, 
        window->getSize().x * tan(Constants::GetInstance().ALPHA) + (index-1) * Constants::GetInstance().LANE_WIDTH - 25, false);
    return object;
}

void CCARFACTORY::initBackground(int index, sf::Texture& textureLane, sf::Sprite& laneBackground, sf::RenderWindow* window) {
    int choice = rand() % 2;
    if (choice == 0) {
        if (!textureLane.loadFromFile("Road.png")) {
            return;
        }
    }
    else if (!textureLane.loadFromFile("Grass.png")) {
        return;
    }
    laneBackground.setTexture(textureLane);
    double scaleX = (window->getSize().x * 2 + 100) / laneBackground.getGlobalBounds().width;
    laneBackground.setScale(scaleX, scaleX);
    //double scaleY = 100 / laneBackground.getGlobalBounds().height;
   // laneBackground.setScale(scaleY, scaleY);
    laneBackground.setPosition(0, (index - 2) * Constants::GetInstance().LANE_WIDTH);
}