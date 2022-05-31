#include "TileTurret.hpp"

TileTurret::TileTurret(int x, int y, Tile::Type type) :
    Tile(x, y, type),
    Button(),
    hasTurret(false)
{
}

void TileTurret::update()
{
    if (hasTurret)
    {
        type = Tile::Type::TURRET;
        sprite = Sprite("../assets/Tiles.png", (int)Tile::Type::ROAD);
    }
    else if (isSelected && type == Tile::Type::TURRET)
    {
        type = Tile::Type::TURRET_SELECT;
        sprite = Sprite("../assets/Tiles.png", (int)type);
    }
    else if (!isSelected && type == Tile::Type::TURRET_SELECT)
    {
        type = Tile::Type::TURRET;
        sprite = Sprite("../assets/Tiles.png", (int)type);
    }
}

void TileTurret::handleEvent( SDL_Event* e)
{
    if (hasTurret) return;
    
    if (e->type == SDL_MOUSEBUTTONDOWN)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        
        bool inside = true;
        
        if (x < getX()) inside = false;
        else if (x > (getX() + Tile::WIDTH)) inside = false;
        else if (y < getY()) inside = false;
        else if (y > (getY() + Tile::WIDTH)) inside = false;
        
        if (inside)
        {
            isSelected = true;
        }
    }
}
