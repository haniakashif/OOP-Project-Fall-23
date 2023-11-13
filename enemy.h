#ifndef __Enemy__
#define __Enemy__

#include "gameObj.h"

class enemy : public gameObject
{
    void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0);
    void draw(SDL_Renderer *renderer);
    void update();
    void clean();
};

#endif