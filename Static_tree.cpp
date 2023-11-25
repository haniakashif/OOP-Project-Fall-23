#pragma once
#include "Static_tree.h"

void Static_tree::draw(SDL_Renderer *renderer)
{
    static_Objs::draw(renderer);
}

void Static_tree::update()
{
    if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_RIGHT)))
    {
        if (!TheCollissionManager::Instance()->collides_with_right(gameObject::player_objs, gameObject::objects, 0))
        {
            if (move_x < 2149 && move_x > 783)
            {
                x_pos -= 1;
            }
        }
    }

    if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_LEFT)))
    {
        if (!TheCollissionManager::Instance()->collides_with_left(gameObject::player_objs, gameObject::objects, 0))
        {
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
            if (move_y < 1152 && move_y > 384)
            {
                y_pos += 1;
            }
        }
    }
    if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_DOWN)))
    {
        if (!TheCollissionManager::Instance()->collides_with_top(gameObject::player_objs, gameObject::objects, 0))
        {
            if (move_y < 1152 && move_y > 384)
            {
                y_pos -= 1;
            }
        }
    }
    if (TheInputHandler::Instance()->keyDown(SDL_SCANCODE_W))
    {
        std::cout << "W presses\n ";
        for (int i = 0; i < gameObject::player_objs.size(); i++)
        {
            std::cout << gameObject::player_objs[i]->get_name() << std::endl;
        }
    }
}

void Static_tree::clean()
{
}

void Static_tree::load(int x, int y, int w, int h, std::string id, int x_s, int y_s, bool background)
{
    static_Objs::load(x, y, w, h, id, x_s, y_s, background);
}