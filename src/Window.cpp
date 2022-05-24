#include "Window.hpp"
#include "Log.hpp"

Window::Window(uint32_t width, uint32_t height, std::string title):
    window(nullptr),
    renderer(nullptr),
    bg_color(0xFF, 0xFF, 0xFF)
{
    
    this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    
    if (this->window == nullptr)
    {
        Log::error("Window(): Couldn't create Window! SDL Error: ");
        Log::error(SDL_GetError());
        throw "Window() Fail";
    }
    
    /// Create vsynced renderer for window; VSync allows the rendering to update at the same time as the monitor during verical refresh
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (this->renderer == nullptr)
    {
        Log::error("Window(): Couldn't create Renderer! SDL Error: ");
        Log::error(SDL_GetError());
        throw "Window() Fail";
    }
}

Window::~Window()
{
    this->destroy();
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
    
    if (this->renderer)
    {
        SDL_DestroyRenderer(this->renderer);
        this->renderer = nullptr;
    }

    if (this->window)
    {
        SDL_DestroyWindow(this->window);
        this->window = nullptr;
    }
}

void Window::refresh()
{
    SDL_RenderPresent(this->renderer);
}

SDL_Texture* Window::loadImage(std::string filename, bool createCopyOfTexture)
{
    if ( textures.count(filename) == 0 || createCopyOfTexture)
    {
        SDL_Texture* newTexture = nullptr;
        
        SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
        if (loadedSurface == nullptr)
        {
            Log::error(string("Unable to load image" + filename + "! SDL_image Error: " + IMG_GetError()));
            throw "Window::loadImage: Couldn't load image";
        }
        
        newTexture = SDL_CreateTextureFromSurface( this->renderer, loadedSurface );
        if( newTexture == nullptr )
        {
            Log::error(string("Unable to create texture from " + filename + "! SDL_image Error: " + IMG_GetError()));
            throw "Window::loadImage: Couldn't create texture";
        }

        SDL_FreeSurface( loadedSurface );
        
        textures[filename].push_back(newTexture);
    }
    
    return textures[filename].back();
}

void Window::fill(Color color)
{
    SDL_SetRenderDrawColor(this->renderer,
                           color.r(),
                           color.g(),
                           color.b(),
                           color.a());

    SDL_RenderClear(this->renderer);
}

void Window::clear()
{
    this->fill(this->bg_color);
}

void Window::setBackgroundColor(Color color)
{
    bg_color = color;
}



