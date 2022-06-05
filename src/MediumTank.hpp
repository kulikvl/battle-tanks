#ifndef MediumTank_hpp
#define MediumTank_hpp

#include "Tank.hpp"

/// \brief Another kind of tank.
class MediumTank : public Tank
{
private:
    virtual void selectPath() override;
public:
    MediumTank(const MazeSolver& mazeSolver, Player& player);
};

#endif /* MediumTank_hpp */
