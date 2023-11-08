#include "menu.h"
#include <SFML/Graphics.hpp>


Menu::Menu(float width, float height)
{
	if(!font.loadFromFile("BebasNeue-Regular.ttf")){
		// handle error
	}
	
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(740 / 2 - 25.f, 580 / 2 - 25.f));
	//menu[0].setPosition(sf::Vector2f(width / 2.1, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(740 / 2 - 25.f, 580 / 2 + 25.f));
	//menu[1].setPosition(sf::Vector2f(width / 2.1, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	selectedItem = 0;
	}

Menu::~Menu()
{
}


void Menu::Draw(sf::RenderWindow &window){
	
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItem + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}
