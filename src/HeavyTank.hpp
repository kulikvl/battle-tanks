#ifndef HeavyTank_hpp
#define HeavyTank_hpp

#include "Tank.hpp"

/// \brief Another kind of tank
///
/// Has low speed, high HP, and moves always the shortest path
class HeavyTank : public Tank
{
private:
    virtual void selectPath() override;
public:
    HeavyTank(const MazeSolver& mazeSolver);
};

#endif /* HeavyTank_hpp */
