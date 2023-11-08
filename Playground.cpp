#include "Playground.h"





Playground::Playground(){
	this->rows = 30;
	this->cols = 40;
	this->size = 16;
	this->longeur = rows * size;
	this->width = cols * size;
	for(int i = 0;i<16;i++){
			this->borders[i].x = rand() % this->cols + 1;
	this->borders[i].y = rand() % this->rows + 1;
	}
	
	          this->borders[0].x = 10;
	this->borders[0].y = 10 + rand() % 10 +1;
	
this->borders[8].x = 10 + rand() % 10 + 1 ;
	this->borders[8].y = 10;
	
	this->borders[1].x = this->borders[0].x + 1;
	this->borders[2].x = this->borders[1].x + 1;
	this->borders[3].x = this->borders[2].x + 1;
	this->borders[1].y = this->borders[0].y ;
	this->borders[2].y = this->borders[1].y ;
	this->borders[3].y = this->borders[2].y ;
	this->borders[4].x = this->borders[0].x ;
	this->borders[5].x = this->borders[1].x;
	this->borders[6].x = this->borders[2].x ;
	this->borders[7].x = this->borders[3].x ;
	this->borders[4].y = this->borders[0].y +1;
	this->borders[5].y = this->borders[1].y +1;
	this->borders[6].y = this->borders[2].y +1;
	this->borders[7].y = this->borders[3].y +1;
	this->borders[9].x = this->borders[8].x + 1;
	this->borders[10].x = this->borders[9].x + 1;
	this->borders[11].x = this->borders[10].x + 1;
	this->borders[9].y = this->borders[8].y ;
	this->borders[10].y = this->borders[9].y ;
	this->borders[11].y = this->borders[10].y ;
	
this->borders[12].x = this->borders[8].x ;

	this->borders[13].x = this->borders[9].x ;
		this->borders[14].x = this->borders[10].x ;
			this->borders[15].x = this->borders[11].x ;
			
this->borders[12].y = this->borders[8].y + 1 ;
	this->borders[13].y = this->borders[9].y +1;
	this->borders[14].y = this->borders[10].y +1;
		this->borders[15].y = this->borders[11].y +1;

	
}

Playground::drawBorders(sf::RenderWindow &window){
	   
	
Texture t4;
	t4.loadFromFile("images/green.png");
	Sprite sprite4(t4);
	   for (int i = 0; i < 16; i++)
        {
           sprite4.setPosition(this->borders[i].x * this->size, this->borders[i].y * this->size);  window.draw(sprite4);
        }
}
