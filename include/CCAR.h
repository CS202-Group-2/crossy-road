#pragma once

#include <iostream>
#include "CVEHICLE.h"

using namespace std;

class CCAR : public CVEHICLE {
private:
    friend class CGAME;
public:
    void move(int x, int y);
};