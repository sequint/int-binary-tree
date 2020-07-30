// Specification file for the program functions.

#pragma once

#include <string>
#include "IntBinaryTree.h"
using namespace std;

// Global Variables - constant menu choices
const int INSERT_INT = 1,
	  DISPLAY_IN_ORDER = 2,
	  LEAF_COUNT = 3,
	  DISPLAY_HEIGHT = 4,
	  DISPLAY_WIDTH = 5,
	  EXIT_PROGRAM = 6;

// Input Functions
void menu(int&);
void insertInteger(IntBinaryTree&);
void getInteger(int&);

// Output Functions
void displayTree(IntBinaryTree&);
void displayLeafCount(IntBinaryTree&);
void displayTreeHeight(IntBinaryTree&);
void displayTreeWidth(IntBinaryTree&);
void goodbyeMessage();
void menuChoiceError(int&);

// Input Validation Functions
void isInteger(int&);
