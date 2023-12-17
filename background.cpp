#include "background.h"

void Background::load(int x, int y, int w, int h, std::string id, int x_s, int y_s)
{
    static_Objs::load(x, y, w, h, id, x_s, y_s);
}

void Background::draw(SDL_Renderer *renderer)
{
    static_Objs::draw(renderer);
}

void Background::update()
{
}


