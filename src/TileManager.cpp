#include "TileManager.hpp"
#include "TileTurret.hpp"

TileManager::TileManager() 
{
    fill();
}

vector<int> TileManager::readMap(const string& inFileName)
{
    /* Open the map */
    ifstream inputFile(inFileName);
    
    /* If the map could not be loaded */
    if ( inputFile.fail() )
    {
        throw runtime_error("Failed to open the map!");
    }
    
    vector<int> mapData;
    mapData.resize(GAME_TILES);
    
    for ( int i = 0; i < GAME_TILES; ++i )
    {
        int tileType = -1;
        
        inputFile >> tileType;
        
        /* If there was a problem in reading map */
        if ( inputFile.fail() )
        {
            throw runtime_error("Failed while reading the map!");
        }
        
        /* Input check */
        if (tileType < 0 || tileType >= TILE_SPRITES )
        {
            throw runtime_error("Wrong data faced while reading the map! Number should be [0," + to_string(TILE_SPRITES) + "]");
        }

        mapData[i] = tileType;
    }

    return mapData;
}

void TileManager::fill()
{
    /* Download the map */
    vector<int> mapData = readMap("Default.map");
    
    /* The tile offsets */
    int x(0), y(0);
    
    /* Create menu tiles */
    for (int i = 0; i < MENU_TILES; ++i)
    {
        tiles[i] = make_shared<Tile>(x, y, TileType::OUTER);
        
        x += Window::TILE_WIDTH;
        
        if (x >= ROW_TILES * Window::TILE_WIDTH)
        {
            x = 0;
            y += Window::TILE_WIDTH;
        }
    }
    
    /* Create game tiles */
    for (int i = 0; i < GAME_TILES; ++i)
    {
        if ( (TileType)mapData[i] == TileType::TURRET )
        {
            tiles[MENU_TILES + i] = make_shared<TileTurret>(x, y, (TileType) mapData[i]);
        }
        else
        {
            tiles[MENU_TILES + i] = make_shared<Tile>(x, y, (TileType) mapData[i]);
        }
       
        
        x += Window::TILE_WIDTH;
        
        if (x >= ROW_TILES * Window::TILE_WIDTH)
        {
            x = 0;
            y += Window::TILE_WIDTH;
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

vector<shared_ptr<Tile>> TileManager::queryTilesOfTypes(const vector<TileType>& types)
{
    vector<shared_ptr<Tile>> result;
    
    for (int i = MENU_TILES; i < TOTAL_TILES; ++i)
    {
        if (find(types.begin(), types.end(), tiles[i]->getType()) != types.end())
        {
            result.push_back(tiles[i]);
        }
    }
    
    return result;
}
