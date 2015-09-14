// Dave Martinez
// Assignment 1

// Cell.h - see cell.cpp for documentation
// created: 2015-1-9
// modified: 

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "variables.cpp"

class Cell {

private:
	int position[2];
	Status cell_status;

public:
	Cell();
	Cell(int x, int y);
	int* getPosition();
	void setPosition(int x, int y);
	Status getStatus();
	void setStatus(Status st);
	void report();
	int getX();
	int getY();
	
};

#endif