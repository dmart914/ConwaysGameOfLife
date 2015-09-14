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



int main() {
	// get random seed
	srand (time(NULL));

	Cell c1;
	std::cout << "Cell c1: " << std::endl;
	c1.report();

	std::cout << std::endl;

	std::cout << "Cell c2: " << std::endl;
	Cell c2(3, 5);
	c2.report();

	std::cout << std::endl;

	// getPosition()
	std::cout << "Using getPosition(): " << std::endl;
	int* c1pos = c1.getPosition();
	std::cout << "c1's x: " << c1pos[0] << std::endl;
	std::cout << "c1's y: " << c1pos[1] << std::endl;

	std::cout << std::endl;	

	// setPosition()
	std::cout << "setPosition()" << std::endl;
	std::cout << "Setting c2's pos to (1, 1)" << std::endl;
	c2.setPosition(1, 1);
	c2.report();

	std::cout << std::endl;	

	// getStatus()
	std::cout << "Checking c1's status: ";
	(c1.getStatus() == 0) ? std::cout << "DEAD" : std::cout << "ALIVE";
	std::cout << std::endl;

	std::cout << std::endl;

	// setStatus()
	std::cout << "Killing c1 with setStatus()" << std::endl;
	c1.setStatus(DEAD);
	c1.report();




	return 0;
}