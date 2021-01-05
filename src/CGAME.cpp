#include "../include/CGAME.h"

CGAME::CGAME() {
    srand(time(NULL));
    this->initVariables();
    this->initWindow();
    this->soundManager = new CSOUND();
    //this->initVehicle();
    this->player = getPlayer();
    this->player->resetPlayer();
    level = 0;
    this->cgui = new CGUI(window->getSize().x, window->getSize().y);
    
}

void CGAME::drawGame() {

}

CGAME::~CGAME() {
    delete window;
    player->savePlayer(score, level);
    delete player;
}

CPEOPLE* CGAME::getPlayer() {
    ifstream playerConfig("game_log/player.txt");
    if (!playerConfig)
        return new CPEOPLE(this->window, CPEOPLE::UP);
    int gender, side, index, score, level;
    double x, y;
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

}

void CGAME::exitGame(HANDLE) {

}

void CGAME::startGame() {

}

bool CGAME::loadGame(string loadFile) {
    ifstream infile(loadFile);
    if (!infile.is_open()) {
        cout << "Load file not found. Error." << endl;
        return false;
    }

    // TODO: implement loading parametres
    cout << "Load successfully" << endl;
    return true;
}

bool CGAME::saveGame(string saveFile) {
    ofstream outfile(saveFile);
    if (!outfile.is_open()) {
        cout << "Save file not found. Error." << endl;
        return false;
    }

    // TODO: implement saving parametres
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
    srand(time(NULL));
    for (deque<CLANE*>::iterator it = lanes.begin(); it != lanes.end(); it++)
        if ((*it)->updatePosObject(level/10+1, level/10+1, *window, *player, *traffic) == false) {
           gameState = GAME_STATE::GAMEOVER;
           cgui->isPause = true;
           cgui->drawGameOverGUI(score, level, window);
        };
    this->score = player->score;
}

void CGAME::shiftLanesUp() {
    //cout << "Called" << endl;
    for (auto it = lanes.begin(); it != lanes.end(); ++it) {
        (*it)->shiftLane();
    }
    CLANE* lane = lanes.front();
    delete lane;
    lanes.pop_front();
    lane = new CLANE(0, new CCARFACTORY(), window);
    lanes.push_back(lane);
}

void CGAME::initLanes() {
    for (int i = 0; i < lanes.size(); ++i) {
        if (lanes[i] != nullptr) delete lanes[i];
    }
    lanes.clear();
    CLANE* lane;
    for (int i = 0; i < Constants::GetInstance().MAX_NUMBER_OF_LANES; i++) {
        lane = new CLANE(i-10, new CCARFACTORY(), window);
        lanes.push_back(lane);
    }
}

void CGAME::initSound() {
    soundManager->playBackgroundSound();
}

void CGAME::drawBackground(const string& backgroundIMG) {
    if (!texture.loadFromFile(backgroundIMG)) {
        return;
    }
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
        srand(time(NULL));
        
        
        updateLanes();
        updateSound();
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
    srand(time(NULL));
    traffic = new CTRAFFIC(0);

    //vehicles.assign(rowCount, vector<CVEHICLE*>(maxVehicle, nullptr));
}
void CGAME::initWindow() {
    GetDesktopResolution();
    this->window = new sf::RenderWindow(this->videoMode, "Crossy Road");
    window->setFramerateLimit(30);
    menu = new Menu(window->getSize().x, window->getSize().y);
    drawBackground("menu.jpg");

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
                cout << "Pressed" << endl;
                if (gameState == GAME_STATE::MENU)
                    menu->MoveUp();
                else if (gameState == GAME_STATE::PAUSE || gameState == GAME_STATE::GAMEOVER)
                    cgui->MoveUp();
                else {
                    player->setSide(CPEOPLE::UP);
                    if (player->canMoveUp())
                        player->moveUp(), level++;
                    else {
                        level++;
                        shiftLanesUp();
                    }
                }
                break;
            case sf::Keyboard::Down:
                if (gameState == GAME_STATE::MENU)
                    menu->MoveDown();
                else if (gameState == GAME_STATE::PAUSE || gameState == GAME_STATE::GAMEOVER)
                    cgui->MoveDown();
                else {
                    player->setSide(CPEOPLE::DOWN);
                    if (player->canMoveDown())
                        player->moveDown(), level--;
                }
                break;
            case sf::Keyboard::Left:
                player->setSide(CPEOPLE::LEFT);
                if (player->canMoveLeft())
                    player->moveLeft();
                break;
            case sf::Keyboard::Right:
                player->setSide(CPEOPLE::RIGHT);
                if (player->canMoveRight())
                    player->moveRight();
                break;
            case sf::Keyboard::Return:
                if (gameState == GAME_STATE::MENU)
                    switch (menu->getPressedItem()) {
                    case 0:
                        cout << "Started the game" << endl;
                        this->initLanes();
                        
                        this->initSound();
                        
                        gameState = GAME_STATE::LEVEL_1;
                        break;
                    case 1:
                        cout << "Load the game" << endl;
                        break;
                    case 2:
                        cout << "Exited the game" << endl;
                        window->close();
                        break;
                    }
                else if (gameState == GAME_STATE::PAUSE) {
                    string file = "";
                    switch (cgui->getPressedItem()) {
                    case 0:
                        cout << "Exited to main menu" << endl;
                        gameState = GAME_STATE::MENU;
                        break;
                    case 1:
                        cout << "Saving the game..." << endl;
                        cout.flush();
                        cin.clear();
                        cout << "Please input the file to save your progress: ";
                        getline(cin, file);
                        saveGame(file);
                        gameState = GAME_STATE::LEVEL_1;
                        break;
                    case 2:
                        cout << "Loading the game..." << endl;
                        cout.flush();
                        cin.clear();
                        cout << "Please input the file to load your progress: ";
                        getline(cin, file);
                        loadGame(file);
                        gameState = GAME_STATE::LEVEL_1;
                        break;
                    case 3:
                        cout << "Continued the game..." << endl;
                        gameState = GAME_STATE::LEVEL_1;
                        break;
                    }
                    cgui->isPause = false;
                }
                else if (gameState == GAME_STATE::GAMEOVER) {
                    string file = "";
                    switch (cgui->getPressedItem()) {
                    case 0:
                        cout << "Restarted the game" << endl;
                        gameState = GAME_STATE::LEVEL_1;
                        delete player;
                        this->player = getPlayer();
                        this->player->resetPlayer();
                        level = 0;
                        initLanes();
                        break;
                    case 1:
                        cout << "Loading the game..." << endl;
                        cout.flush();
                        cin.clear();
                        cout << "Please input the file to load your progress: ";
                        getline(cin, file);
                        loadGame(file);
                        gameState = GAME_STATE::LEVEL_1;
                        break;
                    }
                    cgui->isPause = false;
                }
                    
            }
        case sf::Event::MouseButtonPressed:
            switch (event.mouseButton.button) {
            case sf::Mouse::Left: {
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