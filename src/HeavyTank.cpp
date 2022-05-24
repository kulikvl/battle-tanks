#include "HeavyTank.hpp"

#include "Utils.hpp"
#include "TileManager.hpp"

HeavyTank::HeavyTank(Window* window, const MazeSolver& mazeSolver) :
    Tank(window, mazeSolver, Sprite(window, "Tanks.png", 2, true), Config::getFloat("heavytank_velocity", 2.5f), Config::getInt("heavytank_hp", 6) )
{
    selectPath();
}

void HeavyTank::selectPath()
{
    path = mazeSolver.getShortestPath();
    Utils::getGameCoords(path[currentPathTile], Window::TILE_WIDTH, TileManager::ROW_TILES / TileManager::MENU_TILES ,position.x, position.y);
    setDirection();
    
    Log::debug("Heavy tank spawned!\n");
}
