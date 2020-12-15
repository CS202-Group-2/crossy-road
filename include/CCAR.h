#pragma once

#include <iostream>
#include "CVEHICLE.h"

using namespace std;

class CCAR : public CVEHICLE {
private:

public:
    void move(int x, int y) {
        CVEHICLE::move(x, y);
    }
};