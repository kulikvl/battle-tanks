#ifndef SDL_hpp
#define SDL_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

/// \brief Wrapper class on basic SDL2 calls.
///
/// This simply initializes and finishes SDL2.
///
namespace SDL
{
    bool init();
    void exit();
};

#endif /* SDL_hpp */
