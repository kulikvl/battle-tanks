#include "HeavyTank.hpp"

HeavyTank::HeavyTank(const MazeSolver& mazeSolver) :
    Tank(mazeSolver, Sprite("assets/Tanks.png", 2, true), Config::getFloat("heavytank_velocity", 2.5f), Config::getInt("heavytank_hp", 6) )
{
    selectPath();
}

void HeavyTank::selectPath()
{
    path = mazeSolver.getShortestPath();
    Utils::getGameCoords(path[currentPathTile], Tile::WIDTH, TileManager::ROW_TILES / TileManager::MENU_TILES ,position.x, position.y);
    setDirection();
    
    Log::debug("Heavy tank spawned!");
}
