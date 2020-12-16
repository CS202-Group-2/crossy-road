#include "../include/CGAME.h"



CGAME::CGAME() {
    this->initVariables();
    this->initWindow();
    this->initVehicle();
}

void CGAME::drawGame() {

}

CGAME::~CGAME() {
    delete window;

}

CPEOPLE CGAME::getPeople() {
    return CPEOPLE();
}

CVEHICLE* CGAME::getVehicle() {
    return nullptr;
}

CANIMAL* CGAME::getAnimal() {
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

void CGAME::updatePosVehicle() {
    srand(time(NULL));
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < maxVehicle; ++j) {
            if (vehicles[i][j] != nullptr) {
                vehicles[i][j]->move(vehicles[i][j]->mX, vehicles[i][j]->mY);
                
                if (!texture.loadFromFile("image.jpg")) {
                    cout << "Not found! " << endl;
                }
                sf::Sprite sprite;
                sprite.setPosition(vehicles[i][j]->mX, vehicles[i][j]->mY);
                //sprite.setSize(sf::Vector2f(20.f, 20.f));
                sprite.setScale(sf::Vector2f(0.2f, 0.2f));
                sprite.rotate(-90);
                //sprite.setOutlineThickness(1.f);
                sprite.setTexture(texture);
                sprites.push_back(sprite);
            }
        }
    }
}

void CGAME::updatePosAnimal() {
    
}

void CGAME::update() {
    this->pollEvents();
}

void CGAME::render() {
    window->clear();
    sprites.clear();
    updatePosVehicle();
    for (int i = 0; i < sprites.size(); ++i) window->draw(sprites[i]);
    window->display();
}

void CGAME::initVariables() {
    this->window = nullptr;
    vehicles.assign(rowCount, vector<CVEHICLE*>(maxVehicle, nullptr));

}
void CGAME::initWindow() {
    GetDesktopResolution();
    this->window = new sf::RenderWindow(this->videoMode, "Crossy Road");
    window->setFramerateLimit(60);
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
    while (window->pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::Closed: {
                window->close();
                break;
            }
            case sf::Event::KeyPressed: {
                if (event.key.code == sf::Keyboard::Escape)
                    window->close();
                break;
            }
        }

    }
}

void CGAME::initVehicle() {
    
    for (int i = 0; i < rowCount; ++i) {
        vehicles[i][1] = new CTRUCK(0, 100*i);
    }
    
}