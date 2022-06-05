#ifndef Player_h
#define Player_h

#include "DamageableObject.hpp"

/// @brief Class, which represents player and it's game data.
class Player : public DamageableObject
{
private:
    int coins;
    
public:
    Player(int coins);
    
    void addCoins(int value);
    
    void substractCoins(int value);
    
    int getCoins() const;
    
    virtual void destroy() override;
    
};

#endif /* Player_h */
