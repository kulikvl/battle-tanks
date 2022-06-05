#ifndef Tile_hpp
#define Tile_hpp

#include "GameObject.hpp"
#include "Sprite.hpp"

/// \brief Simple class for representing tile.
///
/// Tile has sprite, it's type, coords and inherited characteristics from GameObject
/// 
class Tile : public GameObject
{
public:
    /// Width of the tile in the game.
    /// @note *Every tile (Game design limitation).
    static const int WIDTH = 80;
    
    /// Types of the tile.
    enum Type
    {
        WALL = 0,
        ROAD = 1,
        ENTRY = 2,
        EXIT = 3,
        TURRET = 4,
        TURRET_SELECT = 5,
        OUTER = 6,
    };
    
protected:
    /// Type of the tile.
    Type type;
    
    /// Image.
    Sprite sprite;
    
    /// To make this class have direct access to tiles.
    friend class TileManager;
    
public:
    Tile(int x, int y, Type type);
    
    virtual void update() override;
    
    virtual void render() override;
    
    Tile::Type getType();
};

#endif /* Tile_hpp */
