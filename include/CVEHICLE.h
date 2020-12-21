#pragma once

#include <iostream>

using namespace std;

class CVEHICLE {
protected:
    int mX = 0, mY = 0;
    friend class CGAME;
public:
    virtual void move(int x, int y);
    virtual void tell () = 0;
    virtual void crash ();
};