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
    /// Special particle effect for this turret.
    ParticleShotExplosion partExplosion;
    
    /// Special particle effect for this turret.
    ParticleShotSmoke partSmoke;
    
    /// Particle timer (frequency of effects applied on tank and turret).
    TimerCounter timerParticle;
    
public:
    
    Smoky(int x, int y);
    
    virtual void render() override;
};

#endif /* Smoky_hpp */
