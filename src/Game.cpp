#include <cstdlib>              // srand()
#include <ctime>                // time()
#include <random>
#include "Game.hpp"

#include "Utils.hpp"

Game::Game() :
    tileManager(),
    mazeSolver(tileManager.queryTilesOfTypes({TileType::ROAD, TileType::ENTRY, TileType::EXIT})),
    tankManager(mazeSolver),
    turretManager(tankManager.getTanks()),
    buttonManager(tileManager.queryTilesOfTypes({TileType::TURRET}), &turretManager),
    tabManager(),
    state(State::PLAYING),
    endScreenImage("EndScreen.png")
    
{
    Utils::Random::seed();
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
       
        SDL::window.clear();
        
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

        SDL::window.refresh();
    }
}

