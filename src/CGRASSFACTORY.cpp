#include "../include/CGRASSFACTORY.h"

COBJECT* CGRASSFACTORY::initObject(int index, sf::RenderWindow* window) {
    CTREEFACTORY* treeFactory = new CTREEFACTORY();
    COBJECT* tree = nullptr;
    float x = rand() % (window->getSize().x - 25) + 25;
    for (int i = 0; i < Constants::GetInstance().MAX_TREE_PER_LANE; ++i) {
        tree = new CTREE(x, (index - 3) * Constants::GetInstance().LANE_WIDTH
            + abs(x * tan(Constants::GetInstance().BETA / 3.14 * 180)), index);
    }

    delete treeFactory;
    return nullptr;

}

void CGRASSFACTORY::initBackground(int index, sf::Texture& textureLane) {
    if (!textureLane.loadFromFile("assets/graphics/Grass.png")) {
        return;
    }
}