#include <SDL.h>
#include <Windows.h>
#include "Game.h"
#include <iostream>

Game *game = 0;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char *args[])
{
	Uint32 frameStart, frameTime;

	if (TheGame::instance()->init("Game", 100, 100, 1366, 768, false))
	{
		while (TheGame::instance()->running())
		{
			frameStart = SDL_GetTicks();

			TheGame::instance()->handleEvents();
			TheGame::instance()->update();
			TheGame::instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}

		TheGame::instance()->clean();
	}
	else
	{
		std::cout << "Init failed\n";
	}
	return 0;
}