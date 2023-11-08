#ifndef PAUSE_H
#define PAUSE_H
#define MAX_NUMBER_OF_ITEMS 2
#include <SFML/Graphics.hpp>
#include "serpent.h"

class Pause
{
	public:
		Pause(sf::RenderWindow &window, serpent snake);
		~Pause();

		
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
		sf::Text menu[MAX_NUMBER_OF_ITEMS + 1];
};

#endif
