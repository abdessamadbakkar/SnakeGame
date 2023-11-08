#ifndef SERPENT_H
#define SERPENT_H
#include <iostream>
#include "Position.h"
#include "Direction.h"
#include "Playground.h"
#include "Fruit.h"
#include "Point.h"
#include <SFML/Graphics.hpp>
//#include <array>

using namespace std;
class serpent
{
	
	
	public:
		serpent();
		~serpent();
	public :
		string self_collision;
		string wall_collision;
			Point s[100];
			int dir;
			int pause;
			sf::Text scoreText;
			Direction vitesse;
//		: string
	Fruit f;
		Playground pg;
	private:
		sf::RectangleShape shape;
		;
		Position position;
	
		int score;
		
		int longeur;
	
		sf::Vector2f m_snakeDirection;
		Position *Body; // Ou bien in tableau c'est le corps de votre serpent
	
	//	Playground.borders borders;
	
	private: 
		changer_fruit_pos(); //voir si un changement de position de fruit  a eu lieu 
		move_body(int x, int y); //bouger le serpent
		initCorp();
		is_injured_itself(); // v�rifier si le serpent s'est suicider
		is_colliding_wall(); // Pas n�cessaire dans notre code (le serpent peut p�n�trer  
                                                        // les murs) donc vous y �crite le code au cas o� vous avez 
                                                        //des obstacles
	public:
	  sf::RectangleShape get_body();
	   int get_body_list();
	   get_vitesse();
	   Tick(int , int , RenderWindow &window, serpent snake);
	   setScore();
	   sf::Text UpdateScore();
	   int getScore();
	   Point get_position();
	   void set(int);
	   turner();
	   move(int x, int y);
	   cli();
	   void set_position(float x, float y);
};

#endif
