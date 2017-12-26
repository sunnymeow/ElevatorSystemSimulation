//
//  Elevator.cpp
//  code
//
//  Created by Sunny Lin on 4/18/16.
//


#include "Elevator.h"

// no-argument constructor
Elevator::Elevator()
{
    currentFloor = 1;
    up = true;
}

// return the elevator's current floor
int Elevator::getCurrentFloor() const
{
    return this->currentFloor;
}

// return the number of passengers currently on the elevator
int Elevator::getPplOnBoard() const
{
    return (int)pplOnBoard.size();
}

// return TRUE if elevator is going UP, false otherwiase
bool Elevator::goingUp() const
{
    return up;
}

// return TRUE if elevator is going down, false otherwise
bool Elevator::goingDown() const
{
    return !up;
}

// move the elevator one floor at a time, include direction
// disembark passengers if they arrive
void Elevator::move()
{
    if (up)
    {
        while (PplDestinated[currentFloor-1] != 0)
        {   disembarkPassenger(currentFloor);   }
        toString();
        currentFloor++;
        if (currentFloor == NUMBER_OF_FLOOR+1)
        {
            up = false;
            currentFloor -= 1;
        }
    }
    else if (!up)
    {
        while (PplDestinated[currentFloor-1] != 0)
        {   disembarkPassenger(currentFloor);   }
        toString();
        currentFloor--;
        if (currentFloor == 0)
        {
            up = true;
            currentFloor += 1;
        }
    }
}

// board ONE passenger into elevator
// assign the passenger to the destinated floor array
void Elevator::boardPassenger(Passenger newPassenger)
{
    if ((getPplOnBoard() + 1) <= CAPACITY)
    {
        int destinationFloor = newPassenger.getPsgDestinationFloor();
        Passenger temp = newPassenger;
        temp.boardElevator();
        pplOnBoard.insert(temp);
        PplDestinated[destinationFloor - 1] += 1;
    }
    else
    {
        Passenger extra = newPassenger;
        string error = "\tThe capacity of elevator (10) has been reached\n";
        ElevatorFullException exception;
        exception.setErrorMsg(error);
        exception.setExtraPsg(extra);
                
        throw exception;
    }
}

// disembark ONE passenger when arrive to their destination
void Elevator::disembarkPassenger(int currentFloorNumber)
{
    for (set<Passenger>::iterator ite = pplOnBoard.begin(); ite != pplOnBoard.end(); ++ite)
    {
        Passenger disembarkedPassenger = *ite;
        if (disembarkedPassenger.getPsgDestinationFloor() == currentFloorNumber)
        {
            pplOnBoard.erase(ite);
            PplDestinated[currentFloorNumber-1] -= 1;
            break;
        }
    }
}

// display floor # with # of on-board passenger
// if there are passengers on board, display their passenger ID
void Elevator::toString()
{
    cout << "Floor " << getCurrentFloor() << ": " << getPplOnBoard() << " passengers in the elevator\n";
    if (!pplOnBoard.empty())
    {
        cout << "\tPassenger: ";
        for (set<Passenger>::iterator ite = pplOnBoard.begin(); ite != pplOnBoard.end(); ++ite)
        {
            Passenger temp = *ite;
            cout << temp.getPsgID() << " ";
        }
        cout << endl;
    }
}
