
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Constants.h"


class Menu {
public:
	Menu(float width, float height);
	~Menu();

	const float titlePadding = 300;
	

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getPressedItem();
private:
	int selectedItemIndex = 0;
	sf::Texture title;
	sf::Font font;
	sf::Text* menu = new sf::Text[Constants::GetInstance().NUMBER_OF_MENU_ITEMS];
};