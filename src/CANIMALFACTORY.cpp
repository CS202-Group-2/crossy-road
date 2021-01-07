#include "../include/CANIMALFACTORY.h"

COBJECT* CANIMALFACTORY::initObject(int index, sf::RenderWindow* window, int level) {
    return new CANIMAL(index, window->getSize().x, level);
    //if (dir == 0) object = new CCAR(-100, (index - 3) * Constants::GetInstance().LANE_WIDTH, true);
    //else object = new CCAR(window->getSize().x+100, 
    //    window->getSize().x * tan(Constants::GetInstance().ALPHA) + (index-2) * Constants::GetInstance().LANE_WIDTH - 25, false);
    //// cout << "Spawned vehicle in row index " << index << endl;
    //return object;
}

void CANIMALFACTORY::initBackground(int index, sf::Texture& textureLane, bool &isGrass) {
    int k = rand() % 100;
    string filepath = "assets/graphics/";
    filepath += (k < 50 ? "Road.png" : "Grass.png");
    if (!textureLane.loadFromFile(filepath)) {
        return;
    }
    if (filepath == "assets/graphics/Grass.png") isGrass = true;
}

bool CANIMALFACTORY::isGrass() {
    return false;
}