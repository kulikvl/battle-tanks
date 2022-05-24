#include "MoveableObject.hpp"

MoveableObject::MoveableObject(float vel) : velocity(vel), initialVelocity(vel)
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
    this->velocity -= v;
    
    if (this->velocity <= 0)
    {
        this->velocity = 0;
        this->isMoving = false;
    }
}

void MoveableObject::accelerate(float v)
{
    this->velocity += v;
    this->isMoving = true;
}

bool MoveableObject::isIdle()
{
    return !(this->isMoving);
}

float MoveableObject::getCurrentVelocity()
{
    return this->velocity;
}

float MoveableObject::getInitialVelocity()
{
    return this->initialVelocity;
}

void MoveableObject::setInitialVelocity()
{
    this->velocity = this->initialVelocity;
}
