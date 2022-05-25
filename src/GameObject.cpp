#include "GameObject.hpp"

GameObject::GameObject(float x, float y) :
    position{x,y},
    isActive(true)
{
}

float GameObject::getX()
{
    return position.x;
}

float GameObject::getY()
{
    return position.y;
}
