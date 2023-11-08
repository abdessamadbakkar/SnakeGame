#include "GameOver.h"
#include "StartGame.h"


using namespace sf;
GameOver::GameOver()
{
	int page_number=1;
		this->rows = 40;
	this->cols = 50;
	this->size = 16;
	this->height = rows * size;
	this->width = cols * size;

	sf::RenderWindow window(sf::VideoMode(this->width, this->height), "GameOver");
	  sf::Color color(sf::Color(46, 148, 185));
 	sf::Event event;
 	sf::Font font;
 	
 	Text text;
 		if(!font.loadFromFile("BebasNeue-Regular.ttf")){
		// handle error
	}
	
 	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(this->cols / 2.1 * this->size - 90, 580 / 2 - 180.f));
	text.setString("Game Over!");
	text.setCharacterSize(50);

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Replay");
	menu[0].setPosition(sf::Vector2f(this->cols / 2.1 * this->size - 35, 580 / 2 - 45.f));
	
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(this->cols / 2.1* this->size - 25,  580 / 2 + 25.f));
	
	selectedItem = 0;
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
					this->MoveUp();
					break;

				case sf::Keyboard::Down:
					this->MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (this->GetPressedItem())
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
        window.draw(text);
       this->Draw(window);
        window.display();
   }
   if(page_number == 0){
    	
    	StartGame SG;
    	
    	
    page_number = 1;
	}
    
   } 
	}



void GameOver::Draw(sf::RenderWindow &window){
	
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
		window.draw(menu[i]);
	}
}

void GameOver::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}

void GameOver::MoveDown()
{
	if (selectedItem + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}
