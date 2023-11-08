#ifndef DIRECTION_H
#define DIRECTION_H
#include <iostream>
#include "Point.h"
#include "Playground.h"
#include "Fruit.h"


class Direction
{
	public:
		Point up;
		Point down;
		Point left;
		Point right;
		int dir;  //Direction actuelle
		
	public:
		Direction();
		set_direction(int a);
		get_direction();
		get_dir();
		get_zero();
};

#endif
