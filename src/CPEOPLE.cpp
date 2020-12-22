#include "../include/CPEOPLE.h"

CPEOPLE::CPEOPLE() {
    if (!texture.loadFromFile(textureFile)) {
        cout << "Cannot find texture file" << endl;
        return;
    }
    sprite.setTexture(texture);
}

void CPEOPLE::moveUp(int) {

}

void CPEOPLE::moveLeft(int) {

}

void CPEOPLE::moveRight(int) {

}
 
void CPEOPLE::moveDown(int) {

}

bool CPEOPLE::isImpact(const CVEHICLE*&) {
    return false;
}

bool CPEOPLE::isImpact(const CANIMAL*&) {
    return false;
}

bool CPEOPLE::isFinish() {
    return false;
}

bool CPEOPLE::isDead() {
    return false;
}