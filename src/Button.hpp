#ifndef Button_hpp
#define Button_hpp

#include "SDL.hpp"
#include "Window.hpp"

/// \brief Class for representing basic button functionality
class Button
{
protected:
    SDL_Point pos;

public:
    Button(SDL_Point pos);
    
    virtual void handleEvent( SDL_Event* e);
    
    bool isSelected;
};

#endif /* Button_hpp */
