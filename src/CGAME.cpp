#include "../include/CGAME.h"

CGAME::CGAME() {
    srand(time(NULL));
    this->initVariables();
    this->initWindow();
    this->initLanes();
    //this->initVehicle();
    this->player = getPlayer();
}

void CGAME::drawGame() {

}

CGAME::~CGAME() {
    delete window;
    player->savePlayer();
    delete player;
}

CPEOPLE* CGAME::getPlayer() {
    ifstream playerConfig("game_log/player.txt");
    if (!playerConfig)
        return new CPEOPLE(this->window, CPEOPLE::UP);
    int gender, side;
    double x, y;
    playerConfig >> gender >> side >> x >> y;
    playerConfig.close();
    return new CPEOPLE(this->window, gender, side, x, y);
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

void CGAME::loadGame(istream&) {

}

void CGAME::saveGame(istream&) {

}

void CGAME::pauseGame(HANDLE) {

}

void CGAME::resumeGame(HANDLE) {

}

void CGAME::updatePosPeople(char) {

}

void CGAME::updateLanes() {
    srand(time(NULL));
    for (deque<CLANE*>::iterator it = lanes.begin(); it != lanes.end(); it++)
        (*it)->updatePosObject(1, 1, *window, *player, *traffic);
}

void CGAME::initLanes() {
    CLANE* lane;
    for (int i = 0; i < Constants::GetInstance().MAX_NUMBER_OF_LANES; i++) {
        lane = new CLANE(i, new CCARFACTORY(), window);
        lanes.push_back(lane);
    }
}

void CGAME::drawBackground(const string& backgroundIMG) {
    if (!texture.loadFromFile(backgroundIMG)) {
        return;
    }
    background.setTexture(texture);
    resizeImage(background);

}


void CGAME::updatePosVehicle() {
    srand(time(NULL));
    for (int i = 0; i < vehicles.size(); ++i) {
        if (vehicles[i] != nullptr) {
            //vehicles[i]->update(1,1, *window, vehicles, *player);
            if (vehicles[i]->checkOutWindow (*window) == 1) {
                float temp = vehicles[i]->initY;
                delete vehicles[i];
                vehicles[i] = new CCAR(-100, temp);
            }
        }
    }
    for (int i = 0; i < lanes.size(); ++i) {
        
    }
}
/*
void CGAME::updatePosAnimal() {
    srand(time(NULL));
    for (int i = 0; i < animals.size(); ++i) {
        if (animals[i] != nullptr) {
            animals[i]->update(1, 1, *window, animals, *player);
            //cout << "Moving" << endl;
        }
    }
}*/

void CGAME::update() {
    this->pollEvents();
}

void CGAME::render() {
    window->clear();
    sprites.clear();

    switch (gameState) {
    case GAME_STATE::MENU: {
        sf::RectangleShape rectangle(sf::Vector2f(250, 350));
        rectangle.setOrigin(rectangle.getLocalBounds().left + rectangle.getLocalBounds().width / 2,
            rectangle.getLocalBounds().top + rectangle.getLocalBounds().height / 2);
        rectangle.setPosition(window->getSize().x / 2, (window->getSize().y - menu->titlePadding) / 2 + menu->titlePadding);
        rectangle.setFillColor(sf::Color(0, 0, 0, 200));

        window->draw(background);
        window->draw(rectangle);
        menu->draw(*window);
        break;
    }
    case GAME_STATE::LEVEL_1: {
        srand(time(NULL));
        window->draw(background);
        updateLanes();
        traffic->drawTraffic(window);
        //updatePosVehicle();
        //updatePosAnimal();
        player->render();

        for (int i = 0; i < sprites.size(); ++i) window->draw(sprites[i]);
        break;
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
                else {
                    player->setSide(CPEOPLE::UP);
                    if (player->canMoveUp())
                        player->moveUp();
                }
                break;
            case sf::Keyboard::Down:
                if (gameState == GAME_STATE::MENU)
                    menu->MoveDown();
                else {
                    player->setSide(CPEOPLE::DOWN);
                    if (player->canMoveDown())
                        player->moveDown();
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
            }
        }
    }
}

void CGAME::initVehicle() {

    COBJECT* v = nullptr;
    
    for (int i = 0; i < Constants::GetInstance().MAX_NUMBER_OF_LANES; ++i) {
        sf::Sprite laneBackground;
        if (!textureRoad.loadFromFile("Road.png")) {
            return;
        }
        laneBackground.setTexture(textureRoad);
        double scaleX = (window->getSize().x * 2 + 100) / laneBackground.getGlobalBounds().width;
        laneBackground.setScale(scaleX, scaleX);
        //double scaleY = 100 / laneBackground.getGlobalBounds().height;
       // laneBackground.setScale(scaleY, scaleY);
        laneBackground.setPosition(0, (i-1)*Constants::GetInstance().LANE_WIDTH);



        for (int j = 0; j < Constants::GetInstance().MAX_NUMBER_OF_VEHICLES_EACH_LANE; ++j) {

            // random create objects in lane
            
            v = new CCAR(-100, (i-1) * Constants::GetInstance().LANE_WIDTH + 25);
            vehicles.push_back(v);
            
   
        }
    }
}

void CGAME::resizeImage(sf::Sprite& sprite) {
    sprite.scale((float)window->getSize().x / (float)sprite.getTexture()->getSize().x,
        (float)window->getSize().y / (float)sprite.getTexture()->getSize().y);
}