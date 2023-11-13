#ifndef __gameObject__
#define __gameObject__

#include <SDL.h>
// #include "Game.h"
#include <string>
#include <SDL_image.h>
#include <iostream>
#include "InputHandler.h"
#include "TextureManager.h"

class gameObject
{
public:
    virtual void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0);
    // virtual void draw(SDL_Renderer *rend);
    virtual void draw(SDL_Renderer *renderer);
    virtual void update();
    virtual void clean();

protected:
    int x_pos;
    int y_pos;

    int x_sor = 0;
    int y_sor = 0;

    int width;
    int height;

    int currFrame;
    int currRow;

    std::string name;
};

#endif