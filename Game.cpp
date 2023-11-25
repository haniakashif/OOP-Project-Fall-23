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
	// if (!TheTextureManager::instance()->load_img("characters.png", "char_animate", Renderer))
	// {
	// 	return false;
	// }
	if (!TheTextureManager::instance()->load_img("back_tst.png", "back", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("walk 1.png", "w1", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("tileset.png", "tileset", Renderer))
	{
		return false;
	}

	// en1 = new enemy();
	// en2 = new enemy();
	// pl1 = new player();
	// pl2 = new player();
	// en1->load(0, 0, 158, 126, "animate");
	// en2->load(0, 100, 158, 126, "animate");
	// pl1->load(0, 200, 158, 126, "animate");
	// pl2->load(0, 300, 158, 126, "animate");
	char2 = new Character();
	back1 = new static_Objs();
	tree1 = new Static_tree();
	tree2 = new Static_tree();
	char2->load(783, 384, 32, 32, "w1");
	back1->load(0, 0, 2732, 1536, "back", 0, 0, true);
	tree1->load(100, 100, 128, 176, "tileset", 32, 304);
	tree2->load(1000, 500, 128, 176, "tileset", 32, 304);

	// menu_objects.push_back((en1));
	// menu_objects.push_back((en2));
	// menu_objects.push_back((pl1));
	// menu_objects.push_back((pl2));

	play_objects.push_back((back1));
	play_objects.push_back((char2));
	play_objects.push_back((tree1));
	play_objects.push_back((tree2));

	return true;
}

void Game::render()
{
	SDL_RenderClear(Renderer);
	if (state == 0)
	{
		for (int i = 0; i < menu_objects.size(); i++)
		{
			menu_objects[i]->draw(Renderer);
		}
	}
	else if (state == 1)
	{
		for (int i = 0; i < play_objects.size(); i++)
		{
			play_objects[i]->draw(Renderer);
		}
	}
	else if (state == 2)
	{
		for (int i = 0; i < gameover_objects.size(); i++)
		{
			gameover_objects[i]->draw(Renderer);
		}
	}
	SDL_RenderPresent(Renderer);
}

void Game::update()
{
	if (state == 0)
	{
		for (int i = 0; i < menu_objects.size(); i++)
		{
			menu_objects[i]->update();
		}
	}
	else if (state == 1)
	{
		for (int i = 0; i < play_objects.size(); i++)
		{
			play_objects[i]->update();
		}
	}
	else if (state == 2)
	{
		for (int i = 0; i < gameover_objects.size(); i++)
		{
			gameover_objects[i]->update();
		}
	}
}
void Game::clean()
{
	std::cout << "cleaning game\n";
	if (state == 0)
	{
		for (int i = 0; i < menu_objects.size(); i++)
		{
			menu_objects[i]->clean();
		}
	}
	else if (state == 1)
	{
		for (int i = 0; i < play_objects.size(); i++)
		{
			play_objects[i]->clean();
		}
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
			case SDLK_RETURN:

				if (state == 0)
					state = 1;
				else if (state == 1)
					state = 2;
				else if (state == 2)
					state = 0;
				std::cout << state << "\n";
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