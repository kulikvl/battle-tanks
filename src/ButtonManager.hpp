#ifndef ButtonManager_hpp
#define ButtonManager_hpp

#include "Button.hpp"
#include "Tile.hpp"
#include <vector>
#include <functional>
#include "TileTurret.hpp"
#include "TurretManager.hpp"

using namespace std;

/// \brief Class for creating and checking button events 
class ButtonManager
{
private:
    vector<Button*> buttons;
    Button* currentSelectedButton;
    TurretManager* turretManager;
    
public:
    ButtonManager(const vector<shared_ptr<Tile>>& turretTiles, TurretManager* turretManager);
    
    void handleEvent(SDL_Event* e);
};

#endif /* ButtonManager_hpp */
