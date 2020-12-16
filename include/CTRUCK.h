#pragma once

#include <iostream>
#include "CVEHICLE.h"

using namespace std;

class CTRUCK : public CVEHICLE {
private:
    friend class CGAME;
public:
    CTRUCK(int x, int y);
    void move(int x, int y);
};