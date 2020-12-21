#pragma once

#include <iostream>

using namespace std;

class CANIMAL {
protected:
    int mX, mY;
    friend class CGAME;

public:
    virtual void move(int x, int y);
    virtual void tell();
};