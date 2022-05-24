#ifndef GameObject_hpp
#define GameObject_hpp

#include "SDL.hpp"

/// \brief Abstract stuff for any kind of game object.
///
/// This class defines basic characteristics to be inherited by any 'game object'
///
class GameObject
{
public:
    SDL_FPoint position;
    
    bool isActive;
    
    GameObject(float x = 0, float y = 0);
    
    virtual void update() = 0;
    
    virtual void render() = 0;
    
    float getX();
    
    float getY();
};

#endif /* GameObject_hpp */
