//
//  Vehicle.hpp
//  VehicleDerivation
//
//  Created by Oleksii Kyrylchuk on 11/8/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <iostream>
#include <vector>

class Vehicle {
public:
    Vehicle();
    ~Vehicle();
    Vehicle ( float len, float width, float height, float weight, float maxSpeed, float fuel, float health, float passengers );
    virtual bool move ( float x, float y, float velocity );
    bool stop();
    bool honk();
    float getPassengers();
    float setPassengers();
    float getDimension ( float numDimension );
protected:
    float setDimension ( float numDimension, float val );
    std::vector<float> measures; // len, width, height, weight, maxSpeed, fuel, health, etc
};

class Car : public virtual Vehicle {
public:
    Car();
    Car ( float len, float width, float height, float weight, float maxSpeed,
         float fuel, float health, float nitroFuel, float passengers );
    bool activateNitro();
protected:
    float nitroFuel;
};

class Boat : public virtual Vehicle {
public:
    Boat();
    Boat ( float len, float width, float height, float weight,
         float maxSpeed, float fuel, float health, float passengers, float waterline);
    float getWaterline();
    void setWaterline( float waterline );
protected:
    float waterline;
};

class AmphibiousCar : public Car, public Boat {
public:
    AmphibiousCar();
    AmphibiousCar ( float len, float width, float height, float weight, float maxSpeed,
                   float fuel, float health, float nitroFuel, int passengers, float waterline);
    int getMode();
    bool setMode();
    bool switchMode();
protected:
    int mode;
};

#endif /* Vehicle_hpp */
