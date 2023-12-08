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
	if (!TheTextureManager::instance()->load_img("background.png", "back", Renderer))
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
	tree3 = new Static_tree();
	enemy1 = new Enemy_troll();
	enemy2 = new Enemy_troll();
	life = new lives();
	key_collected = new keys();
	menu_bck = new menu();
	key1 = new Collectibles();
	key2 = new Collectibles();
	key3 = new Collectibles();

	char2->load(783, 384, 32, 32, "w1");
	back1->load(0, 0, 2732, 1536, "back", 0, 0, true);
	tree1->load(100, 100, 128, 176, "tileset", 32, 304);
	tree2->load(1000, 500, 128, 176, "tileset", 32, 304);
	tree3->load(1200, 500, 128, 176, "tileset", 32, 304);
	enemy1->load(1400, 400, 48, 48, "enemy_walk");
	enemy2->load(100, 400, 48, 48, "enemy_walk");
	life->load(0, 0, 105, 34, "hearts");
	key_collected->load(0, 768 - 25, 75, 25, "keys");
	menu_bck->load(0, 0, 1366, 768, "menu_back");
	key1->load(392 - 10, 700 - 10, 25, 26, "key");
	key2->load(944 - 10, 1188 - 10, 25, 26, "key");
	key3->load(1568 - 10, 1216 - 10, 25, 26, "key");

	// bullet_test = new Bullet();
	// bullet_test->load(100, 100, 32, 32, "w1");

	// menu_objects.push_back((en1));
	// menu_objects.push_back((en2));
	// menu_objects.push_back((pl1));
	// menu_objects.push_back((pl2));
	// play_objects.push_back(gameObject::player_objs);
	// play_objects.push_back(gameObject::objects);
	// play_objects.push_back(gameObject::enemy_objs);
	// play_objects.push_back((back1));
	// play_objects.push_back((char2));
	// play_objects.push_back((tree1));
	// play_objects.push_back((tree2));
	// play_objects.push_back((tree3));
	// play_objects.push_back((enemy1));

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

Game *Game::g_instance = nullptr;