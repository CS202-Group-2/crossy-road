#pragma once

#include <iostream>
#include "CANIMAL.h"

using namespace std;

class CBIRD : public CANIMAL {
private:
    friend class CGAME;
public:
    CBIRD (int x, int y);
    void move(int x, int y);
    void tell();
};