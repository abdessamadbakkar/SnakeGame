#ifndef FRUIT_H
#define FRUIT_H
#include <iostream>
#include "Position.h"
#include "Direction.h"
#include "Point.h"

class Fruit
{
		public:
		Point position;
		int rows;
		int clos;
	public:
		change_pos();
		get_pos();
		init();
};

#endif
