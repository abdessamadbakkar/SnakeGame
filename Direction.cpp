#include "Direction.h"
#include "Point.h"


Direction::set_direction(int a) {
	
  this->dir = a;
// if (dir == 0) s[0].y += 1;
//    if (dir == 1) s[0].x -= 1;
//    if (dir == 2) s[0].x += 1;
//    if (dir == 3) s[0].y -= 1;
	
}

Direction::Direction(){
	this->up.y -= 1;
	this->down.y += 1;
	this->left.x -= 1;
	this->right.x +=1;
	
}
