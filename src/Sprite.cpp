#include "Sprite.hpp"
#include "Log.hpp"
#include "Color.hpp"
#include "SDL.hpp"

Sprite::Sprite(std::string filename, int atlasIndex, bool createCopyOfImage) :  image(nullptr), width(0), height(0), atlasIndex(atlasIndex), color(255,255,255)
{
    this->image = SDL::window.loadImage(filename, createCopyOfImage);
    
    int w, h;
    SDL_QueryTexture(image, nullptr, nullptr, &w, &h);

    this->width  = w;
    this->height = h;
}

void Sprite::render(float x, float y, float angle, SDL_FPoint* center, SDL_RendererFlip flip)
{
    SDL_FRect renderQuad = { x, y, (float) this->width, (float) this->height };

    if (atlasIndex >= 0)
    {
        SDL_Rect clip {atlasIndex * SDL::window.TILE_WIDTH, 0, SDL::window.TILE_WIDTH, SDL::window.TILE_WIDTH};
        renderQuad.w = clip.w;
        renderQuad.h = clip.h;
        SDL_RenderCopyExF( SDL::window.renderer, image, &clip, &renderQuad, (double) angle, center, flip );
    }
    else
    {
        SDL_RenderCopyExF( SDL::window.renderer, image, nullptr, &renderQuad, (double) angle, center, flip );
    }
}

int Sprite::getWidth()
{
    return this->width;
}

int Sprite::getHeight()
{
    return this->height;
}

SDL_Texture* Sprite::getTexture()
{
    return this->image;
}

void Sprite::setColor( Color color )
{
    if (color == this->color) return;
    
    this->color = color;
    
    //cout << "new color: " << (int)color.r() << endl;
    
    SDL_SetTextureColorMod( this->image, this->color.r(), this->color.g(), this->color.b() );
}

Color Sprite::getColor()
{
    return color;
}
