#ifndef TankManager_hpp
#define TankManager_hpp

#include "MazeSolver.hpp"

#include "Tank.hpp"
#include "LightTank.hpp"
#include "MediumTank.hpp"
#include "HeavyTank.hpp"

#include "Player.hpp"

#include "Tile.hpp"

#include <memory>
#include <vector>
#include <string>

#include "TimerCounter.hpp"

using namespace std;

/// \brief Class for creating tanks and controlling them.
///
/// @note if tank is already at the end of the road, destroy it.
///
class TankManager
{
private:
    /// Object for path selection.
    const MazeSolver& mazeSolver;
    
    /// Vector of current tanks in the scene.
    vector<shared_ptr<Tank> > tanks;
    
    /// Timer for tank spawner.
    TimerCounter timer;
    
    /// Count of generated tanks.
    size_t tanksGenerated;
    
    /// Player object.
    Player& player;
    
public:
    /// Init everything.
    TankManager(const MazeSolver& mazeSolver, Player& player);
    
    void generate();
    
    void update();
    
    void render();
    
    /// Get vector of current tanks in the scene.
    vector<shared_ptr<Tank> >& getTanks();
    
};

#endif /* TankManager_hpp */
