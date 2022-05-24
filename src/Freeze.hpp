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
    ParticleFreeze part;
    float slowdownFactor;
    uint8_t blueFactor;
    
    virtual void removeEffectsFromTargetTank() override;
    
public:
    Freeze(Window* window, int x, int y);

    virtual void update() override;
    
    virtual void render() override;
    
    virtual void shoot() override;
};

#endif /* Freeze_hpp */
