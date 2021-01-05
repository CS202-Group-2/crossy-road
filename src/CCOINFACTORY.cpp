#include "../include/CCOINFACTORY.h"

COBJECT* CCOINFACTORY::initObject(int index, sf::RenderWindow* window) {
    float x = rand() % (window->getSize().x - 25) + 25;
    COBJECT* object = new CCOIN(x, (index - 3) * Constants::GetInstance().LANE_WIDTH 
        + abs(x * tan(Constants::GetInstance().BETA / 3.14 * 180)), index);
    // cout << "Spawned vehicle in row index " << index << endl;
    return object;
}

void CCOINFACTORY::initBackground(int index, sf::Texture& textureLane) {

}
//void CCOINFACTORY::shiftBackground(int index, sf::Sprite& laneBackground) {}