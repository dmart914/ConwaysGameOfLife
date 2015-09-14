// Dave Martinez
// Assignment 1

// Cell.cpp
// created: 2015-1-9
// modified: 

#include "Cell.h"
#include "variables.cpp"

/* * * * * * * * * * * * * * * * * * * * * * *
Cell::Cell() - default constructor
Randomly chooses an x/y coord within range
and assigns it to the Cell. Also sets
cell_status to ALIVE
* * * * * * * * * * * * * * * * * * * * * * */
Cell::Cell() {
	position[0] = rand() % BOARD_LIMIT_X + 1;
	position[1] = rand() % BOARD_LIMIT_Y + 1;
	cell_status = ALIVE;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Cell::Cell(int x, int y) - overloaded constructor
Creates cell with x and y coordinates. Sets
cell_status to ALIVE
* * * * * * * * * * * * * * * * * * * * * * */
Cell::Cell(int x, int y) {
	position[0] = x;
	position[1] = y;
	cell_status = ALIVE;
}

/* * * * * * * * * * * * * * * * * * * * * * *
int* Cell::getPosition() - returns a pointer to
first element in array of Cell's position array
* * * * * * * * * * * * * * * * * * * * * * */
int* Cell::getPosition() {
	return position;
}

/* * * * * * * * * * * * * * * * * * * * * * *
void Cell::setPosition(int [2]) - sets the 
position of the Cell. Might not be super 
necessary since most Cells are fixed in place 
but you never know...
* * * * * * * * * * * * * * * * * * * * * * */
void Cell::setPosition(int x, int y) {
	position[0] = x;
	position[1] = y;

	return;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Status Cell::getStatus - returns the
cell_status, an enumerted type.
0 = DEAD
1 = ALIVE
* * * * * * * * * * * * * * * * * * * * * * */
Status Cell::getStatus() {
	return cell_status;
}

/* * * * * * * * * * * * * * * * * * * * * * *
void Cell::setStatus(Status st) - sets
cell_status, an enumerated type
0 = DEAD
1 = ALIVE
* * * * * * * * * * * * * * * * * * * * * * */
void Cell::setStatus(Status st) {
	cell_status = st;
}


/* * * * * * * * * * * * * * * * * * * * * * *
Cell::report() - a debugging tool used to cout
the various things about the cell.
* * * * * * * * * * * * * * * * * * * * * * */
void Cell::report() {
	std::cout << "CELL REPORT" << std::endl;

	std::cout << "STATUS: ";
	(cell_status == 0) ? std::cout << "DEAD" : std::cout << "ALIVE";
	std::cout << std::endl;

	std::cout << "X: " << position[0] << std::endl;
	std::cout << "Y: " << position[1] << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Cell::getX - returns position[0], the x axis
of the ordered pair
* * * * * * * * * * * * * * * * * * * * * * */
int Cell::getX() {
	return position[0];
}

/* * * * * * * * * * * * * * * * * * * * * * *
Cell::getY - returns position[0], the y axis
of the ordered pair
* * * * * * * * * * * * * * * * * * * * * * */
int Cell::getY() {
	return position[1];
}