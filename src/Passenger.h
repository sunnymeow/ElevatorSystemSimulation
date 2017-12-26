//
//  Passenger.h
//  code
//
//  Created by Sunny Lin on 5/6/16.
//
//

#ifndef Passenger_hpp
#define Passenger_hpp
#include <iostream>
using namespace std;

const int UNDEFINED_FLOOR = -1;

class Passenger
{
private:
    int ID;
    int psgCurrentFloor;
    int psgDestinationFloor;
public:
    Passenger() {}  // default constructor
    Passenger(int id);  // constructor
    virtual ~Passenger() {} // virtual destructor
    int getPsgCurrentFloor() const; // return Passenger's current floor
    int getPsgDestinationFloor() const; // return Passenger's destination floor
    int getPsgID() const;   // return Passenger's ID
    bool isResident();  // return true if passenger is resident
    bool isWaitingOnFloor();  // return true if passenger is waiting on floor
    bool isInElevator();    // return true if passenger is in elevator
    void waitForElevator(int newDestinationFloor);  // set Passenger's destination floor
    void boardElevator();   // set Passenger's current floor to undefined
    void arrive();  // set Passenger's current floor to destination, destination floor to undefind
    void toString(); // display passenger

    const Passenger operator= (const Passenger&);  // overloading = operator
    bool operator< (const Passenger&) const; // overloading < operator in order to sort the set
};

#endif /* Passenger_h */
