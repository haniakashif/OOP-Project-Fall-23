#include "player.h"

void player::load(int x, int y, int w, int h, std::string id, int x_s, int y_s)
{
    gameObject::load(x, y, w, h, id, x_s, y_s);
}

void player::draw(SDL_Renderer *renderer)
{
    gameObject::draw(renderer);
}

void player::update()
{
    x_pos += 1;
    y_pos += 1;
    currFrame = int(((SDL_GetTicks() / 300) % 3));
}

void player::clean()
{
    std::cout << "player clean\n";
}
