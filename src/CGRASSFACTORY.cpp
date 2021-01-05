#include "../include/CGRASSFACTORY.h"

COBJECT* CGRASSFACTORY::initObject(int index, sf::RenderWindow* window) {
    return nullptr;
}

void CGRASSFACTORY::initBackground(int index, sf::Texture& textureLane) {
    if (!textureLane.loadFromFile("Grass.png")) {
        return;
    }
}