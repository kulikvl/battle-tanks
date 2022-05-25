#include "Tile.hpp"

Tile::Tile(int x, int y, TileType type) :
    GameObject(x,y),
    type(type),
    sprite("Tiles.png", (int)type, false)
{
}

void Tile::update()
{
    
}

void Tile::render()
{
    sprite.render(getX(), getY());
}

TileType Tile::getType()
{
    return type;
}

