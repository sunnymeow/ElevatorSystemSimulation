//
//  Floor.cpp
//  code
//
//  Created by Sunny Lin on 5/1/16.
//
//

#include "Floor.h"

// returns the number of people on the floor
int Floor::getPeopleOnFloor() const
{
    return (int)PplOnFloor.size();
}

// add ONE people to this floor
void Floor::setPeopleOnFloor (Passenger newPassenger)
{
    PplOnFloor.insert(newPassenger);
}

// erase ONE people when they board the elevator
void Floor::erasePassenger(Passenger leavingPassenger)
{
    for (set<Passenger>::iterator ite = PplOnFloor.begin(); ite != PplOnFloor.end(); ++ite)
    {
        Passenger temp = *ite;
        if (temp.getPsgID() == leavingPassenger.getPsgID())
        {
            PplOnFloor.erase(ite);
            break;
        }
    }
}

// called when ONE passenger is waiting for the elevator
void Floor::waitForElevator(int destinationFloor, Passenger* newPassenger)
{
    newPassenger->waitForElevator(destinationFloor); // change the status of passenger* to waiting
    Passenger newPassengerCopy = *newPassenger;     // change the status of passenger copy in PplOnFloor to waiting
    for (set<Passenger>::iterator ite = PplOnFloor.begin(); ite != PplOnFloor.end(); ++ite)
    {
        Passenger temp = *ite;
        if (temp.getPsgID() == newPassengerCopy.getPsgID())
        {
            PplOnFloor.erase(ite);
            temp.waitForElevator(destinationFloor);
            PplOnFloor.insert(temp);
            break;
        }
    }
}

// display all people on this floor
void Floor::displayCurrentFloor(int floorNumber)
{
    cout << "\t" << getPeopleOnFloor() << " people are on Floor " << floorNumber << endl;
    vector<int> residency;
    vector<int> pplWaitingUp;
    vector<int> pplWaitingDown;
    for (set<Passenger>::iterator ite = PplOnFloor.begin(); ite != PplOnFloor.end(); ++ite)
    {
        Passenger temp = *ite;
        if (temp.isResident())
            residency.push_back(temp.getPsgID());
        else if (temp.getPsgDestinationFloor() > temp.getPsgCurrentFloor())
            pplWaitingUp.push_back(temp.getPsgID());
        else if (temp.getPsgDestinationFloor() < temp.getPsgCurrentFloor())
            pplWaitingDown.push_back(temp.getPsgID());
    }
    // display resident passenger ID
    if (!residency.empty())
    {
        cout << "\t\t" << residency.size() << " residents: ";
        for (int i = 0; i < residency.size(); i++)
        {   cout << residency[i] << " ";}
        cout << endl;
    }
    // display passenger ID of people waiting on this floor going UP
    if (!pplWaitingUp.empty())
    {
        cout << "\t\t" << pplWaitingUp.size() << " passengers waiting to go UP: ";
        for (int i = 0; i < pplWaitingUp.size(); i++)
        {   cout << pplWaitingUp[i] << " ";}
        cout << endl;
    }
    // display passenger ID of people waiting on this floor
    if (!pplWaitingDown.empty())
    {
        cout << "\t\t" << pplWaitingDown.size() << " passengers waiting to go DOWN: ";
        for (int i = 0; i < pplWaitingDown.size(); i++)
        {   cout << pplWaitingDown[i] << " ";}
        cout << endl;
    }
}
