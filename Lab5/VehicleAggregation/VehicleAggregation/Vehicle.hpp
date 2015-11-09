//
//  Vehicle.hpp
//  VehicleAggregation
//
//  Created by Oleksii Kyrylchuk on 11/9/15.
//  Copyright © 2015 olety. All rights reserved.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <iostream>

class Vehicle {
public:
    Vehicle();
    Vehicle ( float len, float width, float height, float weight, float maxSpeed, float fuel, float health );
    bool move ( float x, float y, float velocity );
    bool stop();
    bool honk();
    float getDimension ( float numDimension ); // len, width, height, weight, maxSpeed, fuel, health
protected:
    float setDimension ( float numDimension, float val );
    float measures[7]; // len, width, height, weight, maxSpeed, fuel, health
};


class Car {
public:
    Car();
    Car ( float len, float width, float height, float weight,
         float maxSpeed, float fuel, float health, float nitroFuel,
         int maxPassengers, int numPassengers );
    ~Car();
    int getPassengers();
    int setPassengers();
protected:
    Vehicle *vehicle;
    float nitroFuel;
    int numPassengers;
    int maxPassengers;
};

class Bus {
public:
    Bus();
    Bus ( float len, float width, float height, float weight,
         float maxSpeed, float fuel, float health, int numSeats,
         int numPassengersSeated, int numPassengersStanding, int maxPassengersSeated,
         int maxPassengersStanding, int ticketCost);
    ~Bus();
    int getPassengersSeated();
    int getPassengersStanding();
    int setPassengersSeated();
    int setPassengersStanding();
    int getTicketCost();
    int setTicketCost();
protected:
    Vehicle *vehicle;
    int numSeats;
    int numPassengersSeated;
    int numPassengersStanding;
    int maxPassengersSeated;
    int maxPassengersStanding;
    int ticketCost;
};

#endif /* Vehicle_hpp */
