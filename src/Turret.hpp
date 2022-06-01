#ifndef Turret_hpp
#define Turret_hpp

#include "GameObject.hpp"
#include "ShootableObject.hpp"
#include "Tank.hpp"
#include "Sprite.hpp"
#include "TimerCounter.hpp"
#include "Utils.hpp"
#include "Config.hpp"

/// \brief Class that represents defense tower.
///
/// So it can shoot and has main characteristics of standart game object.
///
class Turret : public GameObject, public ShootableObject
{
protected:
    /// Image of the turret.
    Sprite sprite;
    
    /// Attacked tank.
    Tank* targetTank;
    
    /// Distance to the attacked tank.
    float distanceToTargetTank;
    
    /// Turret current rotation.
    float rotation;
    
    /// Timer for reloading.
    TimerCounter reloadTimer;
    
    /// If any effects of this turret applied to the attacked tank.
    bool effectsAppliedOnTargetTank = false;
    
    /// Removes all efects of current turret applied to the target tank.
    virtual void removeEffectsFromTargetTank();

public:
    /// Init everything.
    Turret(int x, int y, const Sprite& sprite, int damage, float reload, float radius);
    
    virtual void update() override;
    
    virtual void render() override;
    
    virtual void shoot() override;
    
    /// Find closest tank from the vector of all tanks in the scene.
    void findTargetTank(vector<shared_ptr<Tank> >& tanks);
    
    /// Use formula x^2 + y^2 = r^2 a then calculate real in-game coordinates of the end of gun (where it fires).
    void getCoordsOfGunpoint(float& x, float& y, float& d);
    
};

#endif /* Turret_hpp */
