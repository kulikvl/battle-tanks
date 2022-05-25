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
    
    Heart(int x, int y) :
        GameObject(x,y),
        imageRedHeart("Tab.png", 1),
        imageBlackHeart("Tab.png", 2)
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
