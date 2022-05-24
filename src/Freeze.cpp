#include "Freeze.hpp"

Freeze::Freeze(Window* window, int x, int y) :
    Turret(window, x, y, Sprite(window, "Turrets.png", 1),
           Config::getInt("freeze_damage", 2),
           Config::getFloat("freeze_reload", 2.0f),
           Config::getFloat("freeze_radius", 200.0f )), part(window), slowdownFactor(3.0f), blueFactor(100)
{
}

void Freeze::update()
{
    Turret::update();
}

void Freeze::removeEffectsFromTargetTank()
{
    Turret::removeEffectsFromTargetTank();
    
    targetTank->accelerate(targetTank->getInitialVelocity() / slowdownFactor);
    
    Color curTankColor = targetTank->getSprite()->getColor();
    Color newTankColor = curTankColor + Color(blueFactor,blueFactor,0);
    targetTank->getSprite()->setColor(newTankColor);
}

void Freeze::render()
{
    Turret::render();
    
    float x(0.0f), y(0.0f), d(0.0f);
    
    getCoordsOfGunpoint(x,y,d);
    
    if (targetTank != nullptr)
    {
        if (part.isPaused())
        {
            part.resumeEmissions();
        }
    }
    else
    {
        if (!part.isPaused())
        {
            part.pauseEmissions();
        }
    }
    
    part.draw(x, y, d);
}

void Freeze::shoot()
{
    if (targetTank == nullptr) return;
    
    if (!effectsAppliedOnTargetTank)
    {
        targetTank->slow(targetTank->getInitialVelocity() / slowdownFactor);
        
        Color curTankColor = targetTank->getSprite()->getColor();
        Color newTankColor = curTankColor - Color(blueFactor,blueFactor,0);
        targetTank->getSprite()->setColor(newTankColor);
        
        effectsAppliedOnTargetTank = true;
    }
    
    Turret::shoot();
}
