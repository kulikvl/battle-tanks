#include "SDL.hpp"
#include "Log.hpp"
#include "Window.hpp"
#include "Game.hpp"
#include "Config.hpp"

#include <exception>

int main(int argc, char* args[])
{
    
    
    
    try
    {
        Config::load("config.ini");
        
        Log::debugMode(Config::getBool("debug", true));
        
        SDL::init();
        
        Window window(640, 720, "Tower defense");
        
        Game game(&window);
        
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
