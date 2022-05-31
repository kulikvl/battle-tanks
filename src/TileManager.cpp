#include "TileManager.hpp"
#include "TileTurret.hpp"
#include "Config.hpp"
#include <fstream>
#include <exception>

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

    return mapData;
}

void TileManager::fill()
{
    /* Download the map */
    vector<int> mapData = readMap("../examples/Map/Default.map"); //+ Config::get("map"));
    
    /* The tile offsets */
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
    
    Log::debug("Tiles were successfully set.\n");
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
