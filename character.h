#ifndef __Characters__
#define __Characters__

#include "gameObj.h"

class Character : public gameObject
{
    void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0);
    void draw(SDL_Renderer *renderer);
    void update();
    void clean();

private:
    int move_x = 783;
    int move_y = 384;
};

#endif