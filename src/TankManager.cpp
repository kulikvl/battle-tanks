#include "TankManager.hpp"
#include "Utils.hpp"
#include "Log.hpp"
#include "Config.hpp"

TankManager::TankManager(const MazeSolver& mazeSolver) :
    mazeSolver(mazeSolver),
    timer(3000),
    tanksGenerated(0)
{
    timer.startCounting();
}

void TankManager::generate()
{
    switch ( Utils::Random::between(0, 2) ) {
        case 0:
            tanks.push_back(make_shared<LightTank>(mazeSolver));
            break;
        case 1:
            tanks.push_back(make_shared<MediumTank>(mazeSolver));
            break;
        case 2:
            tanks.push_back(make_shared<HeavyTank>(mazeSolver));
            break;
    }
}

void TankManager::update()
{
    if (timer.isDone())
    {
        generate();
        
        tanksGenerated++;
        
        int difficulty = Config::getInt("difficulty", 1);
        
        float delay = Utils::Random::fbetween(4000.0f, 5500.0f) / sqrt( (float)difficulty);
        
        delay -= tanksGenerated * 5.0f;
        
        if (delay < 250.0f) delay = 250.0f;
        
        timer.setDelay( delay );

        timer.startCounting();
    }
    
    for (size_t i = 0; i < tanks.size(); ++i)
    {
        tanks[i]->update();

        if (!tanks[i]->isActive)
        {
            tanks.erase(tanks.begin() + i);
            i--;
        }
    }
}

void TankManager::render()
{
    for (size_t i = 0; i < tanks.size(); ++i)
    {
        tanks[i]->render();
    }
}

vector<shared_ptr<Tank> >& TankManager::getTanks()
{
    return tanks;
}
