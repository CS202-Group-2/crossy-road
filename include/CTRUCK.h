#pragma once

#include <iostream>
#include "CVEHICLE.h"

using namespace std;

class CTRUCK : public CVEHICLE {
private:

public:
    void move(int x, int y);
};