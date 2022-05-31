#include "Window.hpp"
#include "GameObject.hpp"
#include "Sprite.hpp"

class Heart : public GameObject
{
private:
    /// Image of red heart.
    Sprite imageRedHeart;
    
    /// Image of black heart.
    Sprite imageBlackHeart;
    
public:
    bool isRed = true;
    
    Heart(int x, int y) :
        GameObject(x,y),
        imageRedHeart("../assets/Tab.png", 1),
        imageBlackHeart("../assets/Tab.png", 2)
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
