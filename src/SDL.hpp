#ifndef SDL_hpp
#define SDL_hpp

#if __APPLE__
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
#endif

#include "Window.hpp"

/// \brief Wrapper class on basic SDL2 calls.
///
/// This simply initializes and finishes SDL2.
/// @note Also it contains the 'main window', on which the whole game is displayed
///
struct SDL
{
    static bool init();
    static void exit();
    static Window window;
};

#endif /* SDL_hpp */
