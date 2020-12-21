#include "../include/Menu.h"
#include <iostream>
Menu::Menu(float width, float height) {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Failed to load" << std::endl;
	}
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Yellow);
	menu[0].setString("Start game");
	

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Load game");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow& window) {
	if (!title.loadFromFile("CrossyRoadTitle.png")) {
		return;
	}
	sf::Sprite titleText(title);
	titleText.setOrigin(titleText.getLocalBounds().left + titleText.getLocalBounds().width / 2,
		titleText.getLocalBounds().top + titleText.getLocalBounds().height / 2);
	titleText.setScale(sf::Vector2f(1.25, 1.25));
	titleText.setPosition(window.getSize().x / 2, titlePadding/2 + 50);
	window.draw(titleText);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
		sf::FloatRect textRect = menu[i].getLocalBounds();
		menu[i].setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
		menu[i].setPosition(sf::Vector2f(window.getSize().x / 2.0f, (window.getSize().y-titlePadding) / (MAX_NUMBER_OF_ITEMS + 1) * (i+1) + titlePadding));
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex--].setColor(sf::Color::White);
		menu[selectedItemIndex].setColor(sf::Color::Yellow);
	}
	else {
		menu[selectedItemIndex].setColor(sf::Color::White);
		menu[MAX_NUMBER_OF_ITEMS-1].setColor(sf::Color::Yellow);
		selectedItemIndex = MAX_NUMBER_OF_ITEMS - 1;
	}
}

void Menu::MoveDown() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex++].setColor(sf::Color::White);
		menu[selectedItemIndex].setColor(sf::Color::Yellow);
	}
	else {
		menu[selectedItemIndex].setColor(sf::Color::White);
		menu[0].setColor(sf::Color::Yellow);
		selectedItemIndex = 0;
	}
}

int Menu::getPressedItem() {
	return selectedItemIndex;
}