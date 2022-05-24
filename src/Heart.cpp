#include <stdio.h>
#include "Window.hpp"
#include "GameObject.hpp"
#include "Sprite.hpp"

class Heart : public GameObject
{
private:
    Sprite imageRedHeart;
    Sprite imageBlackHeart;
    
public:
    bool isRed = true;
    
    Heart(Window* window, int x, int y) :
        GameObject(x,y),
        imageRedHeart(window, "Tab.png", 1),
        imageBlackHeart(window, "Tab.png", 2)
    {
        
    }
    
    virtual void update() override
    {
    }
    
    virtual void render() override
    {
        if (isRed)
        {
            imageRedHeart.render(getX(), getY());
        }
        else
        {
            imageBlackHeart.render(getX(), getY());
        }
    }
};
