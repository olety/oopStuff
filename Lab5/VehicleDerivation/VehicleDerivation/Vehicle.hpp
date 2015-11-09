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
    Vehicle ( float len, float width, float height, float weight, float maxSpeed, float fuel, float health );
    bool move ( float x, float y, float velocity );
    bool stop();
    bool honk();
    float getDimension ( float numDimension );
protected:
    float setDimension ( float numDimension, float val );
    std::vector<float> measures; // len, width, height, weight, maxSpeed, fuel, health, etc
};

class Car : protected Vehicle {
public:
    Car();
    Car ( float len, float width, float height, float weight,
         float maxSpeed, float fuel, float health, float nitroFuel,
         int maxPassengers, int numPassengers );
    bool activateNitro();
    int getPassengers();
    int setPassengers();
protected:
    float nitroFuel;
    int numPassengers;
    int maxPassengers;
};

class Bus : protected Vehicle {
public:
    Bus();
    Bus ( float len, float width, float height, float weight,
         float maxSpeed, float fuel, float health, int numSeats,
         int numPassengersSeated, int numPassengersStanding, int maxPassengersSeated,
         int maxPassengersStanding, float ticketCost);
    int getPassengersSeated();
    int getPassengersStanding();
    int setPassengersSeated();
    int setPassengersStanding();
    float getTicketCost();
    bool setTicketCost();
protected:
    int numSeats;
    int numPassengersSeated;
    int numPassengersStanding;
    int maxPassengersSeated;
    int maxPassengersStanding;
    float ticketCost;
};

#endif /* Vehicle_hpp */
