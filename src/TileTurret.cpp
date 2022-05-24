#include "TileTurret.hpp"

TileTurret::TileTurret(Window* window, int x, int y, TileType type) :
    Tile(window, x, y, type),
    Button({x,y})
{
}

void TileTurret::update()
{
    if (hasTurret)
    {
        type = TileType::TURRET;
        sprite = Sprite(window, "Tiles.png", (int)TileType::ROAD);
    }
    else if (isSelected && type == TileType::TURRET)
    {
        type = TileType::TURRET_SELECT;
        sprite = Sprite(window, "Tiles.png", (int)type);
    }
    else if (!isSelected && type == TileType::TURRET_SELECT)
    {
        type = TileType::TURRET;
        sprite = Sprite(window, "Tiles.png", (int)type);
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
