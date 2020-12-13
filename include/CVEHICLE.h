#pragma once

#include <iostream>

using namespace std;

class CVEHICLE {
private:
    int mX, mY;
public:
    virtual void move(int x, int y);
};