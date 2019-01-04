#include "Game.h"

const int FPS = 30;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char ** argv)
{
	// set up write to log later
	// freopen("CONSOLE", "w", stdout);

	Game * game = nullptr;
	game = new Game();

	bool success = game->Init();
	if (success)
	{
		game->RunLoop();
	}
	
	game->Shutdown();
	return 0;
}
