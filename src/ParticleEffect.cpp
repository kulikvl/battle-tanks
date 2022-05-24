#include "ParticleEffect.hpp"

ParticleEffect::ParticleEffect(Window* window) : sprite(window, "fire.png") {
    setRenderer(window->renderer);
    setTexture(sprite.getTexture());
}

void ParticleEffect::draw(float x, float y, float angle)
{
    setPosition(x, y);
    _angle = angle;
    ParticleSystem::draw();
}
