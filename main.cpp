#include <iostream>
#include "include/CGAME.h"

using namespace std;

int main() {
    srand(time(NULL));
    CGAME game;


    while (game.running())
    {
        
        game.update();
        game.render();
    }

    
    return 0;
}