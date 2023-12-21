#ifndef __Player__
#define __Player__

#include "gameObj.h"

class player : public gameObject
{
public:
    void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0);
    void draw(SDL_Renderer *renderer);
    void update();
    void clean();
};

#endif