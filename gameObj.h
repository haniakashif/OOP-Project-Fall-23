#ifndef __gameObject__
#define __gameObject__

#include <SDL.h>
#include <vector>
#include <string>
#include <array>
#include <SDL_image.h>
#include <iostream>
#include "InputHandler.h"
#include "TextureManager.h"

class gameObject
{
public:
    virtual void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0, bool background = false);
    // virtual void draw(SDL_Renderer *rend);
    virtual void draw(SDL_Renderer *renderer);
    virtual void update();
    virtual void clean();

    int get_x();
    int get_y();
    int get_width();
    int get_height();

    void increment_x(int x);
    void increment_y(int y);
    void decrement_x(int x);
    void decrement_y(int y);

    static std::vector<gameObject *> objects;
    static std::vector<gameObject *> player_objs;
    static std::vector<gameObject *> enemy_objs;

    static int move_x;
    static int move_y;

    std::string get_name();

protected:
    std::string name;

    int x_pos;
    int y_pos;

    int x_sor = 0;
    int y_sor = 0;

    int width;
    int height;

    int currFrame;
    int currRow;
};

#endif