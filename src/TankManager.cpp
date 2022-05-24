#include "TankManager.hpp"
#include "Utils.hpp"
#include "Log.hpp"
#include "Config.hpp"

TankManager::TankManager(Window* window, const MazeSolver& mazeSolver) : window(window), mazeSolver(mazeSolver), timer(3000)
{
    timer.startCounting();
}

void TankManager::generate()
{
    TankType type = (TankType) Utils::Random::between((int)TankType::LIGHT, (int)TankType::HEAVY);
    
    switch (type) {
        case TankType::LIGHT:
            tanks.push_back(make_shared<LightTank>(window, mazeSolver));
            break;
        case TankType::MEDIUM:
            tanks.push_back(make_shared<MediumTank>(window, mazeSolver));
            break;
        case TankType::HEAVY:
            tanks.push_back(make_shared<HeavyTank>(window, mazeSolver));
            break;
    }
}

void TankManager::update()
{
    if (timer.isDone())
    {
        generate();
        
        int difficulty = Config::getInt("difficulty", 1);
        float delay = Utils::Random::fbetween(4000.0f, 5000.0f) / sqrt( (float)difficulty) ;
        timer.setDelay( delay );
        cout << "delay: " << delay << endl;
        
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
