#include "Window.hpp"
#include "GameObject.hpp"
#include "Sprite.hpp"

class Coin : public GameObject
{
private:
    /// Image of the coin.
    Sprite image;
    
public:
    bool show = false;
    
    Coin( int x, int y) :
        GameObject(x,y),
        image("../assets/Tab.png", 0)
    {
    
    }
    
    virtual void update() override
    {
    }
    
    virtual void render() override
    {
        if (show)
        {
            image.render(getX(), getY());
        }
    }
};
