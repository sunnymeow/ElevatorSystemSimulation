//
//  Building.h
//  code
//
//  Created by Sunny Lin on 5/1/16.
//
//


#ifndef Building_h
#define Building_h
#include <vector>
#include "Elevator.h"
#include "Floor.h"

class Floor;    // forward declaration
class Elevator; // forward declaration
class Passenger;    // forward declaration

class Building
{
private:
    Elevator* elevatorPtr; // declare an Elevator pointer
    Floor* *floorsPtr;      // declare a Floor pointer
    vector<Passenger*> PplInBuilding;  // declare a vector to store all people in this building
public:
    Building(); // constructor creates an Elevator, and one floor for each floor number
    virtual ~Building() {}  // virtual destructor
    Elevator* elevator(); // return the building's Elevator
    Floor* floor(int floorNumber); // return the floor object for the given floor number
    Floor* currentFloor();  // return the floor object from elevator's current floor
    void enter(Passenger*); // add a passenger to the ground floor (floor 1)
    void waitForElevator(int,Passenger*); // stop the elevator on a floor where passengers waiting
    void boardOnePassenger(Passenger*);// board ONE passenger to elevator with exception class
    void boardPassengers(); // board as much as possible passengers to the elevator
    void move();    // move the elevator one floor at a time and board passenger if possible
};
#endif /* Building_h */
