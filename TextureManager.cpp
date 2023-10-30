#include "TextureManager.h"

bool TextureManager::load_img(std::string filename, std::string name, SDL_Renderer *renderer)
{
    SDL_Surface *pTempSurf = IMG_Load(filename.c_str());
    if (pTempSurf == 0)
    {
        return false;
    }
    SDL_Texture *img_texture = SDL_CreateTextureFromSurface(renderer, pTempSurf);
    if (img_texture == 0)
    {
        return false;
    }
    SDL_FreeSurface(pTempSurf);
    img_to_textures[name] = img_texture;
    return true;
}

void TextureManager::draw(int x, int y, int width, int height, std::string name, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcrect;
    SDL_Rect dstrct;

    srcrect.x = srcrect.y = 0;
    srcrect.w = dstrct.w = width;
    srcrect.h = dstrct.h = height;
    dstrct.x = x;
    dstrct.y = y;

    SDL_RenderCopyEx(renderer, img_to_textures[name], &srcrect, &dstrct, 0, 0, flip);
}
void TextureManager::drawCustom(std::string name, int x_pos, int y_pos, int width, int height, int x, int y, int currentRow, int currentFrame, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcrect;
    SDL_Rect dstrct;

    srcrect.x = x_pos + (width * currentFrame);
    srcrect.y = y_pos + (height * (currentRow - 1));
    srcrect.w = dstrct.w = width;
    srcrect.h = dstrct.h = height;
    // dstrct.w = 50;
    // dstrct.h = 50;
    dstrct.x = x;
    dstrct.y = y;

    SDL_RenderCopyEx(renderer, img_to_textures[name], &srcrect, &dstrct, 0, 0, flip);
}

void TextureManager::drawFrame(std::string name, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcrct;
    SDL_Rect dstrct;
    srcrct.x = width * currentFrame;
    srcrct.y = height * (currentRow - 1);
    srcrct.w = dstrct.w = width;
    srcrct.h = dstrct.h = height;
    dstrct.x = x;
    dstrct.y = y;
    SDL_RenderCopyEx(renderer, img_to_textures[name], &srcrct, &dstrct, 0, 0, flip);
}

TextureManager *TextureManager::instance()
{
    if (p_instance == nullptr)
    {
        p_instance = new TextureManager();
        return p_instance;
    }
    return p_instance;
}

TextureManager *TextureManager::p_instance = nullptr;