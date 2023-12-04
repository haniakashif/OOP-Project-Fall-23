#include "menu.h"

void menu::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    gameObject::menu_objects.push_back(this);
    gameObject::load(x, y, w, h, id, x_s, y_s);
}

void menu::draw(SDL_Renderer *renderer)
{
    gameObject::draw(renderer);
}

void menu::update()
{
}

void menu::clean()
{
    std::cout << "menu clean\n";
}