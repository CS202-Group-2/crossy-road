#include "../include/CGAME.h"

CGAME::CGAME() {
    //srand(time(NULL));
    this->initVariables();
    this->initWindow();
    this->initSound ();
    //this->initVehicle();
    //this->player = getPlayer();
    //this->player->resetPlayer();
    this->player = nullptr;
    level = 0;
    this->cgui = new CGUI(window->getSize().x, window->getSize().y);
}

void CGAME::drawGame() {

}

CGAME::~CGAME() {
    delete window;
    delete player;
}

// CALLED FROM:
// ---  START GAME  ---
// newPlayer is passed in as true. Check gender if config file. If no gender exists, it prompts user
// to select gender. Then create a new player and reset to beginning position.
// ---  LOAD GAME  ---
// newPlayer is false. Read config file and create new player.

CPEOPLE* CGAME::getPlayer(bool newPlayer) {
    fstream playerConfig("game_log/player.txt");
    if (!playerConfig) {
        cout << "No player file" << endl;
        return nullptr;
    }
    int gender, side, index, score, level;
    float x, y;

    if (newPlayer) {
        if (playerConfig.eof()) {
            // TODO: PROMPT CHOOSE GENDER
            gender = 0;
            playerConfig << gender;
            playerConfig.close();
        }
        else {
            playerConfig >> gender;
            playerConfig.close();
            clearSavedGame();
        }
        
        CPEOPLE* p = new CPEOPLE(this->window, gender);
        p->resetPlayer();
        return p;
    }

    playerConfig >> gender >> side >> index >> score >> level >> x >> y;
    playerConfig.close();
    this->score = score;
    this->level = level;
    CPEOPLE* player = new CPEOPLE(this->window, gender, side, x, y, index);
    player->score = score;
    return player;
}

COBJECT* CGAME::getVehicle() {
    return nullptr;
}

//COBJECT* CGAME::getAnimal() {
//    return nullptr;
//}

void CGAME::resetGame() {
    if (player == nullptr)
        player = getPlayer(true);
    else
        player->resetPlayer();
    clearSavedGame();
    level = 0;
    initLanes();
}

void CGAME::exitGame(HANDLE) {

}

void CGAME::startGame() {

}

bool CGAME::loadGame() {
    if (player != nullptr)
        delete player;
    ifstream infile("game_log/game.txt");
    if (!infile.is_open()) {
        cout << "Load file not found. Error." << endl;
        return false;
    }
    for (CLANE*& lane : lanes)
        if (lane != nullptr)
            delete lane;
    lanes.clear();
    
    int index;
    string textureFile, texture;
    float x = -1e9, y = -1e9, cX = -1e9, cY = -1e9, speed = -1e9;
    CLANE* lane = nullptr;
    COBJECTFACTORY* factory = nullptr;
    while (infile >> index >> textureFile) {
        if (textureFile != "none") {
            infile >> x >> y >> speed;
            if (textureFile[0] == 'a')
                factory = new CANIMALFACTORY();
            else
                factory = new CCARFACTORY();
        }
        else
            factory = new CGRASSFACTORY();
        infile >> texture;
        if (texture != "none")
            infile >> cX >> cY;
        lane = new CLANE(index, this->window, factory, textureFile, x, y, speed, cX, cY);
        lanes.push_back(lane);
    }

    if (lanes.empty())
        resetGame();
    else 
        player = getPlayer();

    infile.close();

    cout << "Load successfully" << endl;
    return true;
}

void CGAME::clearSavedGame() {
    ofstream clear("game_log/game.txt");
    clear.close();
    ifstream playerConfig("game_log/player.txt");
    int gender;
    playerConfig >> gender;
    playerConfig.close();
    ofstream playerClear("game_log/player.txt");
    playerClear << gender << endl;
    playerClear.close();
}

bool CGAME::saveGame() {
    player->savePlayer(score, level);
    ofstream outfile("game_log/game.txt");
    if (!outfile.is_open()) {
        cout << "Save file not found. Error." << endl;
        return false;
    }

    for (CLANE*& lane : lanes)
        lane->saveLane(outfile);

    outfile.close();
    cout << "Saved successfully" << endl;
    return true;
}

void CGAME::pauseGame(HANDLE) {

}

void CGAME::resumeGame(HANDLE) {

}

void CGAME::updatePosPeople(char) {

}

void CGAME::updateSound() {
    //int r = rand() % 30 + 1;
    //if ((int)clock.getElapsedTime().asSeconds() % 5 == 0) soundManager->playBackgroundSound();
}

void CGAME::updateLanes() {
    //srand(time(NULL));
    for (deque<CLANE*>::iterator it = lanes.begin(); it != lanes.end(); it++)
        if ((*it)->updatePosObject(level/5+1, level/5+1, *window, *player, *traffic, level) == 0) {
           gameState = GAME_STATE::GAMEOVER;
           cgui->isPause = true;
           cgui->drawGameOverGUI(score, level, window);
        };
    this->score = player->score;
}

