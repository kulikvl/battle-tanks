#include "LightTank.hpp"

#include "Utils.hpp"
#include "TileManager.hpp"

LightTank::LightTank(const MazeSolver& mazeSolver) :
    Tank(mazeSolver, Sprite("Tanks.png", 0, true), Config::getFloat("lighttank_velocity", 2.5f), Config::getInt("lighttank_hp", 6) )
{
    selectPath();
}

void LightTank::selectPath()
{
    path = mazeSolver.getLongestPath();
    Utils::getGameCoords(path[currentPathTile], Tile::WIDTH, TileManager::ROW_TILES / TileManager::MENU_TILES ,position.x, position.y);
    setDirection();
    
    Log::debug("Light tank spawned!\n");
}
