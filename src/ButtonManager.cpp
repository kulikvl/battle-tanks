#include "ButtonManager.hpp"
#include "TileTurret.hpp"
#include "Button.hpp"
#include <vector>
#include <algorithm>

using namespace std;

ButtonManager::ButtonManager(const vector<shared_ptr<Tile>>& turretTiles, TurretManager* turretManager) : currentSelectedButton(nullptr), turretManager(turretManager)
{
    for (size_t i = 0; i < turretTiles.size(); ++i)
    {
        Tile* tile = turretTiles[i].get();
        TileTurret* tileTurret = dynamic_cast<TileTurret*>(tile);
        Button* b = tileTurret;
        buttons.push_back(b);
    }
}

void ButtonManager::handleEvent(SDL_Event* e)
{
    if (e->type == SDL_MOUSEBUTTONDOWN)
    {
        for (size_t i = 0; i < buttons.size(); ++i)
        {
            bool isSelectedBefore = buttons[i]->isSelected;
            
            buttons[i]->handleEvent(e);
            
            if (buttons[i]->isSelected == true && isSelectedBefore == false)
            {
                if (currentSelectedButton != nullptr)
                {
                    currentSelectedButton->isSelected = false;
                }
                
                currentSelectedButton = buttons[i];
            }
        }
    }
    else if (currentSelectedButton != nullptr)
    {
        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

        if( currentKeyStates[ SDL_SCANCODE_1 ] )
        {
            turretManager->installTurret(TurretManager::TurretType::FIREBIRD, (TileTurret*)currentSelectedButton );
        }
        else if( currentKeyStates[ SDL_SCANCODE_2 ] )
        {
            turretManager->installTurret(TurretManager::TurretType::FREEZE, (TileTurret*)currentSelectedButton );
        }
        else if( currentKeyStates[ SDL_SCANCODE_3 ] )
        {
            turretManager->installTurret(TurretManager::TurretType::SMOKY, (TileTurret*)currentSelectedButton );
        }
    }
    
    
    
}
