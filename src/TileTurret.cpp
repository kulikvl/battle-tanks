#include "TileTurret.hpp"

TileTurret::TileTurret(int x, int y, Tile::Type type) :
    Tile(x, y, type),
    Button({x,y})
{
}

void TileTurret::update()
{
    if (hasTurret)
    {
        type = Tile::Type::TURRET;
        sprite = Sprite("Tiles.png", (int)Tile::Type::ROAD);
    }
    else if (isSelected && type == Tile::Type::TURRET)
    {
        type = Tile::Type::TURRET_SELECT;
        sprite = Sprite("Tiles.png", (int)type);
    }
    else if (!isSelected && type == Tile::Type::TURRET_SELECT)
    {
        type = Tile::Type::TURRET;
        sprite = Sprite("Tiles.png", (int)type);
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
        
        if (x < pos.x) inside = false;
        else if (x > (pos.x + 80)) inside = false;
        else if (y < pos.y) inside = false;
        else if (y > (pos.y + 80)) inside = false;
        
        if (inside) {
            
            isSelected = true;
        }
    }
}
