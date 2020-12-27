#include "../include/CGAME.h"

CGAME::CGAME() {
    srand(time(NULL));
    this->initVariables();
    this->initWindow();
    this->initVehicle();
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

COBJECT* CGAME::getAnimal() {
    return nullptr;
}

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
            vehicles[i]->update(1, 0, *window, vehicles);
            //cout << "Moving" << endl;
        }
    }
}

void CGAME::updatePosAnimal() {
    srand(time(NULL));
    for (int i = 0; i < animals.size(); ++i) {
        if (animals[i] != nullptr) {
            animals[i]->update(1, 0, *window, animals);
            //cout << "Moving" << endl;
        }
    }
}

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
        updatePosVehicle();
        updatePosAnimal();
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
    for (int i = 0; i < Constants::GetInstance().MAX_NUMBER_OF_LANES; ++i) {
        traffics.push_back(CTRAFFIC(rand() % 10 + 1));
    }
    //vehicles.assign(rowCount, vector<CVEHICLE*>(maxVehicle, nullptr));
}
void CGAME::initWindow() {
    GetDesktopResolution();
    this->window = new sf::RenderWindow(this->videoMode, "Crossy Road");
    //window->setFramerateLimit(60);
    menu = new Menu(window->getSize().x, window->getSize().y);
    drawBackground("menu.jpg");

}

void CGAME::GetDesktopResolution()
{
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    videoMode.width = desktop.right;
    videoMode.height = desktop.bottom;
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
        for (int j = 0; j < Constants::GetInstance().MAX_NUMBER_OF_VEHICLES_EACH_LANE; ++j) {

            // random create objects in lane
            int choice = rand() % 4;
            if (choice % 4 == 0) {
                v = new CCAR(Constants::GetInstance().DISTANCE_BETWEEN_OBSTACLES * j
                    + rand() % 100 - 50, Constants::GetInstance().DISTANCE_BETWEEN_LANES * i
                    + Constants::GetInstance().PADDING_TOP);
                vehicles.push_back(v);
            }
            else if (choice % 4 == 1) {
                v = new CDINAUSOR(Constants::GetInstance().DISTANCE_BETWEEN_OBSTACLES * j
                    + rand() % 100 - 50, Constants::GetInstance().DISTANCE_BETWEEN_LANES * i
                    + Constants::GetInstance().PADDING_TOP);
                animals.push_back(v);
            }
            else if (choice % 4 == 2) {
                v = new CTRUCK(Constants::GetInstance().DISTANCE_BETWEEN_OBSTACLES * j 
                    + rand() % 100 - 50, Constants::GetInstance().DISTANCE_BETWEEN_LANES * i
                    + Constants::GetInstance().PADDING_TOP);
                vehicles.push_back(v);
            }
            else if (choice % 4 == 3) {
                v = new CBIRD(Constants::GetInstance().DISTANCE_BETWEEN_OBSTACLES * j
                    + rand() % 100 - 50, Constants::GetInstance().DISTANCE_BETWEEN_LANES * i
                    + Constants::GetInstance().PADDING_TOP);
                animals.push_back(v);
            }
        }
    }
}

void CGAME::resizeImage(sf::Sprite& sprite) {
    sprite.scale((float)window->getSize().x / (float)sprite.getTexture()->getSize().x,
        (float)window->getSize().y / (float)sprite.getTexture()->getSize().y);
}