#pragma once

#include <iostream>
#include "CPEOPLE.h"
#include "CVEHICLE.h"
#include "CTRUCK.h"
#include "CCAR.h"
#include "CANIMAL.h"
#include "CDINAUSOR.h"
#include "CBIRD.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <wtypes.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

using namespace std;

typedef void* HANDLE;

class CGAME {
private:
    CTRUCK* axt;
    CCAR* axh;
    CDINAUSOR* akl;
    CBIRD* ac;
    CPEOPLE cn;

    vector<CANIMAL*> animals;
    const int rowCount = 7;
    const int maxVehicle = 5;
    vector<vector<CVEHICLE*>> vehicles;
    vector<sf::Sprite> sprites;


    void initVariables();
    void initWindow();
    void initVehicle();

    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;

    sf::RectangleShape enemy;
    sf::Texture texture;

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

    void update();
    void render();
    void pollEvents();
    void GetDesktopResolution();
    const bool running() const;
};