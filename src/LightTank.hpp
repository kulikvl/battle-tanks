#ifndef LightTank_hpp
#define LightTank_hpp

#include "Tank.hpp"

/// \brief Another kind of tank.
class LightTank : public Tank
{
private:
    virtual void selectPath() override;
public:
    LightTank(const MazeSolver& mazeSolver, Player& player);
};

#endif /* LightTank_hpp */
