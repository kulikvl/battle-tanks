#include "SDL.hpp"

bool SDL::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        Log::error("SDL_Init: Couldn't start SDL");
        Log::error(std::string(SDL_GetError()));
        throw "SDL_Init exception";
    }
    
    if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ))
    {
        Log::warning("Warning: Linear texture filtering not enabled!");
    }
    
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        Log::error("SDL_Init: Couldn't start SDL");
        Log::error(std::string(SDL_GetError()));
        throw "IMG_Init exception";
    }

    return true;
}

void SDL::exit()
{
    IMG_Quit();
    SDL_Quit();
}
