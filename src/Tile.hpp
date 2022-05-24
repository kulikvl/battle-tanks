#ifndef Tile_hpp
#define Tile_hpp

#include "Window.hpp"
#include "GameObject.hpp"
#include "Sprite.hpp"

enum TileType
{
    WALL = 0,
    ROAD = 1,
    ENTRY = 2,
    EXIT = 3,
    TURRET = 4,
    TURRET_SELECT = 5,
    OUTER = 6,
};

/// \brief Simple class for representing tile
/// Tile has sprite, it's type, coords and inherited characteristics
/// 
class Tile : public GameObject
{
protected:
    /// The window on which the game is displayed.
    Window* window;
    
    /// Type of the tile.
    TileType type;
    
    /// Image.
    Sprite sprite;
    
    /// To make this class have direct access to tiles.
    friend class TileManager;
    
public:
    Tile(Window* window, int x, int y, TileType type);
    
    virtual void update() override;
    
    virtual void render() override;
    
    TileType getType();
    
};

#endif /* Tile_hpp */
