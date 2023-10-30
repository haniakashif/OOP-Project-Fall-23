#include "gameObj.h"

void gameObject::load(int x, int y, int w, int h, std::string id, int x_s, int y_s)
{
    x_pos = x;
    y_pos = y;
    x_sor = x_s;
    y_sor = y_s;
    width = w;
    height = h;
    name = id;
    currFrame = 0;
    currRow = 1;
}

// void gameObject::draw(SDL_Renderer *renderer)
// {
//     TheTextureManager::instance()->drawFrame(name, x_pos, y_pos, width, height, currRow, currFrame, renderer);
// }

void gameObject::draw(SDL_Renderer *renderer)
{
    TheTextureManager::instance()->drawCustom(name, x_sor, y_sor, width, height, x_pos, y_pos, currRow, currFrame, renderer);
}

void gameObject::update()
{
}

void gameObject::clean()
{
}
