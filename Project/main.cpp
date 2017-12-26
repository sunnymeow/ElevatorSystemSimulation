//
//  ElevatorTest.cpp
//  code
//
//  Created by Sunny Lin on 4/18/16.
//
//


#include "Building.h"
#include <iostream>
using namespace std;

void displayFloorStatus(Building building); // display the building status of each floor
void moveElevator(Building building); // move up/down the elevator between floor 1 to 7

int main()
{
    Building building;
    int numberOfPassenger = 0, destinationFloor = 0;
    
    cout << "Please enter the number of passengers entering the building: ";
    cin >> numberOfPassenger;
    
    // ALL passengers enter the building floor 1
    Passenger* passenger[numberOfPassenger];
    for (int i = 0; i < numberOfPassenger; i++)
    {
        passenger[i] = new Passenger(i+1);
        building.enter(passenger[i]);
    }
    cout << "Initial status of the building: \n";
    
    do
    {
        displayFloorStatus(building);
        cout << endl;
        
        cout << "Enter the desitination floor (1-7) for these " << numberOfPassenger << " passengers ";
        cout << "\nOR enter 0 anytime to exit the program:\n";
        for (int i = 0; i < numberOfPassenger; i++)
        {
            do
            {
                cout << "Destination floor for passenger " << i+1 << ": ";
                cin >> destinationFloor;
            
                if (destinationFloor > 7 || destinationFloor < 0)
                    cout << "\tError! Floor number must between 1 to 7! Try again.\n";
                else if (destinationFloor == 0)
                    goto finish;
                else
                    // assign passenger to destination floor
                    building.waitForElevator(destinationFloor, passenger[i]);
            }  while (destinationFloor > 7 || destinationFloor < 1);
        }
        displayFloorStatus(building);
        moveElevator(building);
        cout << endl;
    }while (destinationFloor != 0);
    
    finish:
    cout << "\n************* Program finished *************\n";
    cout << "Final status of the building:" << endl;
    displayFloorStatus(building);
    
    // delete passenger to prevent memory leak
    for (int i = 0; i < numberOfPassenger; i++)
    {     delete passenger[i];    }
    
    return 0;
}

// display the building status of each floor
void displayFloorStatus(Building building)
{
    for (int floorNumber = 1 ; floorNumber <= 7; floorNumber ++)
    {   building.floor(floorNumber)->displayCurrentFloor(floorNumber);  }
}

// move up/down the elevator between floor 1 to 7
void moveElevator(Building building)
{
    if (building.elevator()->goingUp())
        cout << "\n*********  Elevator move UP  *********" << endl;
    else if (building.elevator()->goingDown())
        cout << "\n********* Elevator movec DOWN *********" << endl;
    
    for (int i = 0; i < 7; i++)
    {
        building.boardPassengers();
        building.move();
    }
}
