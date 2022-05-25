#include "DamageableObject.hpp"

DamageableObject::DamageableObject(int initialHp):
    isAlive(true),
    hp(initialHp)
{
}

int DamageableObject::getHitpoints()
{
    return hp;
}

bool DamageableObject::isDead()
{
    return !isAlive;
}

void DamageableObject::heal(int d)
{
    hp += d;
}

void DamageableObject::damage(int d)
{
    hp -= d;
    
    if (hp <= 0)
    {
        hp = 0;
        isAlive = false;
        destroy();
    }
}
