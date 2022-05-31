#include "Firebird.hpp"
#include <cmath>

Firebird::Firebird(int x, int y) :
    Turret(x, y, Sprite("../assets/Turrets.png", 0),
           Config::getInt("firebird_damage", 2),
           Config::getFloat("firebird_reload", 2.0f),
           Config::getFloat("firebird_radius", 200.0f )), part(), redFactor(100)
    
{
}

void Firebird::update()
{
    Turret::update();
}

void Firebird::removeEffectsFromTargetTank()
{
    Turret::removeEffectsFromTargetTank();
    Color curTankColor = targetTank->getSprite()->getColor();
    Color newTankColor = curTankColor + Color(0,redFactor,redFactor);
    targetTank->getSprite()->setColor(newTankColor);
}

void Firebird::render()
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

void Firebird::shoot()
{
    if (targetTank == nullptr) return;
    
    if (!effectsAppliedOnTargetTank)
    {
        Color curTankColor = targetTank->getSprite()->getColor();
        Color newTankColor = curTankColor - Color(0,redFactor,redFactor);
        targetTank->getSprite()->setColor(newTankColor);
        effectsAppliedOnTargetTank = true;
    }
    
    Turret::shoot();
}



