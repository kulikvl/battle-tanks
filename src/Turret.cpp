#include "Turret.hpp"

Turret::Turret(int x, int y, const Sprite& sprite, int damage, float reload, float radius) :
    GameObject(x,y),
    sprite(sprite),
    ShootableObject(damage, reload, radius),
    targetTank(nullptr),
    rotation(0.0f),
    reloadTimer(reload * 1000)
{
    reloadTimer.startCounting();
}

void Turret::update()
{
    if (targetTank != nullptr)
    {
        float A = sqrt( (targetTank->getY() - getY()) * (targetTank->getY() - getY()) );
        float C = distanceToTargetTank;
        float Cos = A / C;
        rotation = acos(Cos) * 180.0f / M_PI;
        if (targetTank->getY() >= getY()) {
            rotation -= 180.0f;
            if (targetTank->getX() <= getX()) rotation *= -1.0;
        }
        else if (targetTank->getX() >= getX() && targetTank->getY() <= getY()) {
            rotation *= -1.0f;
        }
    }
}

void Turret::render()
{
    sprite.render(getX(), getY(), -90.0f - rotation);
}

void Turret::removeEffectsFromTargetTank()
{
    effectsAppliedOnTargetTank = false;
}

void Turret::shoot()
{
    if (targetTank != nullptr && !targetTank->isDead() && reloadTimer.isDone())
    {
        //Log::debug("SHOOT! - " + to_string(effectsAppliedOnTargetTank) );
        targetTank->damage(damage);
        reloadTimer.startCounting();
    }
}

void Turret::findTargetTank(vector<shared_ptr<Tank> >& tanks)
{
    if (targetTank != nullptr)
    {
        if (targetTank->isActive == false)
        {
            Turret::removeEffectsFromTargetTank();
            targetTank = nullptr;
        }
        else
        {
            /* check if current target tank is still in active radius */
            if (!targetTank->isDead())
            {
                float distToTargetTank = sqrt( (targetTank->getX() - getX()) * (targetTank->getX() - getX()) + (targetTank->getY() - getY()) * (targetTank->getY() - getY()) );
                
                if (distToTargetTank < radius)
                {
                    distanceToTargetTank = distToTargetTank;
                    return;
                }
                else
                {
                    removeEffectsFromTargetTank();
                    targetTank = nullptr;
                }
            }
            else
            {
                removeEffectsFromTargetTank();
                targetTank = nullptr;
            }
        }
    }
    
    //if (effectsAppliedOnTargetTank == true) Log::error("should not be applied!");

    distanceToTargetTank = MAXFLOAT;
    float currentDistance = MAXFLOAT;

    for (size_t i = 0; i < tanks.size(); ++i)
    {
        if (tanks[i]->isDead() || !tanks[i]->isActive) continue;
        
        currentDistance = sqrt( (tanks[i]->getX() - getX()) * (tanks[i]->getX() - getX()) + (tanks[i]->getY() - getY()) * (tanks[i]->getY() - getY()) );
        if (currentDistance < radius && currentDistance < distanceToTargetTank)
        {
            distanceToTargetTank = currentDistance;
            targetTank = tanks[i].get();
        }
    }
}

void Turret::getCoordsOfGunpoint(float& x, float& y, float& d)
{
    /*
     Rotation
     topLeft    - [90,0],
     topRight   - [0,-90],
     botRight   - [-90,-180],
     botLeft    - [-180, 90]
     */
    
    /*
     For ease of understanding the code and taking into account the fact that the size of one block will not change,
     we use constant numbers, where 40 is half the length of the block, 80 is the length of the block
     WARNING: change the code if the length of the block chages
     */
    
    float degreesToAxisY = abs(rotation);
    if (degreesToAxisY > 90.0f)
    {
        degreesToAxisY = fmod(degreesToAxisY, 90.0f);
        degreesToAxisY = 90.0f - degreesToAxisY;
    }
    
    
    float tangens = tan(abs(degreesToAxisY) * M_PI / 180.0f);
    
    float xNormal = (40.0f * tangens * sqrt(tangens*tangens + 1)) / (tangens*tangens + 1);
    float yNormal = sqrt(40.0f * 40.0f - xNormal * xNormal);
    
    float xReal = 0.0f;
    float yReal = 0.0f;
    
    if (Utils::areEqual(xNormal, 0.0f) || Utils::areEqual(xNormal, 40.0f))
    {
        if (Utils::areEqual(xNormal, 40.0f) && rotation < -0.0f && rotation > -180.0f)
            xReal = 80.0f;
        else
            xReal = 40.0f;
        
    }
    else
    {
        if (rotation > 0.0f)
            xReal = 0.0f + (40 - xNormal);
        else if (rotation < -0.0f)
            xReal = 40 +  (xNormal);
    }
    
    if (Utils::areEqual(abs(rotation), 180.0f))
    {
        yReal = 80.0f;
    }
    else
    {
        if (rotation > 0.0f)
        {
            if (rotation > 90.0f)
                yReal = 40.0f + yNormal;
            else
                yReal = 40.0f - yNormal;
        }
        else if (rotation < -0.0f)
        {
            if (rotation < -90.0f)
                yReal = 40.0f + yNormal;
            else
                yReal = 40.0f - yNormal;
        }
    }
    
    //cout << rotation << " " << xReal << "," << yReal << endl;
    
    float angle = -rotation + 90.0f;
    
    x = getX() + xReal;
    y = getY() + yReal;
    d = angle;
}
