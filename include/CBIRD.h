#pragma once

#include <iostream>
#include "CANIMAL.h"

using namespace std;

class CBIRD : CANIMAL {
private:

public:
    void move(int x, int y);
    void tell();
};