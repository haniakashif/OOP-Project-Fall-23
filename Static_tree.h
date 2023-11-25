#include "static_Objs.h"

class Static_tree : public static_Objs
{
public:
    virtual void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0, bool background = false);
    virtual void draw(SDL_Renderer *renderer);
    virtual void update();
    virtual void clean();
};