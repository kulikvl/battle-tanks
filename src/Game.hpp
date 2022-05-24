#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
#include "TileManager.hpp"
#include "TankManager.hpp"
#include "MazeSolver.hpp"
#include "ButtonManager.hpp"
#include "TurretManager.hpp"
#include "TabManager.hpp"
#include "Player.hpp"
#include "Sprite.hpp"
#include "Config.hpp"

#include <vector>
#include <functional>

using namespace std;



/// \brief Class for managing general game logic.
/// Class, in which the main game loop is running.
/// It checks for input, updates, clears and renders the screen.
class Game
{
private:
    /// The window on which the game is displayed.
    Window* window;
    
    /// The tile manager to organise and create tiles.
    TileManager tileManager;
    
    /// The tank manager to organise and create tanks.
    TankManager tankManager;
    
    /// The turret manager to organise and install turrets.
    TurretManager turretManager;
    
    /// The button manager to  control buttons.
    ButtonManager buttonManager;
    
    /// Maze solver to find all paths in the maze.
    MazeSolver mazeSolver;
    
    TabManager tabManager;
    
    Sprite endScreenImage;
    

public:
    /// Initializes pretty much everything.
    Game(Window* window);

    /// Main entry point and game loop.
    ///
    /// This is where it all happens. The game never leaves this
    /// method.
    ///
    /// If we leave this method, the game quits, as seen on
    /// *main.cpp*.
    void run();
    
    enum State
    {
        PLAYING,
        ENDSCREEN
    };
    
    State state;
    
    static Window* mainWindow;
};

#endif /* Game_hpp */
