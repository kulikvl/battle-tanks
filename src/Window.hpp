#ifndef Window_hpp
#define Window_hpp

#include <string>
#include <map>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "Color.hpp"
#include "Timer.hpp"

using namespace std;

/// \brief The main (and only) window of the program.
///
/// Wraps low-level SDL video functions that interfaces with the
/// Operational System's Window Manager.
///
/// Here we set things like fullscreen, window position, size, etc.
class Window
{
private:
    /// background color
    Color bg_color;
    
    /// all textures used in the game
    map<string, vector<SDL_Texture*> > textures;
    
public:
    /// Initializes the program's window with *width*, *height*
    /// and the text that should appear on the program's window
    /// (*title*).
    Window(unsigned int width, unsigned int height, std::string title = "Unnamed");

    /// Frees resources
    virtual ~Window();

    /// Destroys everything on the window and itself.
    /// Can be recreated with `Window::resize`.
    void destroy();

    /// Destroys everything on the window and itself.
    /// Can be recreated with `Window::resize`.
    SDL_Texture* loadImage(std::string filename, bool createCopyOfTexture = false);

    /// Effectively draws everything that's onscreen.
    /// @note Need to be called constantly.
    void refresh();

    /// Fills the whole Window with `color`.
    void fill(Color color);

    /// Clears whole window to the background color #bg_color.
    void clear();

    /// Sets the background color to a RGB-formatted color.
    ///
    /// @note Affects clearScreen().
    void setBackgroundColor(Color color = Color(0, 0, 0));

    /// SDL's internal data structure that represents the window.
    SDL_Window* window;

    /// SDL's internal data structure to which we render textures.
    SDL_Renderer* renderer;
    
    /// Width of the tile in the game
    static const int TILE_WIDTH = 80;

};


#endif /* Window_hpp */