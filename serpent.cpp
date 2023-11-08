#include "serpent.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "GameOver.h"
#include "Pause.h"
serpent::serpent()
{
//	this->initCorp();
	this->longeur = 4;
	this->dir = 0;
	
//   set_position(200,200);
   this->score = 0;

}
serpent::move_body(int x, int y) {
	
		this->shape.move(x,y);
}

serpent::initCorp(){

	this->shape.setSize(sf::Vector2f(20.f,20.f));
    this->shape.setFillColor(sf::Color(50, 200, 50));

}
serpent::move(int x, int y) {
	
	serpent::move_body(x, y);
	
}
sf::RectangleShape serpent::get_body() {
	return this->shape;
}
 Point serpent::get_position() {
 	Point p;
 	p.x = position.pos.x;
 	p.y = position.pos.y;
 	return p;
 	
 }
 
 void serpent::set_position(float x, float y)
 {
 	position.pos.x = x;
 	position.pos.y = y;
 	this->shape.setPosition(x,y);
 }
 
 void serpent::set(int x)
{
//	sf::Vector2f vector = this->shape.getPosition();
//	position.pos.x = vector.x;
//	position.pos.y = vector.y;
this->longeur = x;
}

serpent::Tick(int M, int N, RenderWindow &window, serpent snake){
	this->dir = snake.dir;
	
	 for (int i = this->longeur; i > 0; --i)
    {
    
        this->s[i].x = this->s[i - 1].x; this->s[i].y = this->s[i - 1].y;
    }
    
    
    

    if (this->dir == 0 && this->vitesse.dir!= 3) {this->s[0].y += 1;this->vitesse.dir = 0; //down
	}
    if (this->dir == 1 && this->vitesse.dir!=2){ this->s[0].x -= 1;this->vitesse.dir = 1; //left
}
    if (this->dir == 2 && this->vitesse.dir!=1){ this->s[0].x += 1;this->vitesse.dir = 2; //right
}
    if (this->dir == 3 && this->vitesse.dir!=0){
	 this->s[0].y -= 1;this->vitesse.dir = 3; //up
}
    if (this->pause == 1) {
    	window.close();
    	Pause pause(window, snake);
    	
    	this->pause = 0;
//    	window.close(); 
    	
    	
    	
    	
//    	switch(this->vitesse.dir){
//    		case 0:
//    			this->s[0].y -= 1;
//    			break;
//    		case 1:
//					this->s[0].x -= 0;
//					break;
//					case 2:
//					this->s[0].x += 0;	
//					break;
//					case 3:
//						this->s[0].y -= 0;
//						break;
//							
//		}
	
    		
    	
    	
    	
	}
    
     if ((this->s[0].x == this->s[this->longeur-1].x) && (this->s[0].y == this->s[this->longeur-1].y))
    {
    	window.close();
    	GameOver GO;
    	
    	
    }
    
     for (int i = 0; i < 16; i++)
        {
    if ((this->s[0].x == this->pg.borders[i].x) && (this->s[0].y == this->pg.borders[i].y))
    {
    	window.close();
    	GameOver GO;	
    }
}

    if ((this->s[0].x == this->f.position.x) && (this->s[0].y == this->f.position.y))
    {
        this->longeur++;this->score++; this->f.position.x = rand() % N; this->f.position.y = rand() % M;
          this->pg.borders[0].x = f.position.x;
	this->pg.borders[0].y = f.position.y + rand() % 10 +1;
	
this->pg.borders[8].x = f.position.x + rand() % 10 + 1 ;
	this->pg.borders[8].y = f.position.y;
	this->pg.borders[1].x = this->pg.borders[0].x + 1;
	this->pg.borders[2].x = this->pg.borders[1].x + 1;
	this->pg.borders[3].x = this->pg.borders[2].x + 1;
	this->pg.borders[1].y = this->pg.borders[0].y ;
	this->pg.borders[2].y = this->pg.borders[1].y ;
	this->pg.borders[3].y = this->pg.borders[2].y ;
	this->pg.borders[4].x = this->pg.borders[0].x ;
	this->pg.borders[5].x = this->pg.borders[1].x;
	this->pg.borders[6].x = this->pg.borders[2].x ;
	this->pg.borders[7].x = this->pg.borders[3].x ;
	this->pg.borders[4].y = this->pg.borders[0].y +1;
	this->pg.borders[5].y = this->pg.borders[1].y +1;
	this->pg.borders[6].y = this->pg.borders[2].y +1;
	this->pg.borders[7].y = this->pg.borders[3].y +1;
	
	this->pg.borders[9].x = this->pg.borders[8].x + 1;
	this->pg.borders[10].x = this->pg.borders[9].x + 1;
	this->pg.borders[11].x = this->pg.borders[10].x + 1;
	
	this->pg.borders[9].y = this->pg.borders[8].y ;
	this->pg.borders[10].y = this->pg.borders[9].y ;
	this->pg.borders[11].y = this->pg.borders[10].y ;
	
this->pg.borders[12].x = this->pg.borders[8].x ;

	this->pg.borders[13].x = this->pg.borders[9].x ;
		this->pg.borders[14].x = this->pg.borders[10].x ;
			this->pg.borders[15].x = this->pg.borders[11].x ;
			
this->pg.borders[12].y = this->pg.borders[8].y + 1 ;
	this->pg.borders[13].y = this->pg.borders[9].y +1;
	this->pg.borders[14].y = this->pg.borders[10].y +1;
		this->pg.borders[15].y = this->pg.borders[11].y +1;
			
       	ostringstream zz;
	 
			zz << this->score;
	this->scoreText.setString("Score : "+ zz.str());
    }

    if (this->s[0].x > N) this->s[0].x = 0;  if (this->s[0].x < 0) this->s[0].x = N;
    if (this->s[0].y > M) this->s[0].y = 0;  if (this->s[0].y < 0) this->s[0].y = M;

    for (int i = 1; i < this->longeur; i++)
        if (this->s[0].x == this->s[i].x && this->s[0].y == this->s[i].y)  this->longeur = i;
}


serpent::setScore()
{
	this->score++;
	
}
sf::Text serpent::UpdateScore()
{

	ostringstream zz;
	 
			zz << this->score;
	this->scoreText.setString("Score : "+ zz.str());

	
	
//	window.draw(this->scoreText);
	
}
int serpent::getScore()
{
  return this->score;
}

int serpent::get_body_list(){
	return this->longeur;
}
serpent::~serpent()
{
}
