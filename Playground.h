#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include <iostream>
#include "Position.h"
#include "Direction.h"
#include "Fruit.h"
#include "Point.h"
#include <SFML/Graphics.hpp>
#include <time.h>


using namespace sf; 
class Playground
{

	public:
		int rows;
	int cols;
	int longeur;
	int size;
	int width;
	int dim;
	Point borders[50];
	 

		Playground();
		drawBorders(sf::RenderWindow &window);
		//Méthodes dont vous aurez besoin.
};

#endif
