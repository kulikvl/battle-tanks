#include "Game.hpp"

Game::Game() :
    player(Config::getInt("start_hp", 3), Config::getInt("start_coins", 3)),
    tileManager(),
    mazeSolver(tileManager.queryTilesOfTypes({Tile::Type::ROAD, Tile::Type::ENTRY, Tile::Type::EXIT})),
    tankManager(mazeSolver, player),
    turretManager(tankManager.getTanks(), player),
    buttonManager(tileManager.queryTilesOfTypes({Tile::Type::TURRET}), &turretManager),
    tabManager(player),
    state(State::PLAYING),
    endScreenImage("assets/EndScreen.png")
{
    if (Config::getBool("godmode", false) == true)
    {
        player.heal(999);
        player.addCoins(999);
    }
    
    Utils::Random::seed();
}

void Game::run()
{
    bool quit = false;
    
    SDL_Event e;

    while (!quit)
    {
        switch (state)
        {
            case State::ENDSCREEN:
                
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT) quit = true;
                }
                
                SDL::window.clear();
                
                endScreenImage.render(0, 0);
                
                SDL::window.refresh();
                
                break;
                
            case State::PLAYING:
                
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT) quit = true;
                    
                    buttonManager.handleEvent(&e);
                }
                
                tileManager.update();
                tankManager.update();
                turretManager.update();
                tabManager.update();
                
                if (player.isDead())
                {
                    state = State::ENDSCREEN;
                }
                
                SDL::window.clear();
                
                tileManager.render();
                tankManager.render();
                turretManager.render();
                tabManager.render();
                
                SDL::window.refresh();
                
                break;
        }
    }
}

