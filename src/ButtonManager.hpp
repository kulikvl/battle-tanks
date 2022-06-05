#ifndef ButtonManager_hpp
#define ButtonManager_hpp

#include <vector>
#include <memory>

#include "TileTurret.hpp"
#include "TurretManager.hpp"
#include "Button.hpp"
#include "Tile.hpp"

using namespace std;

/// \brief Class for creating and checking button events 
class ButtonManager
{
private:
    /// All buttons that are under control of the manager.
    vector<Button*> buttons;
    
    /// Pointer to current selected button.
    Button* currentSelectedButton;
    
    /// Object for placing turrets.
    TurretManager* turretManager;
    
public:
    ButtonManager();
    
    /// Init button manager with tiles representing buttons.
    /// @note As there are no other buttons in this game, there is only one (this) constructor that takes vector of tiles for turrets, and then it converts it to data type 'Button' and stores in the vector 'buttons'.
    ButtonManager(const vector<shared_ptr<Tile>>& turretTiles, TurretManager* turretManager);
    
    /// Handle all buttons.
    void handleEvent(SDL_Event* e);
    
};

#endif /* ButtonManager_hpp */
