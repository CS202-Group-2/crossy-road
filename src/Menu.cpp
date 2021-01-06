#include "../include/Menu.h"
#include <iostream>
Menu::Menu(float width, float height) {
	if (!font.loadFromFile(Constants::GetInstance().menuFont)) {
		std::cout << "Failed to load" << std::endl;
	}
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Yellow);
	menu[0].setString("Start game");
	menu[0].setCharacterSize (menu[0].getCharacterSize () + 10);

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Load game");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (Constants::GetInstance().NUMBER_OF_MENU_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (Constants::GetInstance().NUMBER_OF_MENU_ITEMS + 1) * 3));
}

Menu::~Menu() {
	delete[] menu;

}

void Menu::draw(sf::RenderWindow& window) {
	if (!title.loadFromFile("assets/graphics/CrossyRoadTitle.png")) {
		return;
	}
	sf::RectangleShape rectangle(sf::Vector2f(250, 350));
	rectangle.setOrigin(rectangle.getLocalBounds().left + rectangle.getLocalBounds().width / 2,
		rectangle.getLocalBounds().top + rectangle.getLocalBounds().height / 2);
	rectangle.setPosition(window.getSize().x / 2, (window.getSize().y - titlePadding) / 2 + titlePadding);
	rectangle.setFillColor(sf::Color(0, 0, 0, 200));
	window.draw(rectangle);
	sf::Sprite titleText(title);
	titleText.setOrigin(titleText.getLocalBounds().left + titleText.getLocalBounds().width / 2,
		titleText.getLocalBounds().top + titleText.getLocalBounds().height / 2);
	titleText.setScale(sf::Vector2f(1.25, 1.25));
	titleText.setPosition(window.getSize().x / 2, titlePadding/2 + 50);
	window.draw(titleText);
	for (int i = 0; i < Constants::GetInstance().NUMBER_OF_MENU_ITEMS; ++i) {
		sf::FloatRect textRect = menu[i].getLocalBounds();
		menu[i].setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
		menu[i].setPosition(sf::Vector2f(window.getSize().x / 2.0f, 
			(window.getSize().y-titlePadding) / 
			(Constants::GetInstance().NUMBER_OF_MENU_ITEMS + 1) * 
			(i+1) + titlePadding));
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex--].setColor(sf::Color::White);
		menu[selectedItemIndex].setColor(sf::Color::Yellow);
		menu[selectedItemIndex].setCharacterSize (menu[selectedItemIndex].getCharacterSize () + 10);
		menu[selectedItemIndex + 1].setCharacterSize (menu[selectedItemIndex].getCharacterSize () - 10);
	}
	else {
		menu[selectedItemIndex].setColor(sf::Color::White);
		menu[Constants::GetInstance().NUMBER_OF_MENU_ITEMS -1].setColor(sf::Color::Yellow);
		menu[Constants::GetInstance ().NUMBER_OF_MENU_ITEMS - 1].setCharacterSize (menu[Constants::GetInstance ().NUMBER_OF_MENU_ITEMS - 1].getCharacterSize () + 10);
		menu[0].setCharacterSize (menu[0].getCharacterSize () - 10);
		selectedItemIndex = Constants::GetInstance().NUMBER_OF_MENU_ITEMS - 1;
	}
}

void Menu::MoveDown() {
	if (selectedItemIndex + 1 < Constants::GetInstance().NUMBER_OF_MENU_ITEMS) {
		menu[selectedItemIndex++].setColor(sf::Color::White);
		menu[selectedItemIndex].setColor(sf::Color::Yellow);
		menu[selectedItemIndex].setCharacterSize (menu[selectedItemIndex].getCharacterSize () + 10);
		menu[selectedItemIndex - 1].setCharacterSize (menu[selectedItemIndex].getCharacterSize () - 10);
	}
	else {
		menu[selectedItemIndex].setColor(sf::Color::White);
		menu[0].setColor(sf::Color::Yellow);
		menu[0].setCharacterSize (menu[selectedItemIndex].getCharacterSize () + 10);
		menu[Constants::GetInstance ().NUMBER_OF_MENU_ITEMS - 1].setCharacterSize (menu[selectedItemIndex].getCharacterSize () - 10);
		selectedItemIndex = 0;
	}
}

int Menu::getPressedItem() {
	return selectedItemIndex;
}