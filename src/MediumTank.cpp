#include "MediumTank.hpp"

#include "Utils.hpp"
#include "TileManager.hpp"

MediumTank::MediumTank(Window* window, const MazeSolver& mazeSolver) :
    Tank(window, mazeSolver, Sprite(window, "Tanks.png", 1, true), Config::getFloat("mediumtank_velocity", 2.5f), Config::getInt("mediumtank_hp", 6) )
{
    selectPath();
}

void MediumTank::selectPath()
{
    Utils::Random::seed();
    if (Utils::Random::boolean() == true) path = mazeSolver.getLongestPath();
    else path = mazeSolver.getShortestPath();
    
    Utils::getGameCoords(path[currentPathTile], Window::TILE_WIDTH, TileManager::ROW_TILES / TileManager::MENU_TILES ,position.x, position.y);
    setDirection();
    
    Log::debug("Medium tank spawned!\n");
}
