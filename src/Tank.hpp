#ifndef Tank_hpp
#define Tank_hpp

#include "GameObject.hpp"
#include "MoveableObject.hpp"
#include "DamageableObject.hpp"
#include "Window.hpp"
#include "Sprite.hpp"
#include "MazeSolver.hpp"
#include "ParticleTankExplosion.cpp"
#include "TimerCounter.hpp"
#include "Player.hpp"
#include "Config.hpp"

/// \brief Class that represents enemy as a tank
/// It is moveble, damageable and has main characteristics of standart game object.
class Tank : public GameObject, public MoveableObject, public DamageableObject
{
protected:
    Window* window;
    
    Sprite sprite;
    
    const MazeSolver& mazeSolver;
    
    vector<string> path;
    
    int currentPathTile = 0;
    
    void setDirection();
    
    void move();
    
    virtual void selectPath() = 0;
    
    ParticleTankExplosion part;
    
    TimerCounter timerAfterDeath;

public:
    Tank(Window* window, const MazeSolver& mazeSolver, const Sprite& sprite, float velocity, int hp);
    
    virtual void update() override;
    
    virtual void render() override;
    
    virtual void destroy() override;
    
    Sprite* getSprite();
};

#endif /* Tank_hpp */
