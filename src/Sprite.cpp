#include "Sprite.hpp"
#include "Tile.hpp"

Sprite::Sprite(string filename, int atlasIndex, bool createCopyOfImage) :
    image(nullptr),
    width(0),
    height(0),
    atlasIndex(atlasIndex),
    color("white")
{
    image = SDL::window.loadImage(filename, createCopyOfImage);
    
    int w, h;
    SDL_QueryTexture(image, nullptr, nullptr, &w, &h);

    width  = w;
    height = h;
}

void Sprite::render(float x, float y, float angle, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect renderQuad = { (int)x, (int)y, width, height };
    
    if (atlasIndex >= 0)
    {
        SDL_Rect clip {atlasIndex * Tile::WIDTH, 0, Tile::WIDTH, Tile::WIDTH};
        renderQuad.w = clip.w;
        renderQuad.h = clip.h;
        SDL_RenderCopyEx( SDL::window.renderer, image, &clip, &renderQuad, (double) angle, center, flip );
    }
    else
    {
        SDL_RenderCopyEx( SDL::window.renderer, image, nullptr, &renderQuad, (double) angle, center, flip );
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
    
    SDL_SetTextureColorMod( this->image, this->color.r(), this->color.g(), this->color.b() );
}

Color Sprite::getColor()
{
    return color;
}

