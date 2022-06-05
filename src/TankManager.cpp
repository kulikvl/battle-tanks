#include "TankManager.hpp"
#include "Utils.hpp"
#include "Log.hpp"
#include "Config.hpp"

TankManager::TankManager(const MazeSolver& mazeSolver, Player& player, float delayLimit, float decreasingRate, float initialDelay, float initialDelayOffset) :
    mazeSolver(mazeSolver),
    timer(3000),
    tanksGenerated(0),
    player(player),
    delayLimit(delayLimit),
    decreasingRate(decreasingRate),
    initialDelay(initialDelay),
    initialDelayOffset(initialDelayOffset),
    difficulty( Config::getInt("difficulty", 1))
{
    
    timer.startCounting();
}

void TankManager::generate()
{
    TankTypes randomTankType = (TankTypes) Utils::Random::between(TankTypes::LIGHT, TankTypes::HEAVY);
    
    switch (randomTankType)
    {
        case TankTypes::LIGHT:
            tanks.push_back(make_shared<LightTank>(mazeSolver, player));
            break;
        case TankTypes::MEDIUM:
            tanks.push_back(make_shared<MediumTank>(mazeSolver, player));
            break;
        case TankTypes::HEAVY:
            tanks.push_back(make_shared<HeavyTank>(mazeSolver, player));
            break;
        default:
            Log::error("Wrong tank type generated!");
            break;
    }
}

void TankManager::update()
{
    if (timer.isDone())
    {
        generate();
        
        tanksGenerated++;
        
        float delay = Utils::Random::fbetween(initialDelay, initialDelay + initialDelayOffset) / sqrt( (float)difficulty );
        
        delay -= tanksGenerated * decreasingRate;
        
        if (delay < delayLimit) delay = delayLimit;
        
        timer.setDelay(delay);

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
