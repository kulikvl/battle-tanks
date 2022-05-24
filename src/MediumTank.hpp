#ifndef MediumTank_hpp
#define MediumTank_hpp

#include "Tank.hpp"

/// \brief Another kind of tank
///
/// Standart middle tank, can move in any way
class MediumTank : public Tank
{
private:
    virtual void selectPath() override;
public:
    MediumTank(Window* window, const MazeSolver& mazeSolver);
};

#endif /* MediumTank_hpp */
