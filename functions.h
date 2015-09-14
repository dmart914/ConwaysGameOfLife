// Dave Martinez
// Assignment 1

// functions.h - see functions.cpp for documentation
// created: 2015-1-16
// modified: 

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>

#include "Cell.h"
#include "Board.h"

void showIntroArt();
void enterToContinue();
void calibrateWindow();
void showMenu();
void showRules();
void showGameMenu();
bool checkGameMenuValidity(std::string r);
int extractNumber(std::string r);
void showPatternMenu();
void addPatternCell(int x, int y, Board& bd);
void addPinwheel(int x, int y, Board& bd);
void addBigWheel(int x, int y, Board& bd);
void addGlider(int x, int y, Board& bd);
void addGliderGun(int x, int y, Board& bd);
void addO(int x, int y, Board& bd);

#endif