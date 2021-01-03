#pragma once

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/Constants.h"

using namespace std;

class CGUI {
private:
    friend class CGAME;
    bool isPause = false, drawn = false;
    sf::Sprite pauseButton;
    sf::Texture pauseButtonTexture;
	sf::Font font;
    sf::Text scoreText;
    sf::Text levelText;
    sf::Text gameOverText;
	vector<sf::Text> options;
	int selectedItemIndex = 0;
    float width, height;

public:
    CGUI(float width, float height);
	~CGUI();
    void drawGUI(int score, int level, sf::RenderWindow *window);
    void drawGameOverGUI(int score, int level, sf::RenderWindow* window);
    void drawPauseGUI(int score, int level, sf::RenderWindow* window);
    int GUICheck(float x, float y); // 1: pause menu, 0: play, -1: quit
    void drawGUIText(int score, int level, sf::RenderWindow* window);
    void drawGameOverText(sf::RenderWindow* window);
	void MoveUp();
	void MoveDown();
	int getPressedItem();
    

};