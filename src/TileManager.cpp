#include "TileManager.hpp"

#include "Config.hpp"

#include <fstream>
#include <exception>
#include <cstdlib>
#include <algorithm>

TileManager::TileManager() 
{
    fill();
}

vector<int> TileManager::readMap(string inFileName)
{
    ifstream inputFile(inFileName);
    
    if ( inputFile.fail() )
    {
        Log::error("TileManager::readMap() -> Failed to open the map!");
        throw runtime_error("TileManager::readMap() exception");
    }
    
    vector<int> mapData;
    
    mapData.resize(GAME_TILES);
    
    for ( int i = 0; i < GAME_TILES; ++i )
    {
        int tileType = -1;
        
        inputFile >> tileType;
        
        if ( inputFile.fail() )
        {
            Log::error("TileManager::readMap() -> Failed while reading the map!");
            throw runtime_error("TileManager::readMap() exception");
        }
        
        if (tileType < 0 || tileType >= TILE_SPRITES )
        {
            string errorMessage("TileManager::readMap() -> " + string("Wrong data faced while reading the map! Number should be [0,") + to_string(TILE_SPRITES) + "]");
            Log::error(errorMessage);
            throw runtime_error("TileManager::readMap() exception");
        }

        mapData[i] = tileType;
    }
    
    if (count(mapData.begin(), mapData.end(), 2) != 1 || count(mapData.begin(), mapData.end(), 3) != 1)
    {
        Log::error("TileManager::readMap() -> Wrong map format! Double in Exit or Enter!");
        throw runtime_error("TileManager::readMap() exception");
    }
    
    const vector<int> cornerIndexes = {0,1,2,3,4,5,6,7,8,15,16,23,24,31,32,39,40,47,48,55,56,57,58,59,60,61,62,63};
    
    vector<int>::iterator iterEnter = find(mapData.begin(), mapData.end(), 2);
    size_t indexEnter = std::distance(mapData.begin(), iterEnter);
    if (find(cornerIndexes.begin(), cornerIndexes.end(), indexEnter) == cornerIndexes.end())
    {
        Log::error("TileManager::readMap() -> Wrong map format! Wrong Enter place! "+ to_string(indexEnter));
        throw runtime_error("TileManager::readMap() exception");
    }
    
    vector<int>::iterator iterExit = find(mapData.begin(), mapData.end(), 3);
    size_t indexExit = std::distance(mapData.begin(), iterExit);
    if (find(cornerIndexes.begin(), cornerIndexes.end(), indexExit) == cornerIndexes.end())
    {
        Log::error("TileManager::readMap() -> Wrong map format! Wrong Exit place! " + to_string(indexExit));
        throw runtime_error("TileManager::readMap() exception");
    }
    
    if (std::abs((int)indexEnter - (int)indexExit) <= 1)
    {
        Log::error("TileManager::readMap() -> Wrong map format! Distance between Enter and Exit should be > 1!");
        throw runtime_error("TileManager::readMap() exception");
    }

    return mapData;
}

void TileManager::fill()
{
    /* Download the map */
    vector<int> mapData = readMap("examples/Map/" + Config::get("map"));
    
    int x(0), y(0);
    
    /* Create menu tiles */
    for (int i = 0; i < MENU_TILES; ++i)
    {
        tiles[i] = make_shared<Tile>(x, y, Tile::Type::OUTER);
        
        x += Tile::WIDTH;
        
        if (x >= ROW_TILES * Tile::WIDTH)
        {
            x = 0;
            y += Tile::WIDTH;
        }
    }
    
    /* Create game tiles */
    for (int i = 0; i < GAME_TILES; ++i)
    {
        if ( (Tile::Type) mapData[i] == Tile::Type::TURRET )
        {
            tiles[MENU_TILES + i] = make_shared<TileTurret>(x, y, (Tile::Type) mapData[i]);
        }
        else
        {
            tiles[MENU_TILES + i] = make_shared<Tile>(x, y, (Tile::Type) mapData[i]);
        }
       
        
        x += Tile::WIDTH;
        
        if (x >= ROW_TILES * Tile::WIDTH)
        {
            x = 0;
            y += Tile::WIDTH;
        }
    }
    
    Log::debug("Tiles were successfully set");
}

void TileManager::render()
{
    for (int i = 0; i < TOTAL_TILES; ++i)
    {
        tiles[i]->render();
    }
}

void TileManager::update()
{
    for (int i = 0; i < TOTAL_TILES; ++i)
    {
        tiles[i]->update();
    }
}

vector<shared_ptr<Tile> > TileManager::queryTilesOfTypes(const vector<Tile::Type>& types)
{
    vector<shared_ptr<Tile> > result;
    
    for (int i = MENU_TILES; i < TOTAL_TILES; ++i)
    {
        if (find(types.begin(), types.end(), tiles[i]->getType()) != types.end())
        {
            result.push_back(tiles[i]);
        }
    }
    
    return result;
}

