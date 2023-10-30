#include "Game.h"
#include <iostream>

bool Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Init Success \n";

		Window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (Window != 0)
		{
			std::cout << "Window Init Success \n";

			Renderer = SDL_CreateRenderer(Window, -1, 0);
			if (Renderer != 0)
			{
				std::cout << "Renderer Init Success \n";

				SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "Renderer Init Failed \n";
				return false;
			}
		}
		else
		{
			std::cout << "Window Init Failed \n";
			return false;
		}
	}
	else
	{
		std::cout << "SDL Init Failed \n";
		return false;
	}
	std::cout << "Init Success\n";

	Running = true;

	if (!TheTextureManager::instance()->load_img("my assets.png", "animate", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("characters.png", "char_animate", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("back_tst.png", "back", Renderer))
	{
		return false;
	}

	en1 = new enemy();
	en2 = new enemy();
	pl1 = new player();
	pl2 = new player();
	char2 = new Character();
	back1 = new Background();
	// back2 = new Background();
	// back3 = new Background();
	// back4 = new Background();

	en1->load(0, 0, 158, 126, "animate");
	en2->load(0, 100, 158, 126, "animate");
	pl1->load(0, 200, 158, 126, "animate");
	pl2->load(0, 300, 158, 126, "animate");
	char2->load(683, 384, 32, 30, "char_animate", 0, 70);
	back1->load(0, 0, 2732, 1536, "back", 0, 0);
	// back2->load(1367, 0, 1366, 768, "back", 1367, 0);
	// back3->load(0, 769, 1366, 768, "back", 0, 79);
	// back4->load(1367, 769, 1366, 768, "back", 1367, 769);

	objects.push_back((back1));
	// objects.push_back((back2));
	// objects.push_back((back3));
	// objects.push_back((back4));
	objects.push_back((en1));
	objects.push_back((en2));
	objects.push_back((pl1));
	objects.push_back((pl2));
	objects.push_back((char2));

	return true;
}

void Game::render()
{
	SDL_RenderClear(Renderer);
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->draw(Renderer);
	}
	SDL_RenderPresent(Renderer);
}

void Game::update()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->update();
	}
}
void Game::clean()
{
	std::cout << "cleaning game\n";
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->clean();
	}

	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}

void Game::handleEvents()
{

	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			Running = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				Running = false;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	TheInputHandler::Instance()->update();
}

Game *Game::instance()
{
	if (g_instance == nullptr)
	{
		g_instance = new Game();
		return g_instance;
	}
	return g_instance;
}

Game *Game::g_instance = nullptr;