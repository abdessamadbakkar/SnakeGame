#ifndef POSITION_H
#define POSITION_H
#include <iostream>
#include "Position.h"
#include "Direction.h"
#include "Playground.h"
#include "Fruit.h"
#include "Point.h"


class Position
{
		public:
		Point pos;
	private:
	    add(); //addition de deux positions
	    sub();//soustraction de deux position
	public:
	  Point get_pos();
	
};

#endif
