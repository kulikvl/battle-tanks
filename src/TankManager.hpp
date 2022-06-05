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

enum TankTypes
{
    LIGHT = 0,
    MEDIUM = 1,
    HEAVY = 2
};

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
    
    /// Min delay of tank generation.
    const float delayLimit;
    
    /// Tells how fast the delay of tank generation will decrease.
    const float decreasingRate;
    
    /// Initial delay of tank generation in milliseconds.
    const float initialDelay;
    
    /// Random offset of initial delay of tank generation in milliseconds.
    const float initialDelayOffset;
    
    /// Difficulty can be set in config file.
    const int difficulty;
    
public:
    /// Init everything.
    TankManager(const MazeSolver& mazeSolver, Player& player, float delayLimit = 250.0f, float decreasingRate = 5.0f, float initialDelay = 3000.0f, float initialDelayOffset = 1500.0f);
    
    void generate();
    
    void update();
    
    void render();
    
    /// Get vector of current tanks in the scene.
    vector<shared_ptr<Tank> >& getTanks();
    
};

#endif /* TankManager_hpp */
