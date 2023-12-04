#ifndef _Menu_
#define _Menu_

#include "gameObj.h"

class menu : public gameObject
{
public:
    void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0, bool background = false);
    void draw(SDL_Renderer *renderer);
    void update();
    void clean();
};

#endif