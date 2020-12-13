#pragma once

#include <iostream>
#include "CPEOPLE.h"
#include "CVEHICLE.h"
#include "CTRUCK.h"
#include "CCAR.h"
#include "CANIMAL.h"
#include "CDINAUSOR.h"
#include "CBIRD.h"

using namespace std;

typedef void* HANDLE;

class CGAME {
private:
    CTRUCK* axt;
    CCAR* axh;
    CDINAUSOR* akl;
    CBIRD* ac;
    CPEOPLE cn;

public:
    CGAME(); 
    void drawGame(); 
    ~CGAME(); 
    CPEOPLE getPeople();
    CVEHICLE* getVehicle();
    CANIMAL* getAnimal(); 
    void resetGame(); 
    void exitGame(HANDLE); 
    void startGame(); 
    void loadGame(istream&); 
    void saveGame(istream&); 
    void pauseGame(HANDLE); 
    void resumeGame(HANDLE); 
    void updatePosPeople(char);
    void updatePosVehicle(); 
    void updatePosAnimal();
};