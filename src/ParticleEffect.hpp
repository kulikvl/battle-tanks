#ifndef ParticleEffect_hpp
#define ParticleEffect_hpp

#include "ParticleSystem.hpp"
#include "SDL.hpp"
#include "Sprite.hpp"

/// @brief Parent class for every specific particle effect.
class ParticleEffect : public ParticleSystem
{
protected:
    /// Particle image.
    Sprite sprite;
    
    /// Init effect with customized particle settings.
    ParticleEffect();
    
public:
    /// Draw particle.
    void draw(float x, float y, float angle);

};

#endif /* ParticleEffect_hpp */
