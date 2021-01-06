#include "../include/CGRASSFACTORY.h"

COBJECT* CGRASSFACTORY::initObject(int index, sf::RenderWindow* window) {
    
    return nullptr;

}

void CGRASSFACTORY::initBackground(int index, sf::Texture& textureLane, bool& isGrass) {
    if (!textureLane.loadFromFile("assets/graphics/Grass.png")) {
        return;
    }
    isGrass = true;
}