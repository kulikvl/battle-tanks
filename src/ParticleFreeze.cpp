#include "ParticleEffect.hpp"

class ParticleFreeze : public ParticleEffect
{
public:
    ParticleFreeze(Window* window) : ParticleEffect(window)
    {
        initEffect();
    }

    virtual void initEffect() override
    {
        
        setPosition(0, 0);
        
        setStartSpin(0);
        setStartSpinVar(90);
        setEndSpin(90);
        setStartSpinVar(90);
        
        initWithTotalParticles(400);

        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        this->_emitterMode = Mode::GRAVITY;

        // Gravity Mode: gravity
        this->modeA.gravity = { 0, 0 };

        // Gravity Mode: radial acceleration
        this->modeA.radialAccel = 25.0f;
        this->modeA.radialAccelVar = 5.0f;

        // Gravity Mode: speed of particles
        this->modeA.speed = -60;
        this->modeA.speedVar = 20;

        // starting angle
        _angle = 90;
        _angleVar = 10;

        // life of particles
        _life = 2.0f;
        _lifeVar = 0.25f;

        // size, in pixels
        _startSize = 15.0f;
        _startSizeVar = 7.5f;
        //_endSize = START_SIZE_EQUAL_TO_END_SIZE;
        _endSize = 25.0f;

        // emits per frame
        _emissionRate = _totalParticles / _life;

        // color of particles
        _startColor.r = 0.35f;
        _startColor.g = 0.70f;
        _startColor.b = 0.98f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.0f;
        _startColorVar.g = 0.0f;
        _startColorVar.b = 0.0f;
        _startColorVar.a = 0.0f;
        _endColor.r = 0.99f;
        _endColor.g = 0.99f;
        _endColor.b = 0.99f;
        _endColor.a = 0.0f;
        _endColorVar.r = 0.2f;
        _endColorVar.g = 0.0f;
        _endColorVar.b = 0.0f;
        _endColorVar.a = 0.0f;

        _posVar = { 1.0f, 3.0f };
        
    }
};



