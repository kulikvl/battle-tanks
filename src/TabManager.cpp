#include "TabManager.hpp"

TabManager::TabManager(const Player& player) : player(player)
{
    for (size_t i = 0; i < coins.size(); ++i)
    {
        coins[i] = std::make_unique<Coin>((int)i*20,0); // 20 pixels is distance between coins, can not be customized, because it is game design restriction.
    }
    
    for (size_t i = 0; i < hearts.size(); ++i)
    {
        hearts[i] = std::make_unique<Heart>(400 + (int)i * Tile::WIDTH, 0); // 400 pixels offset to the right, can not be customized, because it is game design restriction.
    }
}

void TabManager::update()
{
    for (size_t i = 0; i < coins.size(); ++i)
    {
        if ((int)i < player.getCoins())
            coins[i]->show = true;
        else
            coins[i]->show = false;
    }
    
    for (size_t i = 0; i < hearts.size(); ++i)
    {
        if ((int)i < player.getHitpoints())
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
