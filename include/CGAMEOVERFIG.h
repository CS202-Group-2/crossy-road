#pragma once
#include "COBJECT.h"
#include "CPEOPLE.h"

class CGAMEOVERFIG : public COBJECT {
private:
    bool activated;
    sf::Texture *girlTexture, *boyTexture;
public:
    CGAMEOVERFIG(int index);
    void activateFig(int gender, float x, float y);
    void trafficStop(bool state);
    bool isActivated();
    void hide();
};