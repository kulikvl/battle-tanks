#include "Window.hpp"
#include "Log.hpp"

Window::Window(unsigned int width, unsigned int height, string title) :
    window(nullptr),
    renderer(nullptr),
    bg_color(0xFF, 0xFF, 0xFF)
{
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    
    if (window == nullptr)
    {
        Log::error("Window(): Couldn't create Window! SDL Error: ");
        Log::error(SDL_GetError());
        throw "Window() exception";
    }
    
    /// Create vsynced renderer for window; VSync allows the rendering to update at the same time as the monitor during verical refresh
    renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (renderer == nullptr)
    {
        Log::error("Window(): Couldn't create Renderer! SDL Error: ");
        Log::error(SDL_GetError());
        throw "Window() exception";
    }
}

Window::~Window()
{
    destroy();
}

void Window::destroy()
{
    for (auto& x : textures)
    {
        if (!x.second.empty())
        {
            for (auto& y : x.second)
                SDL_DestroyTexture(y);
        }
    }
    
    textures.clear();
    
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
}

SDL_Texture* Window::loadImage(string filename, bool createCopyOfTexture)
{
    if ( textures.count(filename) == 0 || createCopyOfTexture )
    {
        SDL_Texture* newTexture = nullptr;
        
        SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
        if (loadedSurface == nullptr)
        {
            Log::error(string("Unable to load image" + filename + "! SDL_image Error: " + IMG_GetError()));
            throw "loadImage() exception";
        }
        
        newTexture = SDL_CreateTextureFromSurface( this->renderer, loadedSurface );
        if (newTexture == nullptr)
        {
            Log::error(string("Unable to create texture from " + filename + "! SDL_image Error: " + IMG_GetError()));
            throw "loadImage() exception";
        }

        SDL_FreeSurface(loadedSurface);
        
        textures[filename].push_back(newTexture);
    }
    
    return textures[filename].back();
}

void Window::refresh()
{
    SDL_RenderPresent(renderer);
}

void Window::fill(Color color)
{
    SDL_SetRenderDrawColor(renderer,
                           color.r(),
                           color.g(),
                           color.b(),
                           color.a());

    SDL_RenderClear(renderer);
}

void Window::clear()
{
    fill(bg_color);
}

void Window::setBackgroundColor(Color color)
{
    bg_color = color;
}



