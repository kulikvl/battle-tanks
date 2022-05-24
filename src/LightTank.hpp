#ifndef LightTank_hpp
#define LightTank_hpp

#include "Tank.hpp"

/// \brief Another kind of tank
///
/// Has high speed, low HP, and moves always the longest path
class LightTank : public Tank
{
private:
    virtual void selectPath() override;
public:
    LightTank(Window* window, const MazeSolver& mazeSolver);
};

#endif /* LightTank_hpp */
