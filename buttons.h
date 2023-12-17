#ifndef BUTTON_H
#define BUTTON_H

#include "gameObj.h"

class buttons : public gameObject
{
public:
    void draw(SDL_Renderer *renderer);
    // bool isClicked(int mouseX, int mouseY);
    void load(int x, int y, int w, int h, std::string id, int x_s = 0, int y_s = 0);
    void update();

    // private:
    //     SDL_Texture* texture;
    //     SDL_Renderer* renderer;
    //     SDL_Rect rect;
};

#endif // BUTTON_H