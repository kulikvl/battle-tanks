#ifndef TileTurret_hpp
#define TileTurret_hpp

#include "Tile.hpp"
#include "Button.hpp"

/// \brief Special kind of tile class (inherits from Tile class and Button class), where we can put the turret.
/// Class that is tile and button at the same time.
class TileTurret : public Button, public Tile
{
public:
    TileTurret(int x, int y, TileType type);
    virtual void update() override;
    virtual void handleEvent( SDL_Event* e) override;
    bool hasTurret = false;
};

#endif /* TileTurret_hpp */
