#ifndef Sprite_hpp
#define Sprite_hpp

#include "SDL.hpp"
#include "Color.hpp"
#include "Window.hpp"

using namespace std;

/// \brief Shows a single image onscreen.
///
/// This class opens an image and can be used to print it completely
/// or just a part of it.
///
/// @note Keep in mind you should refresh the screen to see any changes.
///
class Sprite
{
private:
    /// SDL's internal thingy that holds the image data.
    SDL_Texture* image;

    /// Order in the atlas image.
    int atlasIndex;
    
    int width;
    int height;
    
    Color color;
    
public:
    /// Creates and loads a new sprite from `filename` on main window.
    Sprite(string filename, int atlasIndex = -1, bool createCopyOfImage = false);
    
    /// Places the sprite on `x` and `y` of it's `window`.
    ///
    /// @note Don't forget to refresh the `Window`.
    ///
    void render(float x, float y, float angle = 0.0f, SDL_FPoint* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    /// Returns the width of the sprite image on pixels.
    int getWidth();

    /// Returns the height of the sprite image on pixels.
    int getHeight();
    
    SDL_Texture* getTexture();
    
    void setColor( Color color );
    
    Color getColor();

};


#endif /* Sprite_hpp */
