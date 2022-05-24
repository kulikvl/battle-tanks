#include "TurretManager.hpp"
#include "TileTurret.hpp"
#include "Log.hpp"
#include "Config.hpp"

#include <functional>
#include <string>

using namespace std;

TurretManager::TurretManager(Window* window, vector<shared_ptr<Tank> >& tanks) : window(window), tanks(tanks)
{
    
}

void TurretManager::update()
{
    for (size_t i = 0; i < turrets.size(); ++i)
    {
        turrets[i]->findTargetTank(tanks);
        turrets[i]->update();
        turrets[i]->shoot();
    }
}

void TurretManager::render()
{
    for (size_t i = 0; i < turrets.size(); ++i)
    {
        turrets[i]->render();
    }
}

void TurretManager::installTurret(TurretType type, TileTurret* tile)
{
    if (!tile->hasTurret)
    {
        int cost;
        switch (type) {
            case TurretType::FIREBIRD:
                cost = Config::getInt("firebird_cost", 5);
                break;
            case TurretType::FREEZE:
                cost = Config::getInt("freeze_cost", 5);
                break;
            case TurretType::SMOKY:
                cost = Config::getInt("smoky_cost", 5);
                break;
            default:
                cost = 3;
                break;
        }
        
        if (Player::coins < cost)
        {
            Log::warning( string("Not enough coins! " + to_string(Player::coins) + " / " + to_string(cost)));
            return;
        }
        
        tile->hasTurret = true;
        tile->isSelected = false;
        
        switch (type) {
            case TurretType::FIREBIRD:
                turrets.push_back(make_shared<Firebird>(window, tile->getX(), tile->getY()));
                break;
            case TurretType::FREEZE:
                turrets.push_back(make_shared<Freeze>(window, tile->getX(), tile->getY()));
                break;
            case TurretType::SMOKY:
                turrets.push_back(make_shared<Smoky>(window, tile->getX(), tile->getY()));
                break;
        }
        
        Player::coins -= cost;
    }
}
