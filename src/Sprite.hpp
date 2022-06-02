#ifndef Sprite_hpp
#define Sprite_hpp

#include "SDL.hpp"
#include "Color.hpp"

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
    
    /// Width of the texture.
    int width;
    
    /// Height of the texture.
    int height;
    
    /// Order in the atlas image.
    int atlasIndex;
    
    /// Color of the texture.
    Color color;
    
    /// @note It's appropriate to allow ParticleEffect class access internal things of the sprite.
    friend class ParticleEffect;
    
    /// Return a pointer to the texture, which this current sprite is using.
    SDL_Texture* getTexture();
    
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
    
    /// Color will be applied on the texture.
    /// @note If the texture for this sprite was NOT created as a copy, and there are sprites, that are also using this texture, then color keying will be applied on all the sprites using this texture.
    void setColor( Color color );
    
    /// Get current color of the texture.
    Color getColor();

};

#endif /* Sprite_hpp */
