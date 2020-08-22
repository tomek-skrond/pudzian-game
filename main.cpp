#include "Game.h"


int main()
{
	Game game;
	while (game.GetWindowIsOpen()) {

		game.Render();
		game.Update();
		
	}

	
	return 0;
}