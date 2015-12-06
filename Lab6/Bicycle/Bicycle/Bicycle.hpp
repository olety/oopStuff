//
//  Bicycle.hpp
//  Bicycle
//
//  Created by Oleksii Kyrylchuk on 11/23/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef Bicycle_hpp
#define Bicycle_hpp

#include <iostream>

class Vehicle {
public:
    Vehicle ( int numPassengers, float maxSpeed = 50 );
    virtual void move ( float x, float y, float speed) = 0;
    int getNumPassengers ();
    void setNumPassengers ( int numPassengers );
    float getMaxSpeed ();
    void setMaxSpeed ( float maxSpeed );
protected:
    float maxSpeed;
    int numPassengers;
};

class RoadVehicle : protected virtual Vehicle {
public:
    RoadVehicle ( int numWheels = 4, float maxSpeed = 300);
    int getNumWheels ();
    void setNumWheels ( int numWheels );
protected:
    int numWheels;
};

class Bicycle : protected virtual RoadVehicle{
public:
    Bicycle ( float driverSkill = 0, int numPassengers = 1, int numWheels = 2, float maxSpeed = 40);
    virtual void bell() = 0;
protected:
    float driverSkill;
};

#endif /* Bicycle_hpp */
