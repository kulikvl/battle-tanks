#include "Tile.hpp"

Tile::Tile(int x, int y, Type type) :
    GameObject(x,y),
    type(type),
    sprite("assets/Tiles.png", (int)type, false)
{
}

void Tile::update()
{
    
}

void Tile::render()
{
    sprite.render(getX(), getY());
}

Tile::Type Tile::getType()
{
    return type;
}

