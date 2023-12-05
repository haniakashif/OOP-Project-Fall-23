#include "bullet.h"

void Bullet::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    Static_tree::load(x, y, w, h, id, x_s, y_s, background);
}

void Bullet::draw(SDL_Renderer *renderer)
{
    Static_tree::draw(renderer);
}

void Bullet::update()
{
    Static_tree::update();
    currFrame = int(((SDL_GetTicks() / 300) % 4));
    x_pos += velocity_x;
    y_pos += velocity_y;
    if (TheCollissionManager::Instance()->collides(gameObject::objects, this) || (x_pos > 3000) || (x_pos < 0) || (y_pos > 3000) || (y_pos < 0))
    {
        gameObject::remove_from_vector(gameObject::objects, this);
    }
    if (TheCollissionManager::Instance()->collides(gameObject::enemy_objs, this))
    {
        gameObject::remove_from_vector(gameObject::enemy_objs, TheCollissionManager::Instance()->get_colliding_object(gameObject::enemy_objs, this));
        gameObject::remove_from_vector(gameObject::objects, this);
    }
}

void Bullet::clean()
{
    Static_tree::clean();
}

void Bullet::set_velocity(int x, int y)
{
    velocity_x = x;
    velocity_y = y;
}