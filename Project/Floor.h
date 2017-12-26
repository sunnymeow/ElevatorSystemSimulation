//
//  Floor.h
//  code
//
//  Created by Sunny Lin on 5/1/16.
//
//

#ifndef Floor_h
#define Floor_h
#include <set>
#include <vector>
#include "Passenger.h"

class Passenger;   // forward declaration

class Floor
{
private:
    set<Passenger> PplOnFloor;  // # of ppl waiting on this floor
public:
    Floor() {} // default constructor
    virtual ~Floor() {} // virtual destructor
    int getPeopleOnFloor() const;// returns the number of people on the floor
    void setPeopleOnFloor (Passenger);// add ONE people to this floor
    void erasePassenger(Passenger); // erase ONE people when they board the elevator
    void waitForElevator(int,Passenger*);// called when ONE passenger is waiting for the elevator
    void displayCurrentFloor(int); // display all people on this floor
};

#endif /* Floor_h */
