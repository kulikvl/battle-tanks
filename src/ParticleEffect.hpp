#ifndef ParticleEffect_hpp
#define ParticleEffect_hpp

#include "ParticleSystem.hpp"
#include "SDL.hpp"
#include "Window.hpp"
#include "Sprite.hpp"

class ParticleEffect : public ParticleSystem
{
private:
    Sprite sprite;
    
public:
    ParticleEffect(Window* window);
    void draw(float x, float y, float angle);
    virtual void initEffect() = 0;
};

#endif /* ParticleEffect_hpp */
