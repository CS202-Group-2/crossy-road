#include "../include/CTREEFACTORY.h"


COBJECT* CTREEFACTORY::initObject(int index, sf::RenderWindow* window,int level) {
    float x = (window->getSize().x) + window->getSize().x / 2;
    COBJECT* object = new CTREE(x, (index - 3) * Constants::GetInstance().LANE_WIDTH
        + abs(x * tan(Constants::GetInstance().BETA / 3.14 * 180)), index);
    // cout << "Spawned vehicle in row index " << index << endl;
    return object;
}

void CTREEFACTORY::initBackground(int index, sf::Texture*& textureLane, bool& isGrass, string& background) {

}

bool CTREEFACTORY::isGrass() {
    return false;
}