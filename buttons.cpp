#include "buttons.h"
#include <SDL_image.h>

void buttons::load(int x, int y, int w, int h, std::string id, int x_s, int y_s)
{
    gameObject::load(x, y, w, h, id, x_s, y_s);
}

buttons::~buttons() {
    // SDL_DestroyTexture(texture);
}

void buttons::draw(SDL_Renderer *renderer)
{
    gameObject::draw(renderer);
}

void buttons::update()
{
    // x_pos += 1;
    // currFrame = int(((SDL_GetTicks() / 300) % 3));
}

void buttons::clean()
{
    std::cout << "buttons clean\n";
}

// bool buttons::isClicked(int mouseX, int mouseY) {
//     SDL_Point point = { mouseX, mouseY };
//     return SDL_PointInRect(&point, &rect);
// }