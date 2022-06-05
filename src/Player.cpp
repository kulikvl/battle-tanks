#include "Player.hpp"
#include "Config.hpp"
#include "Log.hpp"
#include <exception>
#include <stdexcept>

using namespace std;

Player::Player(int initialHp, int initialCoins) :
    DamageableObject(initialHp),
    coins(initialCoins)
{
    if (initialHp <= 0 || initialCoins <= 0)
    {
        Log::error("Player::Player() -> Fail to init player, wrong values!");
        throw runtime_error("Player::Player() exception");
    }
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
    Log::log("Player is destroyed! Tanks won!");
}
