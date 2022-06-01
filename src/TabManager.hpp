#ifndef TabManager_hpp
#define TabManager_hpp

#include "GameObject.hpp"
#include "Player.hpp"
#include "Heart.cpp"
#include "Coin.cpp"
#include "Tile.hpp"

#include <vector>
#include <functional>
#include <array>

using namespace std;

/// @brief Class for managing UI interface that represents statistics while playing.
class TabManager : public GameObject
{
private:
    /// Coins on the tab.
    array<unique_ptr<Coin>, 17> coins;
    
    /// Hearts on the tab.
    array<unique_ptr<Heart>, 3> hearts;
    
public:
    /// Init.
    TabManager();
    
    virtual void update() override;
    
    virtual void render() override;
};

#endif /* TabManager_hpp */
