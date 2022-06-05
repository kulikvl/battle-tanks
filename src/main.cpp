#include "SDL.hpp"
#include "Log.hpp"
#include "Config.hpp"
#include "Game.hpp"

/*! \mainpage SDL2 Tower Defense game
 *
 * \section howtoplay_sec How to play
 *
 * 1. Click on the special tiles where you can put the turrets.
 * 2. Press 1,2,3 to choose a turret.
 *
 * \section implementationdetails_sec Implementation details
 *
 * The most important class is Game, it contains the main game cycle and initialization of key objects that control and manage the gameplay.
 *
 * There are several static classes in the project, for example, SDL, Log, Config but their functionality is global and the only one within the entire project, so this is justified.
 *
 * There are a lot of 'manager' classes, that create, update, renderer and overally control specific game objects, that they are responsible of. Such classes are: TileManager, TankManager, TurretManager.
 *
 * An important mention is the Config class, which represents the management of settings and customization of the game from an external file, and there I will present some save-files to demonstrate the functionality of the game.
 *
 * I attached great importance to polymorphism, because in games it is always very important to identify common features for game objects, they are classes MoveableObject, DamageableObject, GameObject and so on.
 *
 * The project also provides stand-alone classes - such classes can be used in and compatible with any project, so they are very flexible. Examples of such classes: Timer, TimerCounter, Color, Utils, Log and so on.
 *
 * \section warning_sec Memory leak warning
 *
 * If you run the executable file through the 'valgrind' utility, it will almost always throw a memory leak. This is normal, and inevitable. This is typical for every library using Opengl.
 *
 */

int main(int argc, char* args[])
{
    try
    {
        Config::load("examples/config.ini");
        
        Log::debugMode(Config::getBool("debug", true));
        
        SDL::init();
        
        Game game;
        
        game.run();
        
        SDL::exit();
    }
    catch (...)
    {
        Log::error("Exception caught! Quitting...");
        return -1;
    }
    
    return 0;
}