void CGAME::createNewLane(int index, int level) {
    // We want 30% for animals, 60% for cars and 10% for grass.
    int k = rand() % 100;

    CLANE* lane;
    if (index == 7 || k < 10) // Initially, players always stand on grass
        lane = new CLANE(index, new CGRASSFACTORY(), window, true, level);
    else if (k < 40)
        lane = new CLANE(index, new CANIMALFACTORY(), window, level);
    else
        lane = new CLANE(index, new CCARFACTORY(), window, level);

    lanes.push_back(lane);
}

void CGAME::shiftLanesUp() {
    CTRANSITION::offset().reset();

    //cout << "Called" << endl;
    for (auto it = lanes.begin(); it != lanes.end(); ++it) {
        (*it)->shiftLane();
    }
    CLANE* lane = lanes.front();
    delete lane;
    lanes.pop_front();
    /*lane = new CLANE(0, new CCARFACTORY(), window);
    lanes.push_back(lane);*/
    createNewLane(0, level);
}

void CGAME::initLanes() {
    for (int i = 0; i < lanes.size(); ++i) {
        if (lanes[i] != nullptr) delete lanes[i];
    }
    lanes.clear();


    CLANE* lane;
    for (int i = 0; i < Constants::GetInstance().MAX_NUMBER_OF_LANES; i++) {
        createNewLane(i-10, level);
    }
}

bool CGAME::checkMove(CLANE* lane, CPEOPLE* player, int direction) {
    float coordX = player->mX, coordY = player->mY;
    switch (direction) {
    case 1:
        // up
        coordX += Constants::GetInstance().PLAYER_STEP * cos(Constants::GetInstance().BETA);
        coordY += -Constants::GetInstance().PLAYER_STEP * sin(Constants::GetInstance().BETA);
        break;
    case 2:
        // left
        coordX += -Constants::GetInstance().PLAYER_STEP_HORIZONTAL * cos(Constants::GetInstance().ALPHA);
        coordY += -Constants::GetInstance().PLAYER_STEP_HORIZONTAL * sin(Constants::GetInstance().ALPHA);
        break;
    case 3:
        // right
        coordX += Constants::GetInstance().PLAYER_STEP_HORIZONTAL * cos(Constants::GetInstance().ALPHA);
        coordY += Constants::GetInstance().PLAYER_STEP_HORIZONTAL * sin(Constants::GetInstance().ALPHA);
        break;
    case 4:
        // down
        coordX += -Constants::GetInstance().PLAYER_STEP * cos(Constants::GetInstance().BETA);
        coordY += Constants::GetInstance().PLAYER_STEP * sin(Constants::GetInstance().BETA);
        break;

    }
    int padding = 10;
    for (int i = 0; i < lane->blocks.size(); ++i) {
        if (coordX >= lane->blocks[i]->sprite.getGlobalBounds().left - 20 && coordX <= lane->blocks[i]->sprite.getGlobalBounds().left
            + lane->blocks[i]->sprite.getGlobalBounds().width - padding) return false;
    }
    return true;
}

CLANE* CGAME::findLane(int index) {
    for (auto it = lanes.begin(); it != lanes.end(); ++it) {
        if ((*it)->index == index) return (*it);
    }
}

void CGAME::initSound() {
    this->soundFactory = new CSOUNDFACTORY ();
}

void CGAME::drawBackground(const string& backgroundIMG) {
    if (!texture.loadFromFile(backgroundIMG)) {
        return;
    }
    texture.setSmooth(true);
    background.setTexture(texture);
    resizeImage(background);

}


void CGAME::update() {
    this->pollEvents();
}

void CGAME::render() {
    window->clear();
    sprites.clear();
    window->draw(background);
    switch (gameState) {
    case GAME_STATE::MENU: {

        //window->draw(background);

        menu->draw(*window);
        break;
    }
    case GAME_STATE::LEVEL_1: {
        CTRANSITION::offset().update();
        updateLanes();
        traffic->drawTraffic(window);
        //updatePosVehicle();
        //updatePosAnimal();
        if (!isGameOver) {
            player->render();
        }
        cgui->drawGUI(score, level, window);

        //for (int i = 0; i < sprites.size(); ++i) window->draw(sprites[i]);
        break;
    }
    case GAME_STATE::PAUSE: {
        //cout << "Is pausing" << endl;
        cgui->drawGUI(score, level, window);
    }
    case GAME_STATE::GAMEOVER: {
        //cout << "Is pausing" << endl;
        cgui->drawGUI(score, level, window);
    }
    default: {
        break;
    }
    }


    window->display();
}

void CGAME::initVariables() {
    this->window = nullptr;
    //srand(time(NULL));
    traffic = new CTRAFFIC(0);

    //vehicles.assign(rowCount, vector<CVEHICLE*>(maxVehicle, nullptr));
}
void CGAME::initWindow() {
    GetDesktopResolution();
    this->window = new sf::RenderWindow(this->videoMode, "Crossy Road");
    window->setFramerateLimit(Constants::GetInstance().FPS);
    menu = new Menu(window->getSize().x, window->getSize().y);
    drawBackground("assets/graphics/menu.jpg");

}

