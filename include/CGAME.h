

#include "CLANE.h"
#include "COBJECTFACTORY.h"
#include "CCARFACTORY.h"
#include "CGRASSFACTORY.h"
#include "CPEOPLE.h"
#include "CVEHICLE.h"
#include "CTRUCK.h"
#include "CCAR.h"
#include "../include/COBJECT.h"
#include "CDINAUSOR.h"
#include "CBIRD.h"
#include "Menu.h"
#include "Constants.h"
#include "CTRAFFIC.h"
#include "CGUI.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <wtypes.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <vector>
#include <deque>

using namespace std;

enum class GAME_STATE{MENU, LEVEL_1, LEVEL_2, LEVEL_3, GAMEOVER, PAUSE};

typedef void* HANDLE;

class CGAME {
private:
    CTRUCK* axt;
    CCAR* axh;
    CDINAUSOR* akl;
    CBIRD* ac;
    CPEOPLE* player;

   // vector<COBJECT*> animals;
    vector<COBJECT*> vehicles;
    CTRAFFIC* traffic;
    deque<CLANE*> lanes;
    //vector<sf::Sprite> lanes;
    vector<sf::Sprite> sprites;
    GAME_STATE gameState = GAME_STATE::MENU;
    Menu *menu = nullptr;
    CGUI* cgui = nullptr;
    bool isGameOver = false;
    int score = 0, level = 1;
    
        
    void initVariables();
    void initWindow();
    //void initVehicle();
    void initLanes();

    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;

    sf::RectangleShape enemy;
    sf::Texture texture;
    sf::Sprite background;
    sf::Texture textureRoad;

public:
    CGAME(); 
    void drawGame(); 
    ~CGAME(); 
    CPEOPLE* getPlayer();
    COBJECT* getVehicle();
  //  COBJECT* getAnimal(); 
    void resetGame(); 
    void exitGame(HANDLE); 
    void startGame(); 
    bool loadGame(string loadFile); 
    bool saveGame(string saveFile);
    void pauseGame(HANDLE); 

    void resumeGame(HANDLE); 
    void updatePosPeople(char);
    void createNewLane(int index);
    void updateLanes();
    void shiftLanesUp();
    //void updatePosVehicle(); 
    void drawLane();
   // void updatePosAnimal();
    void drawBackground(const string &backgroundIMG);
    void resizeImage(sf::Sprite& sprite);
    

    void update();
    void render();
    void pollEvents();
    void GetDesktopResolution();
    const bool running() const;
};