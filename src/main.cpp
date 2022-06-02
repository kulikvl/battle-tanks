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
 * There are several static classes in the project, for example, SDL, Log, but their objects are the only ones within the entire project, so this is justified.
 *
 * It is also worth mentioning that such objects (variable members) as 'window', 'renderer' in classes like SDL, used in class e.x. Sprite, are global and static, because they are common to all classes of the entire game (Of course, in a diverse and bigger game project, this would be bad practice, as we would want more possibilities).
 *
 * An important mention is the Config class, which represents the management of settings and customization of the game from an external file, and there I will present the save-file to demonstrate the functionality of the game.
 *
 * I attached great importance to polymorphism, because in games it is always quite easy to identify common features for game objects, they are classes MoveableObject, DamageableObject, GameObject and so on.
 *
 * The project also provides standalone classes - such classes can be used with any project, so they are very flexible and easily portable. Examples of such classes: Timer, TimerCounter, Color, Utils, Log and so on.
 *
 * \section warning_sec Memory leak warning
 *
 * If you run the executable file through the 'valgrind' utility, it will almost always throw a memory leak (I have 64 bytes everytime). This is normal, and inevitable. This is typical for every library using Opengl.
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
