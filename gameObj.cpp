#include "gameObj.h"

std::vector<gameObject *> gameObject::objects;
std::vector<gameObject *> gameObject::player_objs;
std::vector<gameObject *> gameObject::enemy_objs;

void gameObject::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
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

std::string gameObject::get_name()
{
    return name;
}

int gameObject::get_x()
{
    return x_pos;
}
int gameObject::get_y()
{
    return y_pos;
}

int gameObject::get_width()
{
    return width;
}

int gameObject::get_height()
{
    return height;
}
void gameObject::increment_x(int x)
{
    x_pos += x;
}
void gameObject::increment_y(int y)
{
    y_pos += y;
}
void gameObject::decrement_x(int x)
{
    x_pos -= x;
}
void gameObject::decrement_y(int y)
{
    y_pos -= y;
}

void gameObject::set_velocity(int x, int y)
{
    velocity_x = x;
    velocity_y = y;
}

void gameObject::remove_from_vector(std::vector<gameObject *> &vec, gameObject *obj)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i]->get_name() == obj->get_name())
        {
            gameObject *temp = vec[i];
            vec.erase(vec.begin() + i);
            delete temp;
        }
    }
}

int gameObject::move_x = 783;
int gameObject::move_y = 384;