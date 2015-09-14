// Dave Martinez
// Assignment 1

// Board.cpp
// created: 2015-1-11
// modified: 

#include "Cell.h"
#include "Board.h"
#include "variables.cpp"

/* * * * * * * * * * * * * * * * * * * * * * *
Board::Board() - Board constrctor. Uses consts
BOARD_LIMIT_X and BOARD_LIMIT_Y to set board
size. Initializes generation, dead_cells and
alive_cells to 0.
* * * * * * * * * * * * * * * * * * * * * * */
Board::Board() {
	size_x = BOARD_LIMIT_X;
	size_y = BOARD_LIMIT_Y;
	generation = 0;
	dead_cells = 0;
	alive_cells = 0;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::Board(int x, int y) - Overloaded Board
constructor. Uses params x and y to set size
of board. Initializes generation, dead_cells,
and alive_cells to 0. 
* * * * * * * * * * * * * * * * * * * * * * */
Board::Board(int x, int y) {
	size_x = x;
	size_y = y;
	generation = 0;
	dead_cells = 0;
	alive_cells = 0;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::addCell(Cell c) - first checks if any
other cell is at Cell c coordinate. If there
is another Cell at coord, returns false.
Otherwise, adds Cell c to cells vector and 
returns true.
* * * * * * * * * * * * * * * * * * * * * * */
bool Board::addCell(Cell c) {
	if (isAnyCellAtCoord(c.getX(), c.getY())) {
		return false;
	} else {
		cells.push_back(c);
		alive_cells++; 
		return true;
	}	
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::addCellByCoord(int x, int y) - first
checks if any other cell is at (x, y) coord.
If other Cell is at coord, returns false.
Otherwise, creates Cell at (x, y) and
returns true.
* * * * * * * * * * * * * * * * * * * * * * */
bool Board::addCellByCoord(int x, int y) {
	if (isAnyCellAtCoord(x, y)) {
		return false;
	} else {
		Cell c(x, y);
		cells.push_back(c);
		return true;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::isCellAtCoord(int x, int y) - returns
true if Cell in cells vector has matching
coord to params x and y. Excludes Cells with
Status BORN (2). If no Cell is found, returns
false.
* * * * * * * * * * * * * * * * * * * * * * */
bool Board::isCellAtCoord(int x, int y) {
	for (unsigned int i=0; i<cells.size(); i++) {
		if (cells[i].getX() == x) {
			if (cells[i].getY() == y) {
				if (cells[i].getStatus() != 2) {
					return true;
				}
			}
		}
	}
	return false;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::isAnyCellAtCoord(int x, int y) - 
returns true Cell has matching coord to params
x and y. Includes Cells with Status BORN.
Otherwise, returns false.
* * * * * * * * * * * * * * * * * * * * * * */
bool Board::isAnyCellAtCoord(int x, int y) {
	for (unsigned int i=0; i<cells.size(); i++) {
		if (cells[i].getX() == x) {
			if (cells[i].getY() == y) {
				return true;
			}
		}
	}
	return false;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::getCellByCoord(int x, int y) - returns
Cell from vector cells if matching coord from
params x and y are found. Otherwise, throws
integer exception 1.
* * * * * * * * * * * * * * * * * * * * * * */
Cell Board::getCellByCoord(int x, int y) {
	for (unsigned int i=0; i<cells.size(); i++) {
		if (cells[i].getX() == x) {
			if (cells[i].getY() == y) {
				return cells[i];		
			}
		}
	}

	throw 1;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::getGeneration() - returns generation.
* * * * * * * * * * * * * * * * * * * * * * */
int Board::getGeneration() {
	return generation;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::getAliveCells() - returns alive_cells.
* * * * * * * * * * * * * * * * * * * * * * */
int Board::getAliveCells() {
	return alive_cells;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::getDeadCells() - returns dead_cells
* * * * * * * * * * * * * * * * * * * * * * */
int Board::getDeadCells() {
	return dead_cells;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::showBoard() - shows the playing field
using const ints BOARD_LIMIT_X and
BOARD_LIMIT_Y. 
Prints two rows for x axis labels. 
Prints two digits then '+' for blank spots.
Prints C if Cell exists at coord.
* * * * * * * * * * * * * * * * * * * * * * */
void Board::showBoard() {
	std::cout << "XX";
	for (int i=1; i<=BOARD_LIMIT_X; i++) {
		std::cout << floor(i/10);
	}

	std::cout << std::endl;
	std::cout << "XX";

	for (int i=1; i<=BOARD_LIMIT_X; i++) {
		std::cout << i%10;
	}
	std::cout << std::endl;

	for (int i=1; i<=BOARD_LIMIT_Y; i++) {
		for (int j=0; j<=BOARD_LIMIT_X; j++) {
			if (j == 0) {
				if (i < 10) {
					std::cout << "0" << i;
				} else {
					std::cout << i;
				}
			} else if (j == BOARD_LIMIT_X) {
				if (isCellAtCoord(j, i)) {
					std::cout << "C";
				} else {
					std::cout << "+";
				}
				std::cout << std::endl;
			} else {
				if (isCellAtCoord(j, i)) {
					std::cout << "C";
				} else {
					std::cout << "+";
				}
			}
		}
	}

	// Statistical information
	std::cout << "GENERATION: " << generation;
	std::cout << "\t\t";
	std::cout << "CELLS BORN: " << alive_cells;
	std::cout << "\t\t";
	std::cout << "CELLS DIED: " << dead_cells << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board:checkEmptyCellNeighbors(const int x,
const int y) - checks for neighbors around 
an empty Cell. If there are 3 neighbors,
creates Cell at coord (x, y), sets Status to 
BORN and adds to vector cells.
* * * * * * * * * * * * * * * * * * * * * * */
void Board::checkEmptyCellNeighbors(const int x, const int y) {
	int n = 0;
	
	if (!(isAnyCellAtCoord(x, y))) {	
		for (int i=(x-1); i<=(x+1); i++) {
			for (int j=(y-1); j<=(y+1); j++) {
				if (!(i==x && j == y)) {
					if (isCellAtCoord(i, j)) {
						n++;
					}
				}	
			}
		}
	}

	if (n == 3) {
		// New cell is born
		alive_cells++;
		Cell newCell(x, y);
		newCell.setStatus(BORN);
		cells.push_back(newCell);
	}
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::checkCellNeighbors(const int x,
const int y) - Checks for neighbors around
coord (x, y). If neighbor is empty, calls
checkEmptyCellNeighbors(i, j) on empty coord.
If original coord (x, y) has one or less
neighbors, returns int 1, indicating death.
If coord (x, y) has four or more neighbors,
returns int 1, indicating death.
* * * * * * * * * * * * * * * * * * * * * * */
int Board::checkCellNeighbors(const int x, const int y) {
	int n = 0;
	for (int i=(x-1); i<=(x+1); i++) {
		for (int j=(y-1); j<=(y+1); j++) {
			if (!(i==x && j == y)) {
				if (isCellAtCoord(i, j)) {
					n++;
				} else {
					// check empty cell's neighbors
					checkEmptyCellNeighbors(i, j);
				}
			}
		}
	}
	
	if ((n <= 1) || (n >= 4)) {
		// Cell is dead
		dead_cells++;
		return (int) 1;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::updateCells() - checks Cells in vector
cells for neighbors. If checkCellNeighbors
returns 1, sets cell Status to DEAD.
* * * * * * * * * * * * * * * * * * * * * * */
void Board::updateCells() {
	for (unsigned int i=0; i<cells.size(); i++) {
		if ((cells[i].getStatus() == 0) || (cells[i].getStatus() == 1)) {
			int cell_x = cells[i].getX();
			int cell_y = cells[i].getY();
			if (checkCellNeighbors(cell_x, cell_y) == 1) {
				cells[i].setStatus(DEAD);
			}
		}
	}
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::purgedDeadCellsAndDeliverBorn() - 
iterates through cells vector and checks 
Status of various Cells. 
If Cell has DEAD Status, erases Cell and
decrements iterator.
If Cell has BORN Status, mutates Cell Status
to ALIVE. 
* * * * * * * * * * * * * * * * * * * * * * */
void Board::purgeDeadCellsAndDeliverBorn() {
	for (unsigned int i=0; i<cells.size(); i++) {
		Status s = cells[i].getStatus();
		if (s == DEAD) {
			cells.erase(cells.begin() + i);
			i--;
		} else if (s == BORN) {
			cells[i].setStatus(ALIVE);
		}
	}
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::iterateGeneration(int i=1) - Loops i
times (default: 1):
Increments var generation.
Runs updateCells to update Cells in vector
cells.
Executes purgeDeadCellsAndDeliverBorn to
update and erase Cells.
Pauses output for 1 second.
Shows game board with showBoard.
End loop.
* * * * * * * * * * * * * * * * * * * * * * */
void Board::iterateGeneration(int i) {
	for (int j=0; j<i; j++) {
		generation++;
		updateCells();
		purgeDeadCellsAndDeliverBorn();
		usleep(500000);
		showBoard();
	}
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::purgeAllCells() - clears cells vector
* * * * * * * * * * * * * * * * * * * * * * */
void Board::purgeAllCells() {
	cells.clear();
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::resetBoard() - purges all cells from
cells vector.
Sets generation, dead_cells, alive_cells to 0.
* * * * * * * * * * * * * * * * * * * * * * */
void Board::resetBoard() {
	purgeAllCells();
	generation = 0;
	dead_cells = 0;
	alive_cells = 0;
}

/* * * * * * * * * * * * * * * * * * * * * * *
Board::jumpstartCell(int x, int y) - changes
a Cell's Status to ALIVE (1) at coordinate
provided by ints x and y.
* * * * * * * * * * * * * * * * * * * * * * */
void Board::jumpstartCell(int x, int y) {
	for (unsigned int i=0; i<cells.size(); i++) {
		if (cells[i].getX() == x) {
			if (cells[i].getY() == y) {
				cells[i].setStatus(ALIVE);
			}
		}
	}
}