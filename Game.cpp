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
	if (!TheTextureManager::instance()->load_img("background_new.png", "back", Renderer))
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
	if (!TheTextureManager::instance()->load_img("enemy_walk.png", "enemy_walk", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("bullets.png", "bullet", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("hearts.png", "hearts", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("enemy_bullet.png", "e_bullet", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("menu.png", "menu_back", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("key.png", "key", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("keys.png", "keys", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("black.png", "black", Renderer))
	{
		return false;
	}

	char2 = new Character();
	back1 = new static_Objs();
	life = new lives();
	key_collected = new keys();
	menu_bck = new menu();
	key1 = new Collectibles();
	key2 = new Collectibles();
	key3 = new Collectibles();

	barrier = new Static_tree();
	barrier2 = new Static_tree();
	barrier3 = new Static_tree();
	barrier4 = new Static_tree();
	barrier5 = new Static_tree();
	barrier6 = new Static_tree();
	barrier7 = new Static_tree();
	barrier8 = new Static_tree();
	barrier9 = new Static_tree();
	barrier10 = new Static_tree();
	barrier11 = new Static_tree();
	barrier12 = new Static_tree();
	barrier13 = new Static_tree();
	barrier14 = new Static_tree();
	barrier15 = new Static_tree();
	barrier16 = new Static_tree();
	barrier17 = new Static_tree();
	barrier18 = new Static_tree();
	barrier19 = new Static_tree();
	barrier20 = new Static_tree();
	barrier21 = new Static_tree();
	barrier22 = new Static_tree();
	barrier23 = new Static_tree();
	barrier24 = new Static_tree();
	barrier25 = new Static_tree();

	win = new Collectibles();

	enemy1 = new Enemy_troll();
	enemy2 = new Enemy_troll();

	char2->load(30, 198, 32, 32, "w1");
	back1->load(0, 0, 2732, 1536, "back", 0, 0, true);
	life->load(0, 0, 105, 34, "hearts");
	key_collected->load(0, 768 - 25, 75, 25, "keys");
	menu_bck->load(0, 0, 1366, 768, "menu_back");
	key1->load(23, 1482, 25, 26, "key");
	key2->load(1044, 1120, 25, 26, "key");
	key3->load(2688, 1498, 25, 26, "key");

	barrier->load(272, 170, 10, 822, "");
	barrier2->load(0, 146, 368, 26, "");
	barrier3->load(0, 233, 200, 10, "");
	barrier4->load(191, 233, 24, 760, "");
	barrier5->load(115, 982, 98, 21, "");
	barrier6->load(126, 999, 21, 74, "");
	barrier7->load(143, 1053, 73, 163, "");
	barrier8->load(0, 1192, 143, 21, "");
	barrier9->load(268, 982, 88, 17, "");
	barrier10->load(329, 999, 22, 54, "");
	barrier11->load(257, 1053, 86, 169, "");
	barrier12->load(340, 1213, 640, 95, "");
	barrier13->load(340, 1364, 646, 200, "");
	barrier14->load(966, 1192, 678, 40, "");
	barrier15->load(966, 1513, 663, 23, "");
	barrier16->load(1593, 1140, 567, 184, "");
	barrier17->load(1593, 1364, 567, 172, "");
	barrier18->load(1596, 876, 808, 289, "");
	barrier19->load(2152, 495, 580, 337, "");
	barrier20->load(2444, 810, 288, 361, "");
	barrier21->load(1365, 263, 807, 570, ""); // sdsdsd
	barrier22->load(898, 480, 68, 763, "");
	barrier23->load(898, 165, 413, 334, "");
	barrier24->load(1260, 0, 893, 208, "");
	barrier25->load(2152, 0, 580, 36, "");

	win->load(2447, 32, 20, 20, "");

	enemy1->load(237, 1247, 48, 48, "enemy_walk");
	enemy2->load(237, 1300, 48, 48, "enemy_walk");

	return true;
}

void Game::render()
{
	SDL_RenderClear(Renderer);
	if (gameObject::state == 0)
	{
		for (int i = 0; i < gameObject::menu_objects.size(); i++)
		{
			gameObject::menu_objects[i]->draw(Renderer);
		}
	}
	else if (gameObject::state == 1)
	{
		back1->draw(Renderer);
		for (int i = 0; i < gameObject::player_objs.size(); i++)
		{
			gameObject::player_objs[i]->draw(Renderer);
		}
		for (int i = 0; i < gameObject::objects.size(); i++)
		{
			gameObject::objects[i]->draw(Renderer);
		}
		for (int i = 0; i < gameObject::enemy_objs.size(); i++)
		{
			gameObject::enemy_objs[i]->draw(Renderer);
		}
		for (int i = 0; i < gameObject::foreground_objs.size(); i++)
		{
			gameObject::foreground_objs[i]->draw(Renderer);
		}
		for (int i = 0; i < gameObject::Collectible_objects.size(); i++)
		{
			gameObject::Collectible_objects[i]->draw(Renderer);
		}
		// std::cout << gameObject::Collectible_objects.size() << "\n";
		std::cout << gameObject::keys << "\n";
	}
	else if (gameObject::state == 2)
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
	if (gameObject::state == 0)
	{
		for (int i = 0; i < gameObject::menu_objects.size(); i++)
		{
			gameObject::menu_objects[i]->update();
		}
	}
	else if (gameObject::state == 1)
	{
		if (gameObject::life <= 0)
		{
			gameObject::state = 2;
			gameObject::life = 3;
		}
		back1->update();
		for (int i = 0; i < gameObject::player_objs.size(); i++)
		{
			gameObject::player_objs[i]->update();
		}
		for (int i = 0; i < gameObject::objects.size(); i++)
		{
			gameObject::objects[i]->update();
		}
		for (int i = 0; i < gameObject::enemy_objs.size(); i++)
		{
			gameObject::enemy_objs[i]->update();
		}
		for (int i = 0; i < gameObject::foreground_objs.size(); i++)
		{
			gameObject::foreground_objs[i]->update();
		}
		for (int i = 0; i < gameObject::Collectible_objects.size(); i++)
		{
			gameObject::Collectible_objects[i]->update();
		}
	}
	else if (gameObject::state == 2)
	{
		for (int i = 0; i < gameover_objects.size(); i++)
		{
			gameover_objects[i]->update();
		}
		gameObject::life = 3;
		gameObject::keys = 0;
		// Game::reset_game();
	}
	else if (gameObject::state == 3)
	{
		// game win objects update here

		// resetting the game variables:
		gameObject::life = 3;
		gameObject::keys = 0;
		// Game::reset_game();
	}
}
void Game::clean()
{
	std::cout << "cleaning game\n";
	if (gameObject::state == 0)
	{
		for (int i = 0; i < gameObject::menu_objects.size(); i++)
		{
			gameObject::menu_objects[i]->clean();
		}
	}
	// else if (gameObject::state == 1)
	// {
	// 	for (int i = 0; i < gameObject::play_objects.size(); i++)
	// 	{
	// 		gameObject::play_objects[i]->clean();
	// 	}
	// }

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

				if (gameObject::state == 0)
					gameObject::state = 1;
				else if (gameObject::state == 1)
					gameObject::state = 2;
				else if (gameObject::state == 2)
					gameObject::state = 0;
				else if (gameObject::state == 3)
					gameObject::state = 0;
				std::cout << gameObject::state << "\n";
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

void Game::reset_game()
{
	delete Game::g_instance;
	Game::g_instance = nullptr;
	// Game::g_instance = new Game();
}

Game *Game::g_instance = nullptr;