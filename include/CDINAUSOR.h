#pragma once

#include <iostream>
#include "CANIMAL.h"

using namespace std;

class CDINAUSOR : public CANIMAL {
private:

public:
    void move(int x, int y);
    void tell();
};