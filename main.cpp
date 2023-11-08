#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "serpent.h"
#include "Position.h"
#include "Direction.h"
#include "Playground.h"
#include "Fruit.h"
#include "menu.h"
#include "StartGame.h"

using namespace std; 

//Voilà un exemple des différentes classes que vous pouvez avoir dans votre projet.
//Vous pouvez les modifier selon votre besoin par exemple vous pouvez ne pas avoir la classe Playground.
//L'essentiel c'est d'avoir les classes suivantes dans votre projet Serpent, Fruit, Direction et Position.
//
//Pour la structure Point pouvez également avoir votre méthode pour gérer les postions sur window.


int page_number=1;


int main()
{
    sf::RenderWindow window(sf::VideoMode(740, 580), "Menu");
   
    
    Menu menu(window.getSize().x, window.getSize().y);

    sf::Color color(sf::Color(46, 148, 185));
 	sf::Event event;
 	sf::Font font;
 	Text text;
 		if(!font.loadFromFile("BebasNeue-Regular.ttf")){
		// handle error
	}
 	text.setFont(font);
	text.setFillColor(sf::Color::White);
		text.setString("Snake Game!");
		text.setCharacterSize(50);
	text.setPosition(sf::Vector2f(740 / 2 - 85.f, 580 / 2 - 180.f));

	
 	

while(true) {
    while (window.isOpen())
    {       
        while (window.pollEvent(event))
        {	
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						window.close();
						page_number = 0;
						break;

					case 1:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}

        }
        window.clear(color);
        menu.Draw(window);
        window.draw(text);
        window.display();
   }
    
    if(page_number == 0){
    	
    	StartGame SG;
    	
    	
    page_number = 1;
	}
    
   }  


    return 0;
}



