#include "Position.h"
#include "Direction.h"
#include "Playground.h"
#include "Fruit.h"
#include "Point.h"
#include "serpent.h"
#include <SFML/Graphics.hpp>



Point Position::get_pos() 
{
	Point p;
	
	p.x = pos.x;
	p.y = pos.y;
	
	return p;
}
