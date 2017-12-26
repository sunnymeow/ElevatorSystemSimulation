//
//  Building.cpp
//  code
//
//  Created by Sunny Lin on 5/1/16.
//
//

#include "Building.h"

// constructor creates an Elevator, and one floor for each floor number
Building::Building()
{
    elevatorPtr = new Elevator();
    
    floorsPtr = new Floor*[NUMBER_OF_FLOOR];
    for (int index = 0; index < NUMBER_OF_FLOOR; index++) {
        floorsPtr[index] = new Floor();
    }
}

// return the building's Elevator
Elevator* Building::elevator()
{
    return elevatorPtr;
}

// return the floor object for the given floor number
Floor* Building::floor(int floorNumber)
{
    return floorsPtr[floorNumber-1];
}

// return the floor object from elevator's current floor
Floor* Building::currentFloor()
{
    return floor(elevator()->getCurrentFloor());
}

// add a passenger to the ground floor (floor 1)
void Building::enter(Passenger* newPassenger)
{
    PplInBuilding.push_back(newPassenger);
    Passenger newPassengerCopy = *newPassenger;
    floor(1)->setPeopleOnFloor(newPassengerCopy);   // insert passenger to Floor set
    cout << "\tPassenger " << newPassenger->getPsgID() << " enters the building" << endl;
}

// passenger is waiting for elevator on a floor
void Building::waitForElevator(int destinationFloor, Passenger* passengerWaiting)
{
    // if the desination floor is not the current floor, passenger update status to waiting
    // the passenger copy in Floor set is updated to waiting
    if (passengerWaiting->getPsgCurrentFloor() != destinationFloor)
    {
        floor(passengerWaiting->getPsgCurrentFloor())->waitForElevator(destinationFloor, passengerWaiting);
    }
}

// board ONE passenger to elevator with exception class
// if both passenger and elevator are going in same direction
// the passenger board the elevator
void Building::boardOnePassenger(Passenger* newPassenger)
{
    Passenger newPassengerCopy = *newPassenger;
    if ((newPassenger->getPsgDestinationFloor()) > elevator()->getCurrentFloor() && elevator()->goingUp())
    {
        try
        {
            elevator()->boardPassenger(newPassengerCopy);  // insert the copy of passenger in Elevator set
            newPassenger->boardElevator();  // use pointer to set passenger status to in elevator
            currentFloor()->erasePassenger(newPassengerCopy); // erase the copy of passenger in Floor set accroading to ID
        }
        catch (Elevator::ElevatorFullException exception)
        {
            // throw exception if reaches elevator capacity
            cout << exception.getErrorMsg();
            currentFloor()->setPeopleOnFloor(exception.getExtraPsg());
            cout << "\t\tpassenger " << exception.getExtraPsg().getPsgID() << " will stay on Floor "
            << elevator()->getCurrentFloor() << " waiting" << endl;
        }
    }
    else if ((newPassenger->getPsgDestinationFloor()) < elevator()->getCurrentFloor() && elevator()->goingDown())
    {
        try
        {
            elevator()->boardPassenger(newPassengerCopy);  // insert the copy of passenger in Elevator set
            newPassenger->boardElevator();  // use pointer to set passenger status to in elevator
            currentFloor()->erasePassenger(newPassengerCopy); // erase the copy of passenger in Floor set accroading to ID
        }
        catch (Elevator::ElevatorFullException exception)
        {
            // throw exception if reaches elevator capacity
            cout << exception.getErrorMsg();
            currentFloor()->setPeopleOnFloor(exception.getExtraPsg());
            cout << "\t\tpassenger " << exception.getExtraPsg().getPsgID() << " will stay on Floor "
                 << elevator()->getCurrentFloor() << " waiting" << endl;
        }
    }
}

// board as much as possible passengers to the elevator
void Building::boardPassengers()
{
    for (vector<Passenger*>::iterator ite = PplInBuilding.begin(); ite != PplInBuilding.end(); ++ ite)
    {
        Passenger* readyToBoard = *ite;
        // if passenger is on current floor waiting for elevator, then board passenger
        if (readyToBoard->getPsgCurrentFloor() == elevator()->getCurrentFloor() && readyToBoard->isWaitingOnFloor())
        {
            boardOnePassenger(readyToBoard);
        }
    }
}

// move the elevator one floor at a time and disembark passenger if possible
void Building::move()
{
    elevator()->move(); // remove the passenger copy from elevator set
    for (vector<Passenger*>::iterator ite = PplInBuilding.begin(); ite != PplInBuilding.end(); ++ite)
    {
        Passenger* passengerArrived = *ite;
        if (passengerArrived->isInElevator() && passengerArrived->getPsgDestinationFloor() == elevator()->getCurrentFloor())
        {
            passengerArrived->arrive(); // update passenger pointer when arrive
            Passenger passengerArrivedCopy = *passengerArrived;
            currentFloor()->setPeopleOnFloor(passengerArrivedCopy); // add the passenger copy into Floor set
        }
    }
}
