

#include <iostream>
#include "CPEOPLE.h"
#include "CVEHICLE.h"
#include "CTRUCK.h"
#include "CCAR.h"
#include "CANIMAL.h"
#include "CDINAUSOR.h"
#include "CBIRD.h"
#include "Menu.h"
#include "Constants.h"
#include "CTRAFFIC.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <wtypes.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <vector>

using namespace std;

enum class GAME_STATE{MENU, LEVEL_1, LEVEL_2, LEVEL_3, GAMEOVER};

typedef void* HANDLE;

class CGAME {
private:
    CTRUCK* axt;
    CCAR* axh;
    CDINAUSOR* akl;
    CBIRD* ac;
    CPEOPLE* player;

    vector<CANIMAL*> animals;
    vector<CVEHICLE*> vehicles;
    vector<CTRAFFIC> traffics;
    vector<sf::Sprite> sprites;
    GAME_STATE gameState = GAME_STATE::MENU;
    Menu *menu = nullptr;
        
    void initVariables();
    void initWindow();
    void initVehicle();

    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;

    sf::RectangleShape enemy;
    sf::Texture texture;
    sf::Sprite background;

public:
    CGAME(); 
    void drawGame(); 
    ~CGAME(); 
    CPEOPLE* getPlayer();
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
    void drawBackground(const string &backgroundIMG);
    void resizeImage(sf::Sprite& sprite);

    void update();
    void render();
    void pollEvents();
    void GetDesktopResolution();
    const bool running() const;
};