#include "../include/CPEOPLE.h"

int CPEOPLE::RIGHT = 0, CPEOPLE::UP = 1, CPEOPLE::LEFT = 2, CPEOPLE::DOWN = 3;
int CPEOPLE::MALE = 0, CPEOPLE::FEMALE = 1;
int CPEOPLE::FIG_WIDTH = 167, CPEOPLE::FIG_HEIGHT = 373;
double CPEOPLE::FIG_SCALE = 0.2;
double CPEOPLE::MOVEABLE_DIST = 600;

//double CPEOPLE::ALPHA = 30 * 3.14 / 180, CPEOPLE::BETA = 40 * 3.14 / 180;
//double CPEOPLE::PLAYER_STEP = 5;

CPEOPLE::CPEOPLE(sf::RenderWindow* window, int gender, int side, int x, int y, int index) {
    setGender(gender);
    mSprite.setTexture(mTexture);
    mSprite.setScale(FIG_SCALE, FIG_SCALE);
    if (x != -1)
        mSprite.setPosition(x, y);
    else
        mSprite.setPosition(window->getSize().x / 2, window->getSize().y - FIG_HEIGHT * FIG_SCALE);
    setSide(side);
    mWindow = window;
    this->index = index;
}

bool CPEOPLE::canMoveDown() {
    // In moving down, we must decrease x and increase y with respect to BETA.
    bool canDecreaseX = (mSprite.getGlobalBounds().left - Constants::GetInstance().PLAYER_STEP * cos(Constants::GetInstance().BETA) >= 0);

    bool canIncreaseY = (
        (double)mSprite.getGlobalBounds().top
        + (double)mSprite.getGlobalBounds().height
        + Constants::GetInstance().PLAYER_STEP * sin(Constants::GetInstance().BETA)
        <= mWindow->getSize().y
        );

    return canDecreaseX && canIncreaseY;
}

bool CPEOPLE::canMoveUp() {
    // The character only moves up when the distance between the character and the bottom
    // has not exceeded MOVEABLE_DIST.
    // Otherwise, other figures in the screen will move down and player stays still.
    bool isInMovableDist = (mWindow->getSize().y - mSprite.getGlobalBounds().top) <= MOVEABLE_DIST * sin(Constants::GetInstance ().BETA);

    return isInMovableDist;
}

bool CPEOPLE::canMoveRight() {
    // In moving right, we must increase x and increase y with respect to ALPHA.
    bool canIncreaseX = (
        (double)mSprite.getGlobalBounds().left
        + (double)mSprite.getGlobalBounds().width
        + Constants::GetInstance ().PLAYER_STEP_HORIZONTAL * cos(Constants::GetInstance ().ALPHA)
        <= mWindow->getSize().x
        );

    bool canIncreaseY = (
        mSprite.getGlobalBounds().top
        + mSprite.getGlobalBounds().height
        + Constants::GetInstance ().PLAYER_STEP_HORIZONTAL * sin(Constants::GetInstance ().ALPHA)
        <= mWindow->getSize().y
        );

    return canIncreaseX && canIncreaseY;
}

bool CPEOPLE::canMoveLeft() {
    // In moving left, we must decrease x and decrease y with respect to ALPHA.
    bool canDecreaseX = (mSprite.getGlobalBounds().left - Constants::GetInstance ().PLAYER_STEP_HORIZONTAL * cos(Constants::GetInstance ().ALPHA) >= 0);

    bool canDecreaseY = (mSprite.getGlobalBounds().top - Constants::GetInstance ().PLAYER_STEP_HORIZONTAL * sin(Constants::GetInstance ().ALPHA) >= 0);

    return canDecreaseX && canDecreaseY;
}

void CPEOPLE::setGender(int gender) {
    this->gender = gender;
    // Get the corresponding texture.
    if (gender == MALE)
        mTexture.loadFromFile("assets/player/boy.png");
    else
        mTexture.loadFromFile("assets/player/girl.png");
}

void CPEOPLE::setSide(int side) {
    // Move the rectangle to the corresponding figure.
    this->side = side;
    mSprite.setTextureRect(sf::IntRect(FIG_WIDTH * side, 0, FIG_WIDTH, FIG_HEIGHT));
}

void CPEOPLE::render() {
    mWindow->draw(mSprite);
   // cout << mSprite.getGlobalBounds ().height << endl;
  //  cout << mSprite.getGlobalBounds ().width << endl;
  //  cout << mSprite.getGlobalBounds ().top << endl;
  //  cout << mSprite.getGlobalBounds ().left << endl;
    /*
    167.85
75.15
373
265
    */
    /*
    373
167
0
0
    */

}

void CPEOPLE::moveUp() {
    cout << "up\n";
    // Increase x and decrease y with respect to BETA.
    mSprite.move(Constants::GetInstance().PLAYER_STEP * cos(Constants::GetInstance ().BETA), -Constants::GetInstance ().PLAYER_STEP * sin(Constants::GetInstance ().BETA));
    index--;
}

void CPEOPLE::moveLeft() {
    cout << "left\n";
    // Decrease x and Decrease y with respect to ALPHA.
    mSprite.move(-Constants::GetInstance().PLAYER_STEP_HORIZONTAL * cos(Constants::GetInstance ().ALPHA), -Constants::GetInstance ().PLAYER_STEP_HORIZONTAL * sin(Constants::GetInstance ().ALPHA));
}

void CPEOPLE::moveRight() {
    cout << "right\n";
    // Increase x and increase y with respect to ALPHA.
    mSprite.move(Constants::GetInstance().PLAYER_STEP_HORIZONTAL * cos(Constants::GetInstance ().ALPHA), Constants::GetInstance ().PLAYER_STEP_HORIZONTAL * sin(Constants::GetInstance ().ALPHA));
}

void CPEOPLE::moveDown() {
    cout << "down\n";
    // Decrease x and Increase y with respect to BETA.
    mSprite.move(-Constants::GetInstance().PLAYER_STEP * cos(Constants::GetInstance ().BETA), Constants::GetInstance ().PLAYER_STEP * sin(Constants::GetInstance ().BETA));
    index++;
}

//bool CPEOPLE::isImpact(const CVEHICLE*&) {
  //  return false;
//}

bool CPEOPLE::isImpact(const COBJECT*&) {
    return false;
}

bool CPEOPLE::isFinish() {
    return false;
}

bool CPEOPLE::isDead() {
    return false;
}

void CPEOPLE::resetPlayer() {
    gender = 0;
    side = 1;
    index = 8;
    mSprite.setPosition(91.905, 622.108);
}

void CPEOPLE::savePlayer(int score, int level) {
    ofstream playerConfig("game_log/player.txt");
    playerConfig << gender << "\n" << side << "\n" << index << "\n" << score << "\n" << level << "\n"
        << mSprite.getPosition().x << " " << mSprite.getPosition().y;
    playerConfig.close();
}