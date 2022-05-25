#include "TabManager.hpp"

#include <vector>
#include <functional>
#include <array>
using namespace std;

TabManager::TabManager()
{
    for (size_t i = 0; i < coins.size(); ++i)
    {
        coins[i] = std::make_unique<Coin>(i*20,0);
    }
    
    const int offsetHeartTab = 400;
    
    for (size_t i = 0; i < hearts.size(); ++i)
    {
        hearts[i] = std::make_unique<Heart>(offsetHeartTab + i*80, 0);
    }
}

void TabManager::update()
{
    for (size_t i = 0; i < coins.size(); ++i)
    {
        if (i < Player::coins)
            coins[i]->show = true;
        else
            coins[i]->show = false;
    }
    
    for (size_t i = 0; i < hearts.size(); ++i)
    {
        if (i < Player::hp)
            hearts[i]->isRed = true;
        else
            hearts[i]->isRed = false;
    }
}

void TabManager::render()
{
    for (size_t i = 0; i < coins.size(); ++i)
    {
        coins[i]->render();
    }
    
    for (size_t i = 0; i < hearts.size(); ++i)
    {
        hearts[i]->render();
    }
}
