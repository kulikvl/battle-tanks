#ifndef MoveableObject_hpp
#define MoveableObject_hpp


/// \brief An object that possesses speed and can "move" in the direction .
///
/// This class defines characteristics to be inherited by something
/// that may be able to move.
///
class MoveableObject
{
public:
    
    enum Direction
    {
        UP = 0,
        RIGHT = 1,
        DOWN = 2,
        LEFT = 3,
    };
    
    MoveableObject(float initialVelocity);

    void slow(float v);

    void accelerate(float v);

    bool isIdle();

    float getCurrentVelocity();
    
    float getInitialVelocity();
    
    void setInitialVelocity();

protected:
    bool isMoving;
    float  velocity;
    float  initialVelocity;
    Direction direction;
};

#endif /* MoveableObject_hpp */
