#ifndef __Game__
#define __Game__

#include <vector>
// #include "gameObj.h"
#include "player.h"
#include "enemy.h"
#include "character.h"
#include "background.h"

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
	std::vector<gameObject *> objects;

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
};

typedef Game TheGame;

#endif /* defined(__Game__) */