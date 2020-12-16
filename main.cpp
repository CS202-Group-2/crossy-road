#include <iostream>
#include "include/CGAME.h"
#include "include/CPEOPLE.h"
#include "include/CVEHICLE.h"
#include "include/CTRUCK.h"
#include "include/CCAR.h"
#include "include/CANIMAL.h"
#include "include/CDINAUSOR.h"
#include "include/CBIRD.h"





using namespace std;



int main() {
    
    CGAME game;


    while (game.running())
    {
        
        game.update();
        game.render();
    }

    
    return 0;
}