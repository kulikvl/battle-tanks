#include "Player.hpp"
#include "Config.hpp"
#include "Log.hpp"

Player::Player(int coins) :
    DamageableObject(3),
    coins(coins)
{
}

void Player::addCoins(int value)
{
    if (value < 0)
    {
        Log::error("Player::addCoins() -> Fail to add negative number!");
        return;
    }
    
    coins += value;
}

void Player::substractCoins(int value)
{
    if (value < 0)
    {
        Log::error("Player::addCoins() -> Fail to substract negative number!");
        return;
    }
    
    coins -= value;
}

int Player::getCoins() const
{
    return coins;
}

void Player::destroy()
{
    Log::debug("Player is destroyed! Tanks won!");
}
