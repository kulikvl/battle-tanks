#ifndef Smoky_hpp
#define Smoky_hpp

#include "Turret.hpp"
#include "ParticleShotExplosion.cpp"
#include "ParticleShotSmoke.cpp"
#include "TimerCounter.hpp"

/// \brief Another kind of turret
class Smoky : public Turret
{
private:
    ParticleShotExplosion partExplosion;
    ParticleShotSmoke partSmoke;
    
    TimerCounter timerReload;
    
public:
    
    Smoky(Window* window, int x, int y);
    
    virtual void render() override;
};

#endif /* Smoky_hpp */
