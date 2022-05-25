#ifndef TabManager_hpp
#define TabManager_hpp

#include "Window.hpp"
#include "GameObject.hpp"
#include "Player.hpp"

#include <vector>
#include <functional>
#include <array>
using namespace std;

#include "Heart.cpp"
#include "Coin.cpp"

class TabManager : public GameObject
{
private:
    array<unique_ptr<Coin>, 17> coins;
    array<unique_ptr<Heart>, 3> hearts;
    
public:
    TabManager();
    
    virtual void update() override;
    
    virtual void render() override;
};

#endif /* TabManager_hpp */
