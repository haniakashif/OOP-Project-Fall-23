#ifndef __Game__
#define __Game__

#include <vector>
#include "character.h"

#include "Enemy_troll.h"
#include "player.h"
#include "Static_tree.h"
#include "bullet.h"
#include "lives.h"
#include "menu.h"
#include "Collectibles.h"
#include "keys.h"

class Game
{
public:
	static Game *instance();

	bool init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void Quit() { Running = false; }
	bool running() { return Running; }
	SDL_Renderer *get_renderer() { return Renderer; }
	std::vector<gameObject *> menu_objects;
	std::vector<gameObject *> play_objects;
	std::vector<gameObject *> gameover_objects;

private:
	Game() {}
	static Game *g_instance;
	SDL_Window *Window;
	SDL_Renderer *Renderer;
	bool Running;

	gameObject *pl1;
	gameObject *pl2;
	gameObject *en1;
	gameObject *en2;
	gameObject *char2;
	gameObject *back1;
	gameObject *back2;
	gameObject *back3;
	gameObject *back4;
	gameObject *tree1;
	gameObject *tree2;
	gameObject *tree3;
	gameObject *enemy1;
	gameObject *enemy2;
	gameObject *bullet_test;
	gameObject *life;
	gameObject *key_collected;
	gameObject *menu_bck;
	gameObject *key1;
	gameObject *key2;
	gameObject *key3;
};

typedef Game TheGame;

#endif /* defined(__Game__) */