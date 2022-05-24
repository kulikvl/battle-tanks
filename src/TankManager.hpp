#ifndef TankManager_hpp
#define TankManager_hpp

#include "Window.hpp"
#include "MazeSolver.hpp"

#include "Tank.hpp"
#include "LightTank.hpp"
#include "MediumTank.hpp"
#include "HeavyTank.hpp"

#include "Tile.hpp"

#include <functional>
#include <vector>
#include <string>

#include "TimerCounter.hpp"

using namespace std;

/// \brief Class for creating tanks and controlling them.
/// e.x. if tank is already at the end of the road, destroy it.
class TankManager
{
public:
    enum TankType
    {
        LIGHT = 0,
        MEDIUM = 1,
        HEAVY = 2,
    };
    
private:
    Window* window;
    const MazeSolver& mazeSolver;
    vector<shared_ptr<Tank> > tanks;
    TimerCounter timer;
    

public:
    TankManager(Window* window, const MazeSolver& mazeSolver);
    
    void generate();
    
    void update();
    
    void render();
    
    vector<shared_ptr<Tank> >& getTanks();
};

#endif /* TankManager_hpp */
