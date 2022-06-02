#ifndef Freeze_hpp
#define Freeze_hpp

#include "Turret.hpp"
#include "ParticleFreeze.cpp"
#include "Tank.hpp"
#include "TimerCounter.hpp"

/// \brief Another kind of turret
class Freeze : public Turret
{
private:
    /// Special particle effect for this turret.
    ParticleFreeze part;
    
    /// Tells how slow the attacked tank will be.
    float slowdownFactor;
    
    /// Tells how blue the attacked tank will be.
    uint8_t blueFactor;
    
    virtual void removeEffectsFromTargetTank() override;
    
public:
    Freeze(int x, int y);
    
    virtual void render() override;
    
    virtual void shoot() override;
};

#endif /* Freeze_hpp */
