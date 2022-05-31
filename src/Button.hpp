#ifndef Button_hpp
#define Button_hpp

#include "SDL.hpp"

/// \brief Class for representing basic button functionality
class Button
{
public:
    virtual void handleEvent( SDL_Event* e ) = 0;
    
    bool isSelected = false;
};

#endif /* Button_hpp */
