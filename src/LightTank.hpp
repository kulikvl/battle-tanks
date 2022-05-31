#ifndef LightTank_hpp
#define LightTank_hpp

#include "Tank.hpp"

/// \brief Another kind of tank.
class LightTank : public Tank
{
private:
    virtual void selectPath() override;
public:
    LightTank(const MazeSolver& mazeSolver);
};

#endif /* LightTank_hpp */
