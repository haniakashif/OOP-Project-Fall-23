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
	void reset_game();

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

	gameObject *char2;
	gameObject *back1;
	gameObject *life;
	gameObject *key_collected;
	gameObject *menu_bck;
	gameObject *key1;
	gameObject *key2;
	gameObject *key3;

	gameObject *barrier;
	gameObject *barrier2;
	gameObject *barrier3;
	gameObject *barrier4;
	gameObject *barrier5;
	gameObject *barrier6;
	gameObject *barrier7;
	gameObject *barrier8;
	gameObject *barrier9;
	gameObject *barrier10;
	gameObject *barrier11;
	gameObject *barrier12;
	gameObject *barrier13;
	gameObject *barrier14;
	gameObject *barrier15;
	gameObject *barrier16;
	gameObject *barrier17;
	gameObject *barrier18;
	gameObject *barrier19;
	gameObject *barrier20;
	gameObject *barrier21;
	gameObject *barrier22;
	gameObject *barrier23;
	gameObject *barrier24;
	gameObject *barrier25;

	gameObject *win;

	gameObject *enemy1;
	gameObject *enemy2;
	gameObject *enemy3;
	gameObject *enemy4;
	gameObject *enemy5;
	gameObject *enemy6;
	gameObject *enemy7;
	gameObject *enemy8;
	gameObject *enemy9;
	gameObject *enemy10;
};

typedef Game TheGame;

#endif /* defined(__Game__) */