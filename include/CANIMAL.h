#pragma once

#include <iostream>

using namespace std;

class CANIMAL {
private:
    int mX, mY;
public:
    virtual void move(int x, int y);
    virtual void tell();
};