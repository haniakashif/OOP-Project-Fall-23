#include "enemy.h"

void enemy::load(int x, int y, int w, int h, std::string id, int x_s, int y_s)
{
    gameObject::load(x, y, w, h, id, x_s, y_s);
}

void enemy::draw(SDL_Renderer *renderer)
{
    gameObject::draw(renderer);
}

void enemy::update()
{
    x_pos += 1;
    currFrame = int(((SDL_GetTicks() / 300) % 3));
}

void enemy::clean()
{
    std::cout << "enemy clean\n";
}
