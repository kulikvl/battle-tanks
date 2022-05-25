#include "ParticleEffect.hpp"

class ParticleShotSmoke : public ParticleEffect
{
public:
    ParticleShotSmoke()
    {
        initEffect();
    }

    virtual void initEffect() override
    {
        initWithTotalParticles(300);

        // duration
        _duration = 0.04f;

        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0, 0));

        // Gravity Mode: speed of particles
        setSpeed(-15);
        setSpeedVar(5);

        // Gravity Mode: radial
        setRadialAccel(20.0f);
        setRadialAccelVar(1.0f);

        // Gravity Mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(0);

        // angle
        _angle = 90;
        _angleVar = 360;

        // life of particles
        _life = 0.8f;
        _lifeVar = 0.1f;

        // size, in pixels
        _startSize = 10.0f;
        _startSizeVar = 1.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = _totalParticles / _duration;

        // color of particles
        _startColor.r = 0.88f;
        _startColor.g = 0.40f;
        _startColor.b = 0.09f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.05f;
        _startColorVar.g = 0.05f;
        _startColorVar.b = 0.05f;
        _startColorVar.a = 0.0f;
        _endColor.r = 0.0f;
        _endColor.g = 0.0f;
        _endColor.b = 0.0f;
        _endColor.a = 0.0f;
        _endColorVar.r = 0.0f;
        _endColorVar.g = 0.0f;
        _endColorVar.b = 0.0f;
        _endColorVar.a = 0.0f;

        _posVar = { 0, 0 };
        
    }
};




