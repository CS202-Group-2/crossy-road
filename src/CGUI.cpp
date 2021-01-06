#include "../include/CGUI.h"
#include <iostream>
CGUI::CGUI(float width, float height) {
	this->width = width;
	this->height = height;
	if (!pauseButtonTexture.loadFromFile("assets/graphics/Pause.png")) {
		cout << "Cannot find texture file" << endl;
		return;
	}
	pauseButtonTexture.setSmooth(true);
	pauseButton.setTexture(pauseButtonTexture);
	pauseButton.setPosition(0, 0);
	pauseButton.setScale(0.2f, 0.2f);

}

void CGUI::drawGUI(int score, int level, sf::RenderWindow* window) {
	if (!isPause) {
		window->draw(pauseButton);
		// cout << score << " " << level << endl;
		drawGUIText(score, level, window);
		window->draw(levelText);
		window->draw(scoreText);
		return;
	}
	sf::RectangleShape rectangle(sf::Vector2f(300, 600));
	rectangle.setOrigin(rectangle.getLocalBounds().left + rectangle.getLocalBounds().width / 2,
		rectangle.getLocalBounds().top + rectangle.getLocalBounds().height / 2);
	rectangle.setPosition(window->getSize().x / 2, (window->getSize().y) / 2 );
	rectangle.setFillColor(sf::Color(0, 0, 0, 200));
	window->draw(rectangle);

	for (int i = 0; i < options.size(); ++i) {
		sf::FloatRect textRect = options[i].getLocalBounds();
		options[i].setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
		options[i].setPosition(sf::Vector2f(window->getSize().x / 2.0f,
			(window->getSize().y) / (options.size() + 1) * (i + 1)));
		window->draw(options[i]);
	}
	drawGUIText(score, level, window);
	window->draw(levelText);
	window->draw(scoreText);
}

void CGUI::drawGUIText(int score, int level, sf::RenderWindow* window) {
	if (!font.loadFromFile("arial.ttf")) {
		cout << "No font" << endl;
		std::cout << "Failed to load" << std::endl;
	}
	scoreText.setString("Score: " + to_string(score));
	levelText.setString("Steps: " + to_string(level));
	scoreText.setCharacterSize(15);
	levelText.setCharacterSize(15);
	scoreText.setColor(sf::Color::White);
	levelText.setColor(sf::Color::White);
	scoreText.setFont(font);
	levelText.setFont(font);

	sf::FloatRect textRect1 = scoreText.getLocalBounds();
	scoreText.setOrigin(textRect1.left + textRect1.width, textRect1.top);
	sf::FloatRect textRect2 = levelText.getLocalBounds();
	levelText.setOrigin(textRect2.left + textRect2.width, textRect2.top);

	scoreText.setPosition(sf::Vector2f(width - 10, 10));
	levelText.setPosition(sf::Vector2f(width - 10, 35));

	scoreText.setOutlineColor(sf::Color(0, 0, 0, 255));
	scoreText.setOutlineThickness(3);
	levelText.setOutlineColor(sf::Color(0, 0, 0, 255));
	levelText.setOutlineThickness(3);

	
	// cout << "drawn" << endl;
}

void CGUI::drawGameOverText(sf::RenderWindow* window) {
	scoreText.setCharacterSize(30);
	levelText.setCharacterSize(30);
	scoreText.setPosition(sf::Vector2f(window->getSize().x / 2.0f + 100, window->getSize().y / 2.0f));
	levelText.setPosition(sf::Vector2f(window->getSize().x / 2.0f - 100, window->getSize().y / 2.0f));
}

void CGUI::drawPauseGUI(int score, int level, sf::RenderWindow* window) {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Failed to load" << std::endl;
	}

	options.clear();
	options.assign(3, sf::Text());
	options[0].setFont(font);
	options[0].setColor(sf::Color::Yellow);
	options[0].setString("Continue");
	options[0].setCharacterSize (options[0].getCharacterSize () + 15);

	options[1].setFont(font);
	options[1].setColor(sf::Color::White);
	options[1].setString("Restart");
	//options[1].setPosition(sf::Vector2f(width / 2, height / (options.size() + 1) * 2));

	options[2].setFont(font);
	options[2].setColor(sf::Color::White);
	options[2].setString("Save and exit");
	//options[2].setPosition(sf::Vector2f(width / 2, height / (options.size() + 1) * 3));
	
	//options[3].setFont(font);
	//options[3].setColor(sf::Color::White);
	//options[3].setString("Continue");
	//options[3].setPosition(sf::Vector2f(width / 2, height / (options.size() + 1) * 4));
}

void CGUI::drawGameOverGUI(int score, int level, sf::RenderWindow* window) {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Failed to load" << std::endl;
	}
	options.clear();
	options.assign(2, sf::Text());

	options[0].setFont(font);
	options[0].setColor(sf::Color::Yellow);
	options[0].setString("Restart");
	options[0].setCharacterSize (options[0].getCharacterSize () + 15);

	options[1].setFont(font);
	options[1].setColor(sf::Color::White);
	options[1].setString("Back to main menu");

}

CGUI::~CGUI() {
	options.clear();

}

void CGUI::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		options[selectedItemIndex--].setColor(sf::Color::White);
		options[selectedItemIndex].setColor(sf::Color::Yellow);
		options[selectedItemIndex].setCharacterSize (options[selectedItemIndex].getCharacterSize () + 15);
		options[selectedItemIndex + 1].setCharacterSize (options[selectedItemIndex].getCharacterSize () - 15);
	}
	else {
		options[selectedItemIndex].setColor(sf::Color::White);
		options[(int)options.size() - 1].setColor(sf::Color::Yellow);
		options[(int)options.size() - 1].setCharacterSize (options[(int)options.size () - 1].getCharacterSize () + 15);
		options[0].setCharacterSize (options[0].getCharacterSize () - 15);
		selectedItemIndex = (int)options.size() - 1;
	}
	//options[selectedItemIndex].setCharacterSize (options[selectedItemIndex].getCharacterSize () - 15);
}

void CGUI::MoveDown() {
	if (selectedItemIndex + 1 < (int)options.size()) {
		options[selectedItemIndex++].setColor(sf::Color::White);
		options[selectedItemIndex].setColor(sf::Color::Yellow);
		options[selectedItemIndex].setCharacterSize (options[selectedItemIndex].getCharacterSize () + 15);
		options[selectedItemIndex-1].setCharacterSize (options[selectedItemIndex].getCharacterSize () - 15);
	}
	else {
		options[selectedItemIndex].setColor(sf::Color::White);
		options[0].setColor(sf::Color::Yellow);
		options[0].setCharacterSize (options[selectedItemIndex].getCharacterSize () + 15);
		options[(int)options.size()-1].setCharacterSize (options[selectedItemIndex].getCharacterSize () - 15);
		selectedItemIndex = 0;
	}
}

int CGUI::getPressedItem() {
	return selectedItemIndex;
}

int CGUI::GUICheck(float x, float y) {
	if (pauseButton.getGlobalBounds().contains(x, y)) {
		isPause = true;
		return 1;
	}
	else return 0;
} // 1: pause, 0: continue