#include "SDL.hpp"
#include "Log.hpp"
#include "Config.hpp"
#include "Game.hpp"

int main(int argc, char* args[])
{
    try
    {
        Config::load("config.ini");
        
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
