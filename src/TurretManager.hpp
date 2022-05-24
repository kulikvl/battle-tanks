#ifndef TurretManager_hpp
#define TurretManager_hpp

#include "Turret.hpp"
#include "Tank.hpp"
#include "Window.hpp"
#include "Player.hpp"

#include "Firebird.hpp"
#include "Freeze.hpp"
#include "Smoky.hpp"

#include "TileTurret.hpp"

#include <vector>
#include <functional>

using namespace std;

/// \brief Class for controlling and creating turrets
class TurretManager
{
public:
    enum TurretType
    {
        FIREBIRD,
        FREEZE,
        SMOKY
    };
    
private:
    Window* window;
    vector<shared_ptr<Turret> > turrets;
    vector<shared_ptr<Tank> >& tanks;
    
public:
    TurretManager(Window* window, vector<shared_ptr<Tank> >& tanks);

    void update();
    
    void render();
    
    void installTurret(TurretType type, TileTurret* tile);
    
};

#endif /* TurretManager_hpp */
