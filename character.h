#ifndef __Characters__
#define __Characters__

#include "CollissionManager.h"

class Character : public gameObject
{
    void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0, bool background = false);
    void draw(SDL_Renderer *renderer);
    void update();
    void clean();

private:
};

#endif