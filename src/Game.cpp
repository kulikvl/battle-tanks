#include "Game.hpp"

Game::Game() :
    tileManager(),
    mazeSolver(tileManager.queryTilesOfTypes({Tile::Type::ROAD, Tile::Type::ENTRY, Tile::Type::EXIT})),
    tankManager(mazeSolver),
    turretManager(tankManager.getTanks()),
    buttonManager(tileManager.queryTilesOfTypes({Tile::Type::TURRET}), &turretManager),
    tabManager(),
    state(State::PLAYING),
    endScreenImage("assets/EndScreen.png")
{
    Utils::Random::seed();
    Player::coins = Config::getInt("start_coins", 5);
}

void Game::run()
{
    bool quit = false;
    
    SDL_Event e;

    while (!quit)
    {
        if (Config::getBool("godmode", false) == true)
        {
            Player::hp    = 999;
            Player::coins = 999;
        }
        
        if (Player::hp <= 0)
        {
            state = State::ENDSCREEN;
        }
        
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT) quit = true;
            
            if (state == State::PLAYING)
            {
                buttonManager.handleEvent(&e);
            }
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

