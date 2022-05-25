#include "Tank.hpp"
#include "Utils.hpp"
#include "TileManager.hpp"

Tank::Tank(const MazeSolver& mazeSolver, const Sprite& sprite, float velocity, int hp) :
    mazeSolver(mazeSolver),
    sprite(sprite),
    MoveableObject(velocity),
    DamageableObject(hp),
    part(),
    timerAfterDeath(2000)
{
}

void Tank::setDirection()
{
    float x1, y1;
    float x2, y2;
    Utils::getGameCoords(path[currentPathTile], Tile::WIDTH, TileManager::ROW_TILES / TileManager::MENU_TILES ,x1, y1);
    Utils::getGameCoords(path[currentPathTile + 1], Tile::WIDTH, TileManager::ROW_TILES / TileManager::MENU_TILES ,x2, y2);
    if (y1 == y2 && x2 > x1) direction = Direction::RIGHT;
    else if (y1 == y2 && x2 < x1) direction = Direction::LEFT;
    else if (y1 < y2 && x2 == x1) direction = Direction::DOWN;
    else if (y1 > y2 && x2 == x1) direction = Direction::UP;
}

void Tank::move()
{
    float x2, y2;
    Utils::getGameCoords(path[currentPathTile + 1], Tile::WIDTH, TileManager::ROW_TILES / TileManager::MENU_TILES, x2, y2);
    
    /* Change direction */
    if ( (direction == Direction::RIGHT && Utils::areEqual(position.x, x2) ) ||
         (direction == Direction::LEFT && Utils::areEqual(position.x, x2) ) ||
         (direction == Direction::UP && Utils::areEqual(position.y, y2) ) ||
         (direction == Direction::DOWN && Utils::areEqual(position.y, y2) ) )
    {
        /* END */
        if (currentPathTile == path.size() - 2) {
            slow(100);
            Player::hp--;
            isActive = false;
            return;
        }
        
        currentPathTile++;
        setDirection();
    }
    
    /* Move position */
    if (direction == Direction::RIGHT) {
        position.x += velocity;
        if (position.x > x2) position.x = x2;
    }
    if (direction == Direction::LEFT) {
        position.x -= velocity;
        if (position.x < x2) position.x = x2;
    }
    if (direction == Direction::UP) {
        position.y -= velocity;
        if (position.y < y2) position.y = y2;
    }
    if (direction == Direction::DOWN) {
        position.y += velocity;
        if (position.y > y2) position.y = y2;
    }
}

void Tank::update()
{
    if (!isDead())
        move();
    else
    {
        if (timerAfterDeath.isDone())
        {
            isActive = false;
        }
    }
}

void Tank::render()
{
    if (!isDead())
        sprite.render(getX(), getY(), direction * 90);
    else
    {
        float x(0.0f), y(0.0f), d(0.0f);
        x = getX() + Tile::WIDTH / 2;
        y = getY() + Tile::WIDTH / 2;
        part.draw(x, y, d);
    }
}

void Tank::destroy()
{
    Player::coins++;
    timerAfterDeath.startCounting();
}

Sprite* Tank::getSprite()
{
    return &sprite;
}
