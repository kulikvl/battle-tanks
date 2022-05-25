#ifndef Firebird_hpp
#define Firebird_hpp

#include "Turret.hpp"
#include "ParticleFire.cpp"
#include "Tank.hpp"

/// \brief Another kind of turret
class Firebird : public Turret
{
private:
    ParticleFire part;
    uint8_t redFactor;
    
    virtual void removeEffectsFromTargetTank() override;
    
public:

    Firebird(int x, int y);

    virtual void update() override;
    
    virtual void render() override;
   
    virtual void shoot() override;
};

#endif /* Firebird_hpp */
