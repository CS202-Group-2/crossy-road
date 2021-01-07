

#include "CLANE.h"
#include "COBJECTFACTORY.h"
#include "CCARFACTORY.h"
#include "CGRASSFACTORY.h"
#include "CANIMALFACTORY.h"
#include "CPEOPLE.h"
#include "CCAR.h"
#include "../include/COBJECT.h"
#include "Menu.h"
#include "Constants.h"
#include "CTRAFFIC.h"
#include "CGUI.h"
#include "CSOUND.h"
#include "CJUMP.h"
#include "CSOUNDFACTORY.h"
#include "CTRANSITION.h"

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

enum class GAME_STATE{MENU, LEVEL_1, LEVEL_2, LEVEL_3, GAMEOVER, PAUSE, WARNING, GENDER_CHOICE};

typedef void* HANDLE;

class CGAME {
private:
    CPEOPLE* player;
    CSOUNDFACTORY* soundFactory;

    CTRAFFIC* traffic;
    deque<CLANE*> lanes;
    //vector<sf::Sprite> lanes;
    vector<sf::Sprite> sprites;
    GAME_STATE gameState = GAME_STATE::MENU;
    Menu *menu = nullptr;
    CGUI* cgui = nullptr;
    sf::Clock clock;
    bool isGameOver = false;
    bool pressed = false;
    int score = 0, level = 1;
    int coinMoveMark = 0;
    string warning;
        
    void initVariables();
    void initWindow();
    //void initVehicle();
    void initLanes();
    void initSound();

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
    CPEOPLE* getPlayer(bool newPlayer = false);
    COBJECT* getVehicle();
  //  COBJECT* getAnimal(); 
    void resetGame(); 
    void exitGame(HANDLE); 
    void startGame(); 
    bool loadGame(); 
    void clearSavedGame();
    bool saveGame();
    bool haveSavedGame();
    void pauseGame(HANDLE); 

    void resumeGame(HANDLE); 
    void updatePosPeople(char);
    void createNewLane(int index, int level);
    void updateLanes();
    void shiftLanesUp();
    void updateSound();
//    void updateSoundJump ();

    //void updatePosVehicle(); 
    void drawLane();
   // void updatePosAnimal();
    void drawBackground(const string &backgroundIMG);
    void resizeImage(sf::Sprite& sprite);
    bool checkMove(CLANE* lane, CPEOPLE* player, int direction);
    CLANE* findLane(int index);
    
    bool hasCharacterGender();
    void update();
    void render();
    void pollEvents();
    void GetDesktopResolution();
    const bool running() const;
};
