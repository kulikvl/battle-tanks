#ifndef GameObject_hpp
#define GameObject_hpp

#include "SDL.hpp"

/// \brief Abstract stuff for any kind of game object.
///
/// This class defines basic characteristics to be inherited by any 'game object'
///
class GameObject
{
protected:
    /// Position of the game object.
    SDL_FPoint position;
    
public:
    /// Init gameObject.
    GameObject(float x = 0, float y = 0);
    
    /// Update inner things.
    /// @note Should be called every frame.
    virtual void update() = 0;
    
    /// Update inner things.
    /// @note Should be called every frame.
    virtual void render() = 0;
    
    /// Get X coordinate.
    float getX();
    
    /// Get Y coordinate.
    float getY();
    
    /// Tells if the game object is active
    bool isActive;
};

#endif /* GameObject_hpp */
