#ifndef STARTGAME_H
#define STARTGAME_H
#include <SFML/Graphics.hpp>
#include <time.h>
#include "serpent.h"
using namespace sf;
class StartGame
{
	public:
		StartGame(RenderWindow &lwindow, serpent snake);
		StartGame();
		~StartGame();
		void window();
		void windoww(RenderWindow &lwindow, serpent snake);

	private:
	 serpent snake;
};

#endif
