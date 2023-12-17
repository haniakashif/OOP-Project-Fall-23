#include "static_Objs.h"

void static_Objs::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    if (!background)
    {
        objects.push_back(this);
    }
    gameObject::load(x, y, w, h, id, x_s, y_s, background);
}

void static_Objs::draw(SDL_Renderer *renderer)
{
    gameObject::draw(renderer);
}

void static_Objs::update()
{
    if (move_x < 0)
    {
        move_x = 0;
    }
    if (move_x > 1366 * 2)
    {
        move_x = 1366 * 2;
    }
    if (move_y < 0)
    {
        move_y = 0;
    }
    if (move_y > 768 * 2)
    {
        move_y = 768 * 2;
    }
    if (x_pos > 0)
    {
        x_pos = 0;
    }
    if (x_pos < -1366)
    {
        x_pos = -1366;
    }
    if (y_pos > 0)
    {
        y_pos = 0;
    }
    if (y_pos < -768)
    {
        y_pos = -768;
    }
    // std::cout << "colliding with top: " << TheCollissionManager::Instance()->collides_with_top(gameObject::player_objs, gameObject::objects, 0) << std::endl;
    // std::cout << "colliding with bottom: " << TheCollissionManager::Instance()->collides_with_bottom(gameObject::player_objs, gameObject::objects, 0) << std::endl;
    // std::cout << "colliding with left: " << TheCollissionManager::Instance()->collides_with_right(gameObject::player_objs, gameObject::objects, 0) << std::endl;
    // std::cout << "colliding with right: " << TheCollissionManager::Instance()->collides_with_left(gameObject::player_objs, gameObject::objects, 0) << std::endl;
    if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_RIGHT)))
    {
        if (!TheCollissionManager::Instance()->collides_with_right(gameObject::player_objs, gameObject::objects, 0))
        {
            move_x += 1;
            if (move_x < 2149 && move_x > 783)
            {
                x_pos -= 1;
            }
        }
    }

    else if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_LEFT)))
    {
        if (!TheCollissionManager::Instance()->collides_with_left(gameObject::player_objs, gameObject::objects, 0))
        {
            move_x -= 1;
            if (move_x < 2149 && move_x > 783)
            {
                x_pos += 1;
            }
        }
    }
    if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_UP)))
    {
        if (!TheCollissionManager::Instance()->collides_with_bottom(gameObject::player_objs, gameObject::objects, 0))
        {
            move_y -= 1;
            if (move_y < 1152 && move_y > 384)
            {
                y_pos += 1;
            }
        }
    }
    else if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_DOWN)))
    {
        if (!TheCollissionManager::Instance()->collides_with_top(gameObject::player_objs, gameObject::objects, 0))
        {
            move_y += 1;
            if (move_y < 1152 && move_y > 384)
            {
                y_pos -= 1;
            }
        }
    }
}



void static_Objs::set_velocity(int x, int y)
{
    gameObject::set_velocity(x, y);
}