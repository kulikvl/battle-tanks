#ifndef Game_hpp
#define Game_hpp

#include <vector>
#include <functional>

#include "TileManager.hpp"
#include "TankManager.hpp"
#include "TurretManager.hpp"
#include "ButtonManager.hpp"
#include "TabManager.hpp"
#include "MazeSolver.hpp"
#include "Player.hpp"
#include "Sprite.hpp"
#include "Config.hpp"
#include "Utils.hpp"

using namespace std;

/// \brief Class for managing general game logic a main game loop.
/// Class, in which the main game loop is running.
/// It checks for input, updates, clears and renders the screen every frame.
class Game
{
public:
    /// Game state.
    enum State
    {
        PLAYING,
        ENDSCREEN
    };
    
private:
    /// Organise and create tiles.
    TileManager tileManager;
    
    /// Organise and create tanks.
    TankManager tankManager;
    
    /// Organise and install turrets.
    TurretManager turretManager;
    
    /// Control buttons.
    ButtonManager buttonManager;
    
    /// Find all paths in the maze (BFS).
    MazeSolver mazeSolver;
    
    /// Organise tab menu and buttons.
    TabManager tabManager;
    
    /// Current game state.
    State state;
    
    Sprite endScreenImage;
    
public:
    /// Initializes pretty much everything.
    Game();

    /// Main entry point and game loop.
    ///
    /// This is where it all happens. The game never leaves this
    /// method.
    ///
    /// If we leave this method, the game quits, as seen on
    /// *main.cpp*.
    void run();

};

#endif /* Game_hpp */
