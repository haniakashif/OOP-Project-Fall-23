#ifndef __TextureManager__
#define __TextureManager__

#include <sdl.h>
#include <map>
#include <SDL_image.h>
#include <string>

class TextureManager
{
public:
    std::map<std::string, SDL_Texture *> img_to_textures;

    bool load_img(std::string filename, std::string name, SDL_Renderer *renderer);
    void draw(int x, int y, int width, int height, std::string name, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(std::string name, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawCustom(std::string name, int x_pos, int y_pos, int width, int height, int x, int y, int currentRow, int currentFrame, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    static TextureManager *instance();

private:
    TextureManager() {}
    static TextureManager *p_instance;
};

typedef TextureManager TheTextureManager;

#endif