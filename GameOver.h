#ifndef GAMEOVER_H
#define GAMEOVER_H
#define MAX_NUMBER_OF_ITEMS 2
#include <SFML/Graphics.hpp>
class GameOver
{
	public:
		
		GameOver();
			int rows;
	int cols;
	int height;
	int size;
	int width;
void Draw(sf::RenderWindow &window);
		void MoveUp();
		void MoveDown();
		int GetPressedItem() { return selectedItem; }
	private:
		int selectedItem;
		sf::Font font;
		sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

#endif
