#pragma once

#include <iostream>
#include "CVEHICLE.h"
#include <SFML/audio.hpp>

using namespace std;

class CTRUCK : public CVEHICLE {
private:
    friend class CGAME;
public:
    CTRUCK(int x, int y);
    void move(int x, int y);
    void tell ();
    void crash ();
};