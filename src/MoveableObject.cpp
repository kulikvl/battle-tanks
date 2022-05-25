#include "MoveableObject.hpp"

MoveableObject::MoveableObject(float vel) :
    velocity(vel),
    initialVelocity(vel)
{
    if (vel == 0)
    {
        isMoving = false;
    }
    else
    {
        isMoving = true;
    }
}

void MoveableObject::slow(float v)
{
    velocity -= v;
    
    if (velocity <= 0)
    {
        velocity = 0;
        isMoving = false;
    }
}

void MoveableObject::accelerate(float v)
{
    velocity += v;
    isMoving = true;
}

bool MoveableObject::isIdle()
{
    return !isMoving;
}

float MoveableObject::getCurrentVelocity()
{
    return velocity;
}

float MoveableObject::getInitialVelocity()
{
    return initialVelocity;
}

void MoveableObject::setInitialVelocity()
{
    velocity = initialVelocity;
}
