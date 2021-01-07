#include "../include/CGRASSFACTORY.h"

COBJECT* CGRASSFACTORY::initObject(int index, sf::RenderWindow* window, int level) {
    
    return nullptr;

}

void CGRASSFACTORY::initBackground(int index, sf::Texture& textureLane, bool& isGrass, string& background) {
    background = "Grass";
    if (!textureLane.loadFromFile("assets/graphics/Grass.png")) {
        return;
    }
    isGrass = true;
}

bool CGRASSFACTORY::isGrass() {
    return true;
}