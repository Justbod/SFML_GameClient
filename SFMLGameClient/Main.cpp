#include "Game.h"

void main(int argc, void** argv[])
{
	Game game; //creating game object

	while (!game.GetWindow()->IsDone()) {
		//game loop
		game.HandleInput();
		game.Update();
		game.Render();
	}
}