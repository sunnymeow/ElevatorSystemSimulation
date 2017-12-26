//
//  Elevator.h
//  code
//
//  Created by Sunny Lin on 4/18/16.
//
//

#ifndef Elevator_h
#define Elevator_h
#include <set>
#include "Passenger.h"

const int NUMBER_OF_FLOOR = 7;
const int CAPACITY = 10;

class Passenger;    // forward declaration

class Elevator
{
private:
    set<Passenger> pplOnBoard; // # of ppl in the elevator
    int currentFloor;   // current floor where the elevator at
    bool up;    // return true when elevator goes UP    
public:
    Elevator();// no-argument constructor
    virtual ~Elevator() {}  // virtual destructor
    int PplDestinated[NUMBER_OF_FLOOR] = {0,0,0,0,0,0,0}; // # of destinated people to the counterpair floor
    int getCurrentFloor() const;// return the elevator's current floor
    int getPplOnBoard() const;// return the number of passengers currently on the elevator
    bool goingUp() const; // return TRUE if elevator is going UP
    bool goingDown() const; // return TRUE if elevator is going down
    void move(); // move the elevator one floor at a time
    void boardPassenger(Passenger);// board ONE passengers into elevator
    void disembarkPassenger(int);// disembark ONE passenger when arrive to their destination
    void toString();// display floor # with # of on-board passenger
    
    class ElevatorFullException // exception class
    {
    private:
        string errorMsg;    // Error Msg for full capacity
        Passenger extraPsg; // # of passengers excess the full capacity
    public:
        ElevatorFullException() {}
        void setErrorMsg (string msg) // set Error Msg
        {   errorMsg = msg;     }
        string getErrorMsg () const // get Error Msg
        {   return errorMsg;    }
        void setExtraPsg (Passenger extra)  // set # of excess passengers
        {   extraPsg = extra;     }
        Passenger getExtraPsg () const    // get # of excess passengers
        {   return extraPsg;    }
        ~ElevatorFullException() {}
    };
};
#endif /* Elevator_h */
