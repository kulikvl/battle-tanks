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
    
protected:
    bool isMoving;
    float  velocity;
    float  initialVelocity;
    Direction direction;
    
public:
    /// Init the movealbe object.
    MoveableObject(float initialVelocity);

    /// Slow down the object (Decrease the velocity).
    void slow(float v);

    /// Accelerate the object (Increase the velocity).
    void accelerate(float v);

    /// Tells if the object is idle.
    bool isIdle();

    /// Returns current velocity of the object.
    float getCurrentVelocity();
    
    /// Returns initial velocity of the object (Velocity, which the object had after initialization).
    float getInitialVelocity();
    
    /// Sets initial velocity (Velocity, which the object had after initialization).
    void setInitialVelocity();

};

#endif /* MoveableObject_hpp */
