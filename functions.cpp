// Dave Martinez
// Assignment 1

// functions.cpp
// created: 2015-1-16
// modified: 

#include "functions.h"


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void showIntroArt() - prints the introduction art to the
game.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void showIntroArt() {
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "+                                       CONWAY'S                                 +" << std::endl;
	std::cout << "+                                     GAME OF LIFE                               +" << std::endl;
	std::cout << "+                                                                                +" << std::endl;
	std::cout << "+                                   A CS162 PROJECT                              +" << std::endl;
	std::cout << "+                                  BY Dave Martinez                              +" << std::endl;
	std::cout << "+                                     WINTER 2015                                +" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void enterToContinue() - pauses the program until the user
hits the enter or return key.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void enterToContinue() {
	std::cout << "Hit [ENTER] to continue...";
	std::cin.get();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void calibrateWindow() - shows a sample display grid so that
the user may calibrate their window.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void calibrateWindow() {
	std::string calib_response;

	while (calib_response != "done") {
		Board temp;
		temp.showBoard();
		std::cout << "The above box should be full of + signs." << std::endl;
		std::cout << "Type 'again' to try again or 'done' if things look good. ";
		std::getline(std::cin, calib_response);
		while ((calib_response != "again") && (calib_response != "done")) {
			std::cout << "Please type 'again' or 'done' without the single quotes. ";
			std::getline(std::cin, calib_response);
		}
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void showMenu() - prints the first menu
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void showMenu() {
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "+  OPTION     | ACTION                                                           +" << std::endl;
	std::cout << "+  calibrate  - recalibrate your window size                                     +" << std::endl;
	std::cout << "+  art        - show the intro art again                                         +" << std::endl;
	std::cout << "+  rules      - show an overview of Conway's Game of Life rules                  +" << std::endl;
	std::cout << "+  start      - start a new game                                                 +" << std::endl;
	std::cout << "+  quit       - exit to the terminal                                             +" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void showRules() - prints the rules to Conway's Game of Life
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void showRules() {
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "+                        HOW TO PLAY CONWAY'S GAME OF LIFE                       +" << std::endl;
	std::cout << "+ OVERVIEW:                                                                      +" << std::endl;
	std::cout << "+ Conway's Game of Life is a simulation of cellular growth on an infinite plane. +" << std::endl;
	std::cout << "+ You add cells and then allow them to live, replicate or die. You can choose    +" << std::endl;
	std::cout << "+ from a number of patterns or add your own custom layout.                       +" << std::endl;
	std::cout << "+                                                                                +" << std::endl;
	std::cout << "+    1. If a cell has 1 or 0 neighbors, it dies of loneliness.                   +" << std::endl;
	std::cout << "+    2. If a cell has 2 or 3 neighbors, it lives to the next generation.         +" << std::endl;
	std::cout << "+    3. If a cell has 4 or more neighbors, it dies of overcrowding.              +" << std::endl;
	std::cout << "+                                                                                +" << std::endl;
	std::cout << "+ To learn more about the starting patterns, 'start' a game!                     +" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}	

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void showGameMenu() - prints the game menu
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void showGameMenu() {
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "+  OPTION        | ACTION                                                        +" << std::endl;
	std::cout << "+ show board     | shows the game board                                          +" << std::endl;
	std::cout << "+ add cell [#]   | add a number of cells. If no number is provided, add one cell +" << std::endl;
	std::cout << "+ add randoms [#]| add a random set of cells. If no number is provided, adds 60  +" << std::endl;
	std::cout << "+ advance [#]    | advance a number of generations. If no number is provided,    +" << std::endl;
	std::cout << "+                | advances one generation.                                      +" << std::endl;
	std::cout << "+ pattern        | takes you to another menu to add a pattern                    +" << std::endl;
	std::cout << "+ finish         | finishes a game and takes you back to the first menu          +" << std::endl;
	std::cout << "+ start over     | clears the board and starts over                              +" << std::endl;
	std::cout << "+ quit           | quits the program and returns you to terminal                 +" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
bool checkGameMenuValidity(std::string r) - takes param r
and checks various conditions to figure out if the user's
input is a valid response to the game menu.
Returns true if response is valid and false if invalid.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
bool checkGameMenuValidity(std::string r) {
	// check show board
	if ((r.find("show board")) != std::string::npos) {
		// check that string only contains "quit"
		if (r.length() == 10) {
			return true;			
		} else {
			// check for whitespace if str longer
			for (int i=10; i<r.length(); i++) {
				if (!(isspace(r.at(i)))) {
					return false;
				}
			}
		}
		return true;
	}

	// check add cell
	if ((r.find("add cell")) != std::string::npos) {
		// check that "add cell" is at beginning
		if (r.find("add cell") == 0) {
			// check that there's nothing other than white space
			// or numerals after "add cell"
			for (int i=8; i<r.length(); i++) {
				if (!(isdigit(r.at(i))) && !(isspace(r.at(i)))) {
					return false;
				}
			}
		} else {
			return false;
		}
		return true;
	}

	// check add randoms
	if ((r.find("add randoms")) != std::string::npos) {
		// check that "add randoms" at start of str
		if (r.find("add randoms") == 0) {
			// check that there's nothing other than white space
			// or numerals after "add cell"
			for (int i=11; i<r.length(); i++) {
				if (!(isdigit(r.at(i))) && !(isspace(r.at(i)))) {
					return false;
				}
			}
		} else {
			return false;
		}
		return true;
	}

	// check advance
	if ((r.find("advance")) != std::string::npos) {
		// check that "advance" at start of str
		if (r.find("advance") == 0) {
			// check that there's nothing other than white space
			// or numerals after "advance"
			for (int i=7; i<r.length(); i++) {
				if (!(isdigit(r.at(i))) && !(isspace(r.at(i)))) {
					return false;
				}
			}
		} else {
			return false;
		}
		return true;
	}

	// check pattern
	if (r == "pattern") {
		return true;
	}

	// check finish
	if ((r.find("finish")) != std::string::npos) {
		// check that string only contains finish
		if (r.length() == 6) {
			return true;
		} else {
			// if string doesn't contain 6 chars, check that
			// all chars after are white space
			for (int i=6; i<r.length(); i++) {
				if (!(isspace(r.at(i)))) {
					return false;
				}
			}
		}
		return true;
	}

	// check start over
	if ((r.find("start over")) != std::string::npos) {
		// check that string only contains "start over"
		if (r.length() == 10) {
			return true;
		} else {
			// check for whitespace if str longer
			for (int i=10; i<r.length(); i++) {
				if (!(isspace(r.at(i)))) {
					return false;
				}
			}
		}
		return true;
	}

	// check quit
	if ((r.find("quit")) != std::string::npos) {
		// check that string only contains "quit"
		if (r.length() == 4) {
			return true;			
		} else {
			// check for whitespace if str longer
			for (int i=10; i<r.length(); i++) {
				if (!(isspace(r.at(i)))) {
					return false;
				}
			}
		}
		return true;
	}

	// for all other cases, return false
	return false;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
int extractNumber(std::string r) - extracts a number from 
a valid user response to the game menu. Uses a
stringstream object to convert the string response to a
type int. 
Returns that int or 0 if none found.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int extractNumber(std::string r) {
	// holders for substring
	std::string sub;
	int i;

	if (r.find("add cell") != std::string::npos) {
		// start index after
		i = r.find("add cell");
		i += 8;
	}

	if (r.find("add randoms") != std::string::npos) {
		// start index after
		i = r.find("add randoms");
		i += 11;
	}

	if (r.find("advance") != std::string::npos) {
		// start index after
		i = r.find("advance");
		i += 7;
	}

	// iterate through the string
	// find digits
	while (i < r.length()) {
		if (isdigit(r.at(i))) {
			sub += r.at(i);
		}
		i++;
	}

	// if no integers were found, return 0
	if (sub.length() == 0) {
		return 0;
	}

	// stringstream convert to int
	std::istringstream num(sub);
	int number;
	num >> number;

	return number;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void showPatternMenu() - prints the pattern menu
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void showPatternMenu() {
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "+  PATTERN      | DESCRIPTION                                                    +" << std::endl;
	std::cout << "+  pinwheel     | a simple, three cell pattern that repeats infinitely           +" << std::endl;
	std::cout << "+  big wheel    | a square setup of the pinwheel                                 +" << std::endl;
	std::cout << "+  glider       | a five cell pattern that moves across the screen               +" << std::endl;
	std::cout << "+  glider gun   | a pattern that generates infinite gliders                      +" << std::endl;
	std::cout << "+  o            | a still life in the shape of an 'o'                            +" << std::endl;
	std::cout << "+ NOTE: any cell belonging to a pattern will overwrite any other cell            +" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void addPatternCell(int x, int y, Board& bd) - checks for
existing cell before attempting to add a cell to coord x, y
If cell exists at coord, uses jumpStartCell() method of
class Board to flip Status to ALIVE (1). 
Otherwise, adds Cell at coord.
Used to insert pattern to Board.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void addPatternCell(int x, int y, Board& bd) {
	if (bd.isAnyCellAtCoord(x, y)) {
		bd.jumpstartCell(x, y);
	} else {
		bd.addCell(Cell(x, y));
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void addPinwheel(int x, int y, Board& bd) - adds a pinwheel
pattern to Board bd offset by x, y
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void addPinwheel(int x, int y, Board& bd) {
	addPatternCell(x, y, bd);
	addPatternCell(x, y+1, bd);
	addPatternCell(x, y+2, bd);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void addBigWheel(int x, int y, Board& bd) - adds a Big Wheel
pattern to Board bd offset by x, y
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void addBigWheel(int x, int y, Board& bd) {
	addPatternCell(x+2, y, bd);
	addPatternCell(x+3, y, bd);
	addPatternCell(x+4, y, bd);
	addPatternCell(x, y+2, bd);
	addPatternCell(x+6, y+2, bd);
	addPatternCell(x, y+3, bd);
	addPatternCell(x+6, y+3, bd);
	addPatternCell(x, y+4, bd);
	addPatternCell(x+6, y+4, bd);
	addPatternCell(x+2, y+6, bd);
	addPatternCell(x+3, y+6, bd);
	addPatternCell(x+4, y+6, bd);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void addGlider(int x, int y, Board& bd) - adds a Glider
pattern to Board bd offset by x, y
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void addGlider(int x, int y, Board& bd) {
	addPatternCell(x+1, y, bd);
	addPatternCell(x+2, y+1, bd);
	addPatternCell(x, y+2, bd);
	addPatternCell(x+1, y+2, bd);
	addPatternCell(x+2, y+2, bd);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void addGliderGun(int x, int y, Board& bd) - adds a Gosper
Glider Gun pattern to Board bd offset by x, y
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void addGliderGun(int x, int y, Board& bd) {
	addPatternCell(x, y+4, bd);
	addPatternCell(x, y+5, bd);
	addPatternCell(x+1, y+4, bd);
	addPatternCell(x+1, y+5, bd);

	addPatternCell(x+10, y+4, bd);
	addPatternCell(x+10, y+5, bd);
	addPatternCell(x+10, y+6, bd);
	addPatternCell(x+11, y+3, bd);
	addPatternCell(x+11, y+7, bd);
	addPatternCell(x+12, y+2, bd);
	addPatternCell(x+13, y+2, bd);
	addPatternCell(x+12, y+8, bd);
	addPatternCell(x+13, y+8, bd);

	addPatternCell(x+14, y+5, bd);
	addPatternCell(x+15, y+3, bd);
	addPatternCell(x+15, y+7, bd);
	addPatternCell(x+16, y+4, bd);
	addPatternCell(x+16, y+5, bd);
	addPatternCell(x+16, y+6, bd);
	addPatternCell(x+17, y+5, bd);

	addPatternCell(x+20, y+2, bd);
	addPatternCell(x+20, y+3, bd);
	addPatternCell(x+20, y+4, bd);
	addPatternCell(x+21, y+2, bd);
	addPatternCell(x+21, y+3, bd);
	addPatternCell(x+21, y+4, bd);
	addPatternCell(x+22, y+1, bd);
	addPatternCell(x+22, y+5, bd);
	addPatternCell(x+24, y, bd);
	addPatternCell(x+24, y+1, bd);
	addPatternCell(x+24, y+5, bd);
	addPatternCell(x+24, y+6, bd);

	addPatternCell(x+34, y+2, bd);
	addPatternCell(x+34, y+3, bd);
	addPatternCell(x+35, y+2, bd);
	addPatternCell(x+35, y+3, bd);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
void addO(int x, int y, Board& bd) - adds a 'o' pattern to
Board bd offset by x, y
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void addO(int x, int y, Board& bd) {
	addPatternCell(x+1, y, bd);
	addPatternCell(x+2, y, bd);
	addPatternCell(x, y+1, bd);
	addPatternCell(x, y+2, bd);
	addPatternCell(x+3, y+1, bd);
	addPatternCell(x+3, y+2, bd);
	addPatternCell(x+1, y+3, bd);
	addPatternCell(x+2, y+3, bd);
}