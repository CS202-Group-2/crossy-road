#include "../include/CCOINFACTORY.h"

COBJECT* CCOINFACTORY::initObject(int index, sf::RenderWindow* window, int level) {
    float x = rand() % (window->getSize().x/2) + window->getSize().x / 2;
    COBJECT* object = new CCOIN(x, (index - 3) * Constants::GetInstance().LANE_WIDTH 
        + abs(x * tan(Constants::GetInstance().BETA / 3.14 * 180)), index);
    // cout << "Spawned vehicle in row index " << index << endl;
    cout << "Spawned at " << x << "  " << abs(x * tan(Constants::GetInstance().BETA / 3.14 * 180)) << endl;
    return object;
}

void CCOINFACTORY::initBackground(int index, sf::Texture& textureLane, bool& isGrass, string& background) {

}
//void CCOINFACTORY::shiftBackground(int index, sf::Sprite& laneBackground) {}

bool CCOINFACTORY::isGrass() {
    return false;
}