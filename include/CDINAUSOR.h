#pragma once

#include <iostream>
#include "CANIMAL.h"

using namespace std;

class CDINAUSOR : public CANIMAL {
private:
    friend class CGAME;
public:
    CDINAUSOR (int x, int y);
    void move(int x, int y);
    void tell();
};