void CGAME::GetDesktopResolution()
{
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    videoMode.width = 432;
    videoMode.height = 768;
}

const bool CGAME::running() const {
    return this->window->isOpen();
}

void CGAME::pollEvents() {
    while (window->pollEvent(event)) {
        
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            switch (event.key.code) {
            case sf::Keyboard::Escape:
                window->close();
                break;
            case sf::Keyboard::Up:
                soundFactory->playSound (2);
                cout << "Pressed" << endl;
                if (gameState == GAME_STATE::MENU)
                    menu->MoveUp();
                else if (gameState == GAME_STATE::PAUSE || gameState == GAME_STATE::GAMEOVER)
                    cgui->MoveUp();
                else {
                    player->setSide(CPEOPLE::UP);
                    
                    if (player->canMoveUp() && checkMove(findLane(player->index-1), player, 1))
                        player->moveUp(), level++;
                    else if (checkMove(findLane(player->index - 1), player, 1)) {
                        level++;
                        shiftLanesUp();
                    }
                }
                break;
            case sf::Keyboard::Down:
                soundFactory->playSound (2);
                if (gameState == GAME_STATE::MENU)
                    menu->MoveDown();
                else if (gameState == GAME_STATE::PAUSE || gameState == GAME_STATE::GAMEOVER)
                    cgui->MoveDown();
                else {
                    player->setSide(CPEOPLE::DOWN);
                    
                    if (player->canMoveDown() && checkMove(findLane(player->index + 1), player, 4))
                        player->moveDown(), level--;
                }
                break;
            case sf::Keyboard::Left:
                soundFactory->playSound (2);
                player->setSide(CPEOPLE::LEFT);
                
                if (player->canMoveLeft() && checkMove(findLane(player->index), player, 2))
                    player->moveLeft();
                break;
            case sf::Keyboard::Right:
                soundFactory->playSound (2);
                player->setSide(CPEOPLE::RIGHT);
                
                if (player->canMoveRight() && checkMove(findLane(player->index), player, 3))
                    player->moveRight();
                break;
            case sf::Keyboard::Return:
                if (gameState == GAME_STATE::MENU)
                    switch (menu->getPressedItem()) {
                    case 0:
                        // Clear saved stuff when start new game.
                        clearSavedGame();

                        cout << "Started the game" << endl;
                        this->initLanes();
                        soundFactory->playSound(1);
                        this->player = getPlayer(true);
                        level = 0;
                        gameState = GAME_STATE::LEVEL_1;
                        break;
                    case 1:
                        cout << "Load the game" << endl;
                        loadGame();
                        soundFactory->playSound(1);
                        gameState = GAME_STATE::LEVEL_1;
                        break;
                    case 2:
                        cout << "Exited the game" << endl;
                        window->close();
                        break;
                    }
                else if (gameState == GAME_STATE::PAUSE) {
                    soundFactory->playSound (2);
                    string file = "";
                    switch (cgui->getPressedItem()) {
                    case 2:
                        cout << "Save and exit" << endl;
                        saveGame();
                        gameState = GAME_STATE::MENU;
                        break;
                    case 1:
                        cout << "Restart game." << endl;
                        gameState = GAME_STATE::LEVEL_1;
                        resetGame();
                        break;
                    case 0:
                        cout << "Continued the game..." << endl;
                        gameState = GAME_STATE::LEVEL_1;
                        break;
                    }
                    cgui->isPause = false;
                }
                else if (gameState == GAME_STATE::GAMEOVER) {
                    // Clear saved stuff when gameover.
                    clearSavedGame();

                    string file = "";
                    // soundFactory->playSound (4);
                    switch (cgui->getPressedItem()) {
                    case 0:
                       // soundFactory->playSound (2);
                        cout << "Restarted the game" << endl;
                        gameState = GAME_STATE::LEVEL_1;
                        resetGame();
                        break;
                    case 1:
                       // soundFactory->playSound (2);
                        cout << "Exit to main menu" << endl;
                        gameState = GAME_STATE::MENU;
                        break;
                    }
                    cgui->isPause = false;
                }

            }
        case sf::Event::MouseButtonPressed:
            switch (event.mouseButton.button) {
            case sf::Mouse::Left: {
                soundFactory->playSound (2);
                cout << "Mouse clicked" << endl;
                if (cgui->GUICheck(event.mouseButton.x, event.mouseButton.y)) {
                    cout << "Paused the game" << endl;
                    gameState = GAME_STATE::PAUSE;
                    cgui->drawPauseGUI(score, level, window);
                    break;
                }

            }
            }
        }
       
    }
}
void CGAME::resizeImage(sf::Sprite& sprite) {
    sprite.scale((float)window->getSize().x / (float)sprite.getTexture()->getSize().x,
        (float)window->getSize().y / (float)sprite.getTexture()->getSize().y);
}
