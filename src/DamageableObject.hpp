#ifndef DamageableObject_hpp
#define DamageableObject_hpp

/// \brief An object that possesses hitpoints and can "die".
///
/// This class defines characteristics to be inherited by something
/// that may be able to die.
///
class DamageableObject
{
protected:
    bool isAlive; ///< Is it alive?
    int  hp;      ///< Hitpoints.

public:
    /// Creates damageable object with initial ammount of hitpoints.
    DamageableObject(int initialHp);

    /// Heals a Planet's hitpoints.
    void heal(int d);

    /// Deals a damage to the object's hitpoints.
    /// @note Hitpoints are padded at zero (no negative hitpoints allowed).
    void damage(int d);

    /// Tells if it have been destroyed.
    bool isDead();

    /// Return ammount of hitpoints left.
    int getHitpoints();
    
    /// Method called on destruction of the object
    virtual void destroy() = 0;
    
};

#endif /* DamageableObject_hpp */
