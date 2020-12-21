#pragma once

#include <iostream>
#include "CVEHICLE.h"
#include <SFML/audio.hpp>

using namespace std;

class CCAR : public CVEHICLE {
private:
    friend class CGAME;
public:
    CCAR (int x, int y);
    void move(int x, int y);
    void tell ();
    void crash ();
};