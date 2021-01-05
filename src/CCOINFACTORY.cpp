#include "../include/CCOINFACTORY.h"

COBJECT* CCOINFACTORY::initObject(int index, sf::RenderWindow* window) {
    COBJECT* object = new CCOIN(rand() % (window->getSize().x-25) + 25,
        (index - 2) * Constants::GetInstance().LANE_WIDTH, index);
    // cout << "Spawned vehicle in row index " << index << endl;
    return object;
}

void CCOINFACTORY::initBackground(int index, sf::Texture& textureLane, sf::Sprite& laneBackground, sf::RenderWindow* window) {}
void CCOINFACTORY::shiftBackground(int index, sf::Sprite& laneBackground) {}