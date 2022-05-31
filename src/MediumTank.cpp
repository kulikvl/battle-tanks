#include "MediumTank.hpp"

MediumTank::MediumTank(const MazeSolver& mazeSolver) :
    Tank(mazeSolver, Sprite("../assets/Tanks.png", 1, true), Config::getFloat("mediumtank_velocity", 2.5f), Config::getInt("mediumtank_hp", 6) )
{
    selectPath();
}

void MediumTank::selectPath()
{
    Utils::Random::seed();
    if (Utils::Random::boolean() == true) path = mazeSolver.getLongestPath();
    else path = mazeSolver.getShortestPath();
    
    Utils::getGameCoords(path[currentPathTile], Tile::WIDTH, TileManager::ROW_TILES / TileManager::MENU_TILES ,position.x, position.y);
    setDirection();
    
    Log::debug("Medium tank spawned!\n");
}
