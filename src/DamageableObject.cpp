#include "DamageableObject.hpp"
#include "Log.hpp"

DamageableObject::DamageableObject(int initialHp) :
    isAlive(true),
    hp(initialHp)
{
}

void DamageableObject::heal(int d)
{
    if (d < 0)
    {
        Log::error("DamageableObject::heal() -> Fail to heal with negative number!");
        return;
    }
    
    hp += d;
}

void DamageableObject::damage(int d)
{
    if (d < 0)
    {
        Log::error("DamageableObject::damage() -> Fail to damage with negative number!");
        return;
    }
    
    hp -= d;
    
    if (hp <= 0)
    {
        hp = 0;
        isAlive = false;
        destroy();
    }
}

bool DamageableObject::isDead() const
{
    return !isAlive;
}

int DamageableObject::getHitpoints() const
{
    return hp;
}
