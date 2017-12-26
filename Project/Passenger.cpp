//
//  Passenger.cpp
//  code
//
//  Created by Sunny Lin on 5/6/16.
//
//

#include "Passenger.h"

// constructor
Passenger::Passenger(int id)
{
    ID = id;
    psgCurrentFloor = 1;
    psgDestinationFloor = UNDEFINED_FLOOR;
}

// return Passenger's current floor
int Passenger::getPsgCurrentFloor() const
{
    return this->psgCurrentFloor;
}

// return Passenger's destination floor
int Passenger::getPsgDestinationFloor() const
{
    return this->psgDestinationFloor;
}

// return Passenger's ID
int Passenger::getPsgID() const
{
    return this->ID;
}

// return true if passenger is resident
bool Passenger::isResident()
{
    bool resident = false;
    if (psgCurrentFloor != UNDEFINED_FLOOR && psgDestinationFloor == UNDEFINED_FLOOR)
    {   resident = true;    }
    return resident;
}

// return true if passenger is waiting on floor
bool Passenger::isWaitingOnFloor()
{
    bool waitingOnFloor = false;
    if (psgCurrentFloor != UNDEFINED_FLOOR && psgDestinationFloor != UNDEFINED_FLOOR)
    {   waitingOnFloor = true;    }
    return waitingOnFloor;
}

// return true if passenger is in elevator
bool Passenger::isInElevator()
{
    bool inElevator = false;
    if (psgCurrentFloor == UNDEFINED_FLOOR && psgDestinationFloor != UNDEFINED_FLOOR)
    {   inElevator = true;    }
    return inElevator;
}

// set Passenger's destination floor
void Passenger::waitForElevator(int newDestinationFloor)
{
    this->psgDestinationFloor = newDestinationFloor;
}

// set Passenger's current floor to undefined
void Passenger::boardElevator()
{
    this->psgCurrentFloor = UNDEFINED_FLOOR;
}

// set Passenger's current floor to destination
// set Passenger's destination floor to undefined
void Passenger::arrive()
{
    this->psgCurrentFloor = psgDestinationFloor;
    this->psgDestinationFloor = UNDEFINED_FLOOR;
}

// display passenger
void Passenger::toString()
{
    if (isResident())
        {   cout << "This passenger is a resident on floor " << psgCurrentFloor << endl;   }
    else if (isInElevator())
        {   cout << "This passenger is on an Elevator\n";    }
    else if (isWaitingOnFloor())
        {   cout << "This passenger is waiting for an elevator on floor " << psgCurrentFloor << endl;    }
    else
        {   cout << "Passenger Error!\n";   }
}

// overloading = operator
const Passenger Passenger::operator= (const Passenger& right)
{
    this->ID = right.getPsgID();
    this->psgCurrentFloor = right.getPsgCurrentFloor();
    this->psgDestinationFloor = right.getPsgDestinationFloor();
    return *this;
}

// overloading < operator in order to sort the set
bool Passenger::operator< (const Passenger &right) const
{
    return this->getPsgID() < right.getPsgID();
}

