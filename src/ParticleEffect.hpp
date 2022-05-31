#ifndef ParticleEffect_hpp
#define ParticleEffect_hpp

#include "ParticleSystem.hpp"
#include "SDL.hpp"
#include "Sprite.hpp"

class ParticleEffect : public ParticleSystem
{
private:
    /// Particle image.
    Sprite sprite;
    
public:
    /// Init.
    ParticleEffect();
    
    /// Draw particle.
    void draw(float x, float y, float angle);
    
    virtual void initEffect() = 0;
};

#endif /* ParticleEffect_hpp */
