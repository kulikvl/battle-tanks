#include <cstdlib>              // srand()
#include <ctime>                // time()
#include <random>
#include "Game.hpp"
#include "SDL.hpp"
#include "Log.hpp"
#include "Window.hpp"
#include "TimerCounter.hpp"
#include "LightTank.hpp"
#include "Button.hpp"

#include "Utils.hpp"

Window* Game::mainWindow = nullptr;

Game::Game(Window* window) :
    window(window),
    tileManager(window),
    mazeSolver(tileManager.queryTilesOfTypes({TileType::ROAD, TileType::ENTRY, TileType::EXIT})),
    tankManager(window, mazeSolver),
    turretManager(window, tankManager.getTanks()),
    buttonManager(tileManager.queryTilesOfTypes({TileType::TURRET}), &turretManager),
    tabManager(window),
    state(State::PLAYING),
    endScreenImage(window, "EndScreen.png")
    
{
    Utils::Random::seed();
    Game::mainWindow = window;
}

void Game::run()
{
    bool quit = false;
    
    SDL_Event e;

    while (!quit)
    {
        if (Player::hp <= 0)
        {
            state = State::ENDSCREEN;
        }
        
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT) quit = true;
            
            if (state == State::PLAYING)
                buttonManager.handleEvent(&e);
                
        }
        
        if (state == State::PLAYING)
        {
            tileManager.update();
            tankManager.update();
            turretManager.update();
            tabManager.update();
        }
       
        window->clear();
        
        if (state == State::PLAYING)
        {
            tileManager.render();
            tankManager.render();
            turretManager.render();
            tabManager.render();
        }

        if (state == State::ENDSCREEN)
        {
            endScreenImage.render(0, 0);
        }

        window->refresh();
    }
}

