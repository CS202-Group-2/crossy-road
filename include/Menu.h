
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3

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
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};