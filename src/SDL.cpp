#include "SDL.hpp"
#include "Log.hpp"

/// The whole game is designed for this resolution, that's why it can not be changed.
Window SDL::window = Window(640, 720, "Tower defense");

bool SDL::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        Log::error("SDL::Init() -> Couldn't start SDL VIDEO");
        Log::error(std::string(SDL_GetError()));
        throw "SDL_Init() exception";
    }
    
    if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ))
    {
        Log::warning("Warning: Linear texture filtering not enabled!");
    }
    
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        Log::error("SDL::Init() -> Couldn't start SDL IMG");
        Log::error(std::string(SDL_GetError()));
        throw "IMG_Init() exception";
    }

    return true;
}

void SDL::exit()
{
    Log::debug("Clear resources before exiting...");
    //window.destroy();
    IMG_Quit();
    SDL_Quit();
}
