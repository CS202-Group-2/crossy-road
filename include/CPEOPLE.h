#pragma once

#include <iostream>
#include "CVEHICLE.h"
#include "CANIMAL.h"

using namespace std;

class CPEOPLE {
private:
    int mX, mY;
    bool mState; 
public:
    CPEOPLE();
    void moveUp(int);
    void moveLeft(int);
    void moveRight(int);
    void moveDown(int);
    bool isImpact(const CVEHICLE*&);
    bool isImpact(const CANIMAL*&);
    bool isFinish();
    bool isDead();
};