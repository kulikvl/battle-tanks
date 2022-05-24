#include "Smoky.hpp"

Smoky::Smoky(Window* window, int x, int y) :
    Turret(window, x, y, Sprite(window, "Turrets.png", 2),
           Config::getInt("smoky_damage", 2),
           Config::getFloat("smoky_reload", 2.0f),
           Config::getFloat("smoky_radius", 200.0f )), partExplosion(window), partSmoke(window),
    timerReload(reload * 1000)
    
{
    timerReload.startCounting();
}


void Smoky::render()
{
    if (targetTank != nullptr)
    {
        float x(0.0f), y(0.0f), d(0.0f);
        x = targetTank->getX() + Window::TILE_WIDTH / 2;
        y = targetTank->getY() + Window::TILE_WIDTH / 2;
        partExplosion.draw(x, y, d);
        
        getCoordsOfGunpoint(x, y, d);
        partSmoke.draw(x, y, d);
        
        if (!partExplosion.isActive() && timerReload.isDone())
        {
            partExplosion.resetSystem();
            partSmoke.resetSystem();
            timerReload.startCounting();
        }
        
    }

    Turret::render();
}

