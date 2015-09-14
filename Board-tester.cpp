// Dave Martinez
// Assignment 1

// Cell-tester.cpp - a testing file for the Cell class
// created: 2015-1-9
// modified: 

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "Cell.h"
#include "Board.h"




int main() {

	srand(time(NULL));
/*
	Cell c1(1, 1);
	c1.report();

	Board life;
	life.addCell(c1);
	Cell c2(2, 2);
	life.addCell(c2);
	life.addCell(Cell(3, 3));
	life.addCell(Cell(3, 2));
	life.addCell(Cell(20, 2));
	life.addCell(Cell(2, 79));
	life.addCell(Cell(1, 10));
	life.addCell(Cell(2, 10));

	try {
		Cell c2 = life.getCellByCoord(1, 1);
		c2.report();
	} catch (int n) {
		std::cout << "No cell there." << std::endl;
	}

	life.showBoard();
	life.updateCells();
	life.purgeDeadCells();
	life.showBoard();
*/
	Board gameOfLife;

	for (int i=0; i<60; i++) {
		Cell c1;
		gameOfLife.addCell(c1);
	}

/*
	gameOfLife.addCell(Cell(2, 2));
	gameOfLife.addCell(Cell(3, 3));
	gameOfLife.addCell(Cell(1, 4));
	gameOfLife.addCell(Cell(2, 4));
	gameOfLife.addCell(Cell(3, 4));

	gameOfLife.addCell(Cell(7, 2));
	gameOfLife.addCell(Cell(8, 3));
	gameOfLife.addCell(Cell(6, 4));
	gameOfLife.addCell(Cell(7, 4));
	gameOfLife.addCell(Cell(8, 4));

	gameOfLife.addCell(Cell(18, 3));
	gameOfLife.addCell(Cell(18, 4));
	gameOfLife.addCell(Cell(18, 5));
*/

	gameOfLife.showBoard();
	
	gameOfLife.iterateGeneration();
	gameOfLife.iterateGeneration(100);

	return 0;
}