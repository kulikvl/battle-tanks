#include "ParticleEffect.hpp"

class ParticleTankExplosion : public ParticleEffect
{
public:
    ParticleTankExplosion(Window* window) : ParticleEffect(window)
    {
        initEffect();
    }

    virtual void initEffect() override
    {
        initWithTotalParticles(500);

        // duration
        _duration = 0.15f;

        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0, 0));

        // Gravity Mode: speed of particles
        setSpeed(-70);
        setSpeedVar(40);

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(0);

        // angle
        _angle = 90;
        _angleVar = 360;

        // life of particles
        _life = 0.87f;
        _lifeVar = 0.2f;

        // size, in pixels
        _startSize = 15.0f;
        _startSizeVar = 5.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = _totalParticles / _duration;

        // color of particles
        _startColor.r = 1.0f;
        _startColor.g = 0.6f;
        _startColor.b = 0.2f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.1f;
        _startColorVar.g = 0.1f;
        _startColorVar.b = 0.1f;
        _startColorVar.a = 0.0f;
        _endColor.r = 0.1f;
        _endColor.g = 0.1f;
        _endColor.b = 0.1f;
        _endColor.a = 0.0f;
        _endColorVar.r = 0.1f;
        _endColorVar.g = 0.1f;
        _endColorVar.b = 0.1f;
        _endColorVar.a = 0.0f;

        _posVar = { 0, 0 };
        
    }
};



