#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <sstream>

#include "variables.cpp"
#include "functions.h"
#include "Cell.h"
#include "Board.h"

int main(int argc, char** argv) {
	
	std::string user_response;			// used to hold user responses
	
	Board gameOfLife;				// the game board

	// Intro
	showIntroArt();
	enterToContinue();

	// Calibration
	std::cout << std::endl;
	std::cout << "IMPORTANT: Please calibrate your window." << std::endl;
	std::cout << "I will show you a " << BOARD_LIMIT_X << " by " << BOARD_LIMIT_Y + 2
			  << " box. If you do not see a box full of '+' signs," << std::endl;
	std::cout << "please adjust your window and type 'again'." << std::endl;
	std::cout << "Type 'done' when you are finished." << std::endl;

	std::cout << std::endl;
	enterToContinue();

	calibrateWindow();

	// menu
	// loop until user quits
	while (user_response != "quit") {
		showMenu();
		std::cout << "Please choose an option: ";
		std::getline(std::cin, user_response);

		// std::cout << "user_response = " << user_response << std::endl;
		if (user_response == "calibrate") {
			calibrateWindow();
		} else if (user_response == "art") {
			showIntroArt();
			enterToContinue();
		} else if (user_response == "rules") {
			showRules();
			enterToContinue();
		} else if (user_response == "start") {
			// the game loop
			while (user_response != "quit") {
				showGameMenu();	
				
				// get user response
				std::cout << "Please choose an option: ";
				std::getline(std::cin, user_response);
				while (!(checkGameMenuValidity(user_response))) {
					std::cout << "Sorry, that isn't a valid option." << std::endl;
					std::cout << "Please choose an option: ";
					std::getline(std::cin, user_response);
				}

				// execute menu option
				if (user_response.find("show board") != std::string::npos) {
					gameOfLife.showBoard();

				} else if (user_response.find("add cell") != std::string::npos) {
					// extract number from response
					int amt = extractNumber(user_response);

					// check for no number
					if (amt == 0) {
						amt = 1;
					}

					// prompt user for cells
					for (int i=0; i<amt; i++) {
						// storage for user vars
						int x, y;

						std::cout << "NEW CELL # " << i+1 << std::endl;
						
						// prompt user
						std::cout << "Enter a x value: ";
						while (!(std::cin >> x)) {
							std::cin.clear();
							std::cin.ignore(256, '\n');
							std::cout << "That's not a valid value." << std::endl;
							std::cout << "Enter a x value: ";
						}

						std::cout << "Enter a y value: ";
						while (!(std::cin >> y)) {
							std::cin.clear();
							std::cin.ignore(256, '\n');
							std::cout << "That's not a valid value." << std::endl;
							std::cout << "Enter a y value: ";
						}

						// check if cell at coord
						if (gameOfLife.isAnyCellAtCoord(x, y)) {
							std::cout << "That coordinate is not available!" << std::endl;
							i--;
						} else {
							gameOfLife.addCell(Cell(x, y));
							std::cout << "New cell added at (" << x
									  << ", " << y << ")." << std::endl;
						}
						
						// clear cin
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cout << std::endl;
					}

				} else if (user_response.find("add randoms") != std::string::npos) {
					int amt = extractNumber(user_response);

					if (amt == 0) {
						// no number, default value is 60
						for (int i=0; i<60; i++) {
							Cell c1;
							if (gameOfLife.isAnyCellAtCoord(c1.getX(), c1.getY())) {
								i--;
							} else {
								gameOfLife.addCell(c1);
							}
						}

						gameOfLife.showBoard();

						std::cout << "60 random cells added." << std::endl;
						enterToContinue();

					} else {
						// go by number
						for (int i=0; i<amt; i++) {
							Cell c1;
							if (gameOfLife.isAnyCellAtCoord(c1.getX(), c1.getY())) {
								i--;
							} else {
								gameOfLife.addCell(c1);
							}
						}
						std::cout << amt << " random cells added." << std::endl;
					}

				} else if (user_response.find("advance") != std::string::npos) {
					// extract number from response
					int amt = extractNumber(user_response);
					
					// iterate the board
					if (amt != 0) {
						gameOfLife.iterateGeneration(amt);
					} else {
						gameOfLife.iterateGeneration();
					}

					// pause on board view
					enterToContinue();

				} else if (user_response == "pattern") {
					showPatternMenu();

					std::cout << "Select a pattern: ";
					std::getline(std::cin, user_response);

					while ((user_response != "pinwheel") && (user_response != "big wheel") 
						&& (user_response != "glider") && (user_response != "glider gun") 
						&& (user_response != "o")) {
						std::cout << "That's not a valid pattern." << std::endl;
						std::cout << "Select a pattern: ";
						std::getline(std::cin, user_response);
					}

					int x, y;

					std::cout << "Where should the top left of the pattern be?" << std::endl;

					std::cout << "Enter a x value: ";
					while (!(std::cin >> x)) {
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cout << "That's not a valid value." << std::endl;
						std::cout << "Enter a x value: ";
					}

					std::cout << "Enter a y value: ";
					while (!(std::cin >> y)) {
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cout << "That's not a valid value." << std::endl;
						std::cout << "Enter a y value: ";
					}

					if (user_response == "pinwheel") {
						addPinwheel(x, y, gameOfLife);
					} else if (user_response == "big wheel") {
						addBigWheel(x, y, gameOfLife);
					} else if (user_response == "glider") {
						addGlider(x, y, gameOfLife);
					} else if (user_response == "glider gun") {
						addGliderGun(x, y, gameOfLife);
					} else if (user_response == "o") {
						addO(x, y, gameOfLife);
					}

					// clear cin
					std::cin.clear();
					std::cin.ignore(256, '\n');
					std::cout << std::endl;

					// display board
					gameOfLife.showBoard();

					// pause board
					enterToContinue();

				} else if (user_response.find("finish") != std::string::npos) {
					std::cout << std::endl;

					// statistics
					std::cout << "Thanks for playing!" << std::endl;
					std::cout << "The board advanced " << gameOfLife.getGeneration()
							  << " generations." << std::endl;
					std::cout << gameOfLife.getAliveCells() << " cells were born." 
							  << std::endl;
					std::cout << gameOfLife.getDeadCells() << " cells died." << std::endl;

					// clear board
					gameOfLife.resetBoard();

					// return to main menu.
					enterToContinue();
					break;

				} else if (user_response == "start over") {
					std::cout << std::endl;

					std::cout << "Starting over!" << std::endl;
					std::cout << "The board advanced " << gameOfLife.getGeneration()
							  << " generations." << std::endl;
					std::cout << gameOfLife.getAliveCells() << " cells were born." 
							  << std::endl;
					std::cout << gameOfLife.getDeadCells() << " cells died." << std::endl;

					// clear board
					gameOfLife.resetBoard();

					// return to main menu.
					enterToContinue();

				} else if (user_response == "quit") {
					// do nothing

				} else {
					std::cout << "Sorry, that is not a valid response.";
				}

				std::cout << std::endl;
			}
		} else if (user_response == "quit") {
			// valid response, but do nothing
		} else {
			std::cout << "Sorry! That's not a valid response. :(" << std::endl;
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
	return 0;
}