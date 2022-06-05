#ifndef Window_hpp
#define Window_hpp

#include <string>
#include <map>
#include <vector>

#if __APPLE__
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
#endif

#include "Color.hpp"

using namespace std;

/// \brief The main (and only) window of the program.
///
/// Wraps low-level SDL video functions that interfaces with the
/// Operational System's Window Manager.
///
/// Here we set things like fullscreen, window position, size, etc.
class Window
{
public:
    /// SDL's internal data structure that represents the window.
    SDL_Window* window;

    /// SDL's internal data structure to which we render textures.
    SDL_Renderer* renderer;
    
private:
    /// Background color
    Color bg_color;
    
    /// All textures used in the game
    map<string, vector<SDL_Texture*> > textures;
    
public:
    /// Initializes the program's window with *width*, *height*
    /// and the text that should appear on the program's window
    /// (*title*).
    Window(unsigned int width, unsigned int height, string title = "Unnamed");

    /// Frees resources
    ~Window();

    /// Destroys everything on the window and itself.
    /// Can be recreated with `Window::resize`.
    void destroy();

    /// Destroys everything on the window and itself.
    /// Can be recreated with `Window::resize`.
    /// \param[in] createCopyOfTexture if true, creates a copy and pushes it to the vector of the same textures (needed for colorkeying)
    SDL_Texture* loadImage(string filename, bool createCopyOfTexture = false);

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
    
};

#endif /* Window_hpp */
