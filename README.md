# ElevatorSystemSimulation
Simulated a elevator with capacity of 10 passengers to take passengers up and down in a 7-floor building

*	Building: Contains 7 Floors and one Elevator. 
*	Elevator: Carries Passengers between Floors. Has a limited capacity of 10 passengers.
*	Floor: Passengers spend some time on a Floor, and then use the Elevator to go to another Floor.
*	Passenger: A person who enters and leaves the Building. While inside the Building, a Passenger is either on a Floor, or in the Elevator, moving between Floors.

The system design follows this UML diagram:

![UML](https://github.com/sunnymeow/ElevatorSystemSimulation/blob/master/res/UML%20diagram.png)

# Mechanics
* The elevator can be moving up or moving down. Once the elevator is moving up, it won't move down until it reaches the top floor, and vice versa. 
* A passenger arrives at the start floor at the start fime, waits for the elevator to arrive and stays on the elevator until arriving at the end floor.
* When a elevator arrives at a floor, it picks up all of the passengers waiting at the floor, up to the maximum capacity of 10, and then starts moving to the End Floors.
* The elevator will limit the number of passengers it can carry, throwing an ElevatorFullException if an attempt is made to board passengers past this limit.
* When stopped at a floor, if there are any passengers in the elevator with that end Floor as a destination, it discharges the passengers. Then, if there are any passengers with that floor as their start Floor it picks up passengers up to the capacity of the elevator.

# Simulation run

![run1](https://github.com/sunnymeow/ElevatorSystemSimulation/blob/master/res/run1.png)

![run2](https://github.com/sunnymeow/ElevatorSystemSimulation/blob/master/res/run2.png)

![run3](https://github.com/sunnymeow/ElevatorSystemSimulation/blob/master/res/run3.png)
