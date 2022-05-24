#include "Tile.hpp"

Tile::Tile(Window* window, int x, int y, TileType type) :
    window(window),
    GameObject(x,y),
    type(type),
    sprite(window, "Tiles.png", (int)type, false)
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

