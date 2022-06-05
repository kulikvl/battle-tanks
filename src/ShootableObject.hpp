#ifndef ShootableObject_hpp
#define ShootableObject_hpp

/// \brief An object that possesses damage amount, reload speed and can "shoot".
///
/// This class defines characteristics to be inherited by something
/// that may be able to shoot.
///
class ShootableObject
{
protected:
    int damage;
    float reload;
    float radius;
    bool isShooting;
    
public:
    ShootableObject(int damage, float reload, float radius);
    
    virtual void shoot() = 0;
    
};


#endif /* ShootableObject_hpp */
