// Dave Martinez
// Assignment 1

// Board.h - see Board.cpp for documentation
// created: 2015-1-11
// modified: 

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <unistd.h>

class Cell;

class Board {

private:
	int size_x;
	int size_y;
	std::vector<Cell> cells;
	int generation;
	int dead_cells;
	int alive_cells;

public:
	Board();
	Board(int x, int y);
	bool addCell(Cell c);
	bool addCellByCoord(int x, int y);
	bool isCellAtCoord(int x, int y);
	bool isAnyCellAtCoord(int x, int y);
	Cell getCellByCoord(int x, int y);
	int getGeneration();
	int getAliveCells();
	int getDeadCells();
	void showBoard();
	void checkEmptyCellNeighbors(int x, int y);
	int checkCellNeighbors(int x, int y);
	void updateCells();
	void purgeDeadCellsAndDeliverBorn();
	void iterateGeneration(int i = 1);
	void purgeAllCells();
	void resetBoard();
	void jumpstartCell(int x, int y);
};

#endif