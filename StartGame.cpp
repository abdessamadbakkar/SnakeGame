#include "StartGame.h"
#include "serpent.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Playground.h"

using namespace std;
using namespace sf;
StartGame::StartGame()
{
	
	window();
}
StartGame::StartGame(sf::RenderWindow &lwindow, serpent snake)
{
	
	windoww(lwindow, snake);
}
StartGame::~StartGame()
{
}

void StartGame::window() {
		Playground pg;
	sf::RenderWindow window(sf::VideoMode(pg.width, pg.longeur), "Snake Game");
 window.setFramerateLimit(60);
 sf::Text position;
 sf::Text score;
 sf::Font font;
 		ostringstream ss;
	ostringstream yy;
	ostringstream zz;
	string s;
	string y;
 	if(!font.loadFromFile("BebasNeue-Regular.ttf")){
		// handle error
	}
	
   
   sf::Color color(sf::Color::Red);
 	 sf::Event event;
 	 	
    srand(time(0));

   
  
    Texture t1, t2, t3;
    t1.loadFromFile("images/dark.jpg");
    t2.loadFromFile("images/red.png");
t3.loadFromFile("images/white.png");

    Sprite sprite1(t1);
    Sprite sprite2(t3);
Sprite sprite3(t2);

    Clock clock;
    float timer = 0, delay = 0.1;

    this->snake.f.position.x = 10;
    this->snake.f.position.y = 10;
	
 	      
this->snake.scoreText.setFont(font);
	this->snake.scoreText.setFillColor(sf::Color::White);
	this->snake.scoreText.setPosition(sf::Vector2f(10, 10));
	zz << this->snake.getScore();
this->snake.scoreText.setString("Score : "+ zz.str());
 	 
 	    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }
  if (this->snake.vitesse.dir!= 2){
        	if(Keyboard::isKeyPressed(Keyboard::Left)) this->snake.dir = 1;
		} 
        if (this->snake.vitesse.dir!= 1){
        if(Keyboard::isKeyPressed(Keyboard::Right)) this->snake.dir = 2;	
		}
        if (this->snake.vitesse.dir!= 0){
        	if(Keyboard::isKeyPressed(Keyboard::Up)) this->snake.dir = 3;
		} 
        if (this->snake.vitesse.dir!= 3){
        	if(Keyboard::isKeyPressed(Keyboard::Down)) this->snake.dir = 0;
		} 
        if (Keyboard::isKeyPressed(Keyboard::Space)) this->snake.pause = 1;

        if (timer > delay) { timer = 0; this->snake.Tick(this->snake.pg.rows,this->snake.pg.cols, window, this->snake); }

        window.clear();
   
        for (int i = 0; i < this->snake.pg.cols; i++)
            for (int j = 0; j < this->snake.pg.rows; j++)
            {
                sprite1.setPosition(i * this->snake.pg.size, j * this->snake.pg.size);  window.draw(sprite1);
            }
           this->snake.pg.drawBorders(window);
 
        for (int i = 0; i < this->snake.get_body_list(); i++)
        {
            sprite2.setPosition(this->snake.s[i].x * this->snake.pg.size, this->snake.s[i].y * this->snake.pg.size);  window.draw(sprite2);
        }
 
        sprite3.setPosition(this->snake.f.position.x * this->snake.pg.size, this->snake.f.position.y * this->snake.pg.size);  window.draw(sprite3);

		window.draw(this->snake.scoreText);

        window.display();
    }


  
}

void StartGame::windoww(RenderWindow &window1, serpent snake) {
	
	
	this->snake = snake;
	
	this->snake.pause = 0;
//	Playground pg;
	
		sf::RenderWindow window(sf::VideoMode(this->snake.pg.width, this->snake.pg.longeur), "Snake Game");
 window.setFramerateLimit(60);
 sf::Text position;
 sf::Text score;
 sf::Font font;
 		ostringstream ss;
	ostringstream yy;
	ostringstream zz;
	string s;
	string y;
 	if(!font.loadFromFile("BebasNeue-Regular.ttf")){
		// handle error
	}
	
   
   sf::Color color(sf::Color::Red);
 	 sf::Event event;
srand(time(0));
   
  
    Texture t1, t2, t3;
    t1.loadFromFile("images/dark.jpg");
    t2.loadFromFile("images/red.png");
t3.loadFromFile("images/white.png");

	
    Sprite sprite1(t1);
    Sprite sprite2(t3);
Sprite sprite3(t2);
	 Clock clock;
    float timer = 0, delay = 0.1;

	 	    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

            if (this->snake.vitesse.dir!= 2){
        	if(Keyboard::isKeyPressed(Keyboard::Left)) this->snake.dir = 1;
		} 
        if (this->snake.vitesse.dir!= 1){
        if(Keyboard::isKeyPressed(Keyboard::Right)) this->snake.dir = 2;	
		}
        if (this->snake.vitesse.dir!= 0){
        	if(Keyboard::isKeyPressed(Keyboard::Up)) this->snake.dir = 3;
		} 
        if (this->snake.vitesse.dir!= 3){
        	if(Keyboard::isKeyPressed(Keyboard::Down)) this->snake.dir = 0;
		} 
        if (Keyboard::isKeyPressed(Keyboard::Space)) this->snake.pause = 1;

        if (timer > delay) { timer = 0; this->snake.Tick(this->snake.pg.rows,this->snake.pg.cols, window, this->snake); }


        window.clear();
   
        for (int i = 0; i < this->snake.pg.cols; i++)
            for (int j = 0; j < this->snake.pg.rows; j++)
            {
                sprite1.setPosition(i * this->snake.pg.size, j * this->snake.pg.size);  window.draw(sprite1);
            }
           this->snake.pg.drawBorders(window);
 
        for (int i = 0; i < this->snake.get_body_list(); i++)
        {
            sprite2.setPosition(this->snake.s[i].x * this->snake.pg.size, this->snake.s[i].y * this->snake.pg.size);  window.draw(sprite2);
        }
 
        sprite3.setPosition(this->snake.f.position.x * this->snake.pg.size, this->snake.f.position.y * this->snake.pg.size);  window.draw(sprite3);

		window.draw(this->snake.scoreText);

        window.display();
    }
	
}
