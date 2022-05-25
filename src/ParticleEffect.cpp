#include "ParticleEffect.hpp"

ParticleEffect::ParticleEffect() : sprite("fire.png") {
    setRenderer(SDL::window.renderer);
    setTexture(sprite.getTexture());
}

void ParticleEffect::draw(float x, float y, float angle)
{
    setPosition(x, y);
    _angle = angle;
    ParticleSystem::draw();
}
