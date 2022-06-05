#ifndef TabManager_hpp
#define TabManager_hpp

#include "GameObject.hpp"
#include "Player.hpp"
#include "Heart.cpp"
#include "Coin.cpp"
#include "Tile.hpp"

#include <vector>
#include <memory>
#include <array>

using namespace std;

/// @brief Class for managing UI interface that represents statistics while playing.
class TabManager : public GameObject
{
private:
    /// Coins on the tab.
    /// @note Up to 17 coins can be displayed on the tab panel. (Game design limitation).
    array<unique_ptr<Coin>, 17> coins;
    
    /// Hearts on the tab.
    /// @note Up to 3 hearts can be displayed on the tab panel. (Game design limitation).
    array<unique_ptr<Heart>, 3> hearts;
    
    /// Player object.
    const Player& player;
    
public:
    /// Init.
    TabManager(const Player& player);
    
    virtual void update() override;
    
    virtual void render() override;
};

#endif /* TabManager_hpp */
