#include "character.h"

void Character::load(int x, int y, int w, int h, std::string id, int x_s, int y_s)
{
    gameObject::load(x, y, w, h, id, x_s, y_s);
}

void Character::draw(SDL_Renderer *renderer)
{
    gameObject::draw(renderer);
}

void Character::update()
{
    if (x_pos < 0)
    {
        x_pos = 0;
    }
    if (x_pos > 1366 - width)
    {
        x_pos = 1366 - width;
    }
    if (y_pos < 0)
    {
        y_pos = 0;
    }
    if (y_pos > 768 - height)
    {
        y_pos = 768 - height;
    }
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

    if ((TheInputHandler::Instance()->keyDown(SDL_SCANCODE_RIGHT)))
    {
        currRow = 3;
        currFrame = int(((SDL_GetTicks() / 300) % 4));
        move_x += 1;
        if (move_x >= 2149 || move_x <= 783)
        {
            x_pos += 1;
        }
    };
    if (TheInputHandler::Instance()->keyDown(SDL_SCANCODE_LEFT))
    {
        currRow = 4;
        currFrame = int(((SDL_GetTicks() / 300) % 4));
        move_x -= 1;
        if (move_x <= 783 || move_x >= 2149)
        {
            x_pos -= 1;
        }
    };
    if (TheInputHandler::Instance()->keyDown(SDL_SCANCODE_UP))
    {
        currRow = 1;
        currFrame = int(((SDL_GetTicks() / 300) % 4));
        move_y -= 1;
        if (move_y >= 1152 || move_y <= 384)
        {
            y_pos -= 1;
        }
    };
    if (TheInputHandler::Instance()->keyDown(SDL_SCANCODE_DOWN))
    {
        currRow = 2;
        currFrame = int(((SDL_GetTicks() / 300) % 4));
        move_y += 1;
        if (move_y >= 1152 || move_y <= 384)
        {
            y_pos += 1;
        }
    };
}

void Character::clean()
{
    std::cout << "obstacle clean\n";
}
