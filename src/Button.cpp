#include "Button.hpp"
#include <iostream>

Button::Button(SDL_Point pos) : pos(pos), isSelected(false)
{
    
}

void Button::handleEvent( SDL_Event* e)
{
    if (e->type == SDL_MOUSEBUTTONDOWN)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        
        bool inside = true;
        
        if (x < pos.x) inside = false;
        else if (x > (pos.x + 80)) inside = false;
        else if (y < pos.y) inside = false;
        else if (y > (pos.y + 80)) inside = false;
        
        if (inside) {
            
            isSelected = true;
        }
    }
}

