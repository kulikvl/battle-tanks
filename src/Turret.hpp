#ifndef Turret_hpp
#define Turret_hpp

#include "GameObject.hpp"
#include "Tank.hpp"
#include "ShootableObject.hpp"
#include "Window.hpp"
#include "Sprite.hpp"
#include "TimerCounter.hpp"

/// \brief Class that represents defense tower
/// So it can shoot and has main characteristics of standart game object.
class Turret : public GameObject, public ShootableObject
{
protected:
    Sprite sprite;
    
    Tank* targetTank;
    
    float distanceToTargetTank;
    
    float rotation;
    
    TimerCounter reloadTimer;
    
    virtual void removeEffectsFromTargetTank();
    
    bool effectsAppliedOnTargetTank = false;

public:
    Turret(int x, int y, const Sprite& sprite, int damage, float reload, float radius);
    
    virtual void update() override ;
    
    virtual void render() override ;
    
    virtual void shoot() override ;
    
    /// Find closest tank
    void findTargetTank(vector<shared_ptr<Tank> >& tanks);
    
    /// Use formula x^2 + y^2 = r^2 a then calculate real in-game coordinates of the end of gun (where it fires)
    void getCoordsOfGunpoint(float& x, float& y, float& d);
    
};

#endif /* Turret_hpp */
