// Implementation file for the program functions.

#include <iostream>
#include <string>
#include "functions.h"
using namespace std;


//*******************************************************************************************
//					INPUT FUNCTIONS	    				    *
//*******************************************************************************************


//*******************************************************************************************
// menu Function									    *
//											    *
// This function gives the user a list of numbered choices, gets the choice from the user,  *
// then validates that the choice is valid.						    *
//*******************************************************************************************

void menu(int& choice)
{
	// Display the menu and get the user's choice.
	cout << "\n\nMAIN MENU\n\n";
	cout << INSERT_INT << ") Insert an Integer\n";
	cout << DISPLAY_IN_ORDER << ") Display Tree in Order\n";
	cout << LEAF_COUNT << ") Display Leaf Count\n";
	cout << DISPLAY_HEIGHT << ") Display Tree Height\n";
	cout << DISPLAY_WIDTH << ") Display Tree Width\n";
	cout << EXIT_PROGRAM << ") Exit the Program\n\n";
	cout << "Enter a number from the menu options: ";
	cin >> choice;

	// Check if the input is an integer.
	isInteger(choice);
}

//*******************************************************************************************
// insertInteger Function								    *
//											    *
// This function gets an integer from the user, then call insertNode to insert the value    *
// into the tree.									    *
//*******************************************************************************************

void insertInteger(IntBinaryTree& tree)
{
	int newInt;  // Holds the user's value to be inserted into the tree.

	// Get an integer from the user and store it into newInt.
	getInteger(newInt);

	// Insert the new value into the tree.
	tree.insertNode(newInt);
}

//*******************************************************************************************
// getInteger Function									    *
//											    *
// This function prompts the user for an integer, and continues to do so while the input    *
// is not an integer.									    *
//*******************************************************************************************

void getInteger(int& value)
{
	// Get an integer from the user, and check that it is an integer.
	cout << "\nPlease enter a number that you would like to insert into the tree: ";
	cin >> value;
	isInteger(value);
}



//*******************************************************************************************
//					OUTPUT FUNCTIONS				    *
//*******************************************************************************************


//*******************************************************************************************
// displayTree Function									    *
//											    *
// This function displays the tree in order.						    *
//*******************************************************************************************

void displayTree(IntBinaryTree& tree)
{
	// General message printed before tree order is displayed.
	cout << "\nTree in order:";

	// If the tree is empty.
	if (tree.isEmpty())
		cout << " The tree is empty.";
	// Otherwise, display the tree in order.
	else
		tree.displayInOrder();

	cout << "\n";
}

//*******************************************************************************************
// displayLeafCount Function								    *
//											    *
// This function displays the number of leaves on the tree.				    *
//*******************************************************************************************

void displayLeafCount(IntBinaryTree& tree)
{
	// Store leaf count into a variable.
	int leafCount = tree.getLeafCount();

	cout << "\nLeaf Count: ";

	// If the tree is empty.
	if (leafCount == 0)
		cout << leafCount << ", the tree is empty.\n";
	// Otherwise, print the count.
	else
		cout << leafCount << "\n";
}

//*******************************************************************************************
// displayTreeHeight Function								    *
//											    *
// This function displays the largest count of nodes vertically in the tree.		    *
//*******************************************************************************************

void displayTreeHeight(IntBinaryTree& tree)
{
	int treeHeight = tree.getTreeHeight();  // Holds the height of the tree.

	cout << "\nTree Height: ";

	// If the tree is empty, display empty message. (-1 check instead of calling isEmpty() to save on runtime.)
	if (treeHeight == -1)
		cout << "The tree is empty.\n";
	// Otherwise, print the height.
	else
		cout << treeHeight << "\n";
}

//*******************************************************************************************
// displayTreeWidth Function								    *
//											    *
// This function displays the width of the tree by finding the level with the most	    *
// amount of nodes in it.								    *
//*******************************************************************************************

void displayTreeWidth(IntBinaryTree& tree)
{
	int treeWidth = tree.getTreeWidth();  // Holds the width of the tree.

	cout << "\nTree Width: ";

	// If the tree is empty, display empty message. (-1 check instead of calling isEmpty() to save on runtime.)
	if (treeWidth == -1)
		cout << "The tree is empty.\n";
	// Otherwise, print the width.
	else
		cout << treeWidth << "\n";
}

//*******************************************************************************************
// goodbyeMessage Function								    *
//											    *
// This function prints a goodbye message used at the exit of the program. 		    *
//*******************************************************************************************

void goodbyeMessage()
{
	cout << "\nGoodbye!\n";
}

//*******************************************************************************************
// menuChoiceError Function								    *
//											    *
// This function prints an error message to inform user that their selection is not valid.  *
//*******************************************************************************************

void menuChoiceError(int& choice)
{
	cout << "\nError, '" << choice << "' is not a menu option.\n";
}



//*******************************************************************************************
//				INPUT VALIDATION FUNCTIONS				    *
//*******************************************************************************************


//*******************************************************************************************
// isInteger Function									    *
//											    *
// This functions takes checks if the input is an integer, and prompts for another input    *
// if it is not.									    *
//*******************************************************************************************

void isInteger(int& input)
{
	// While input is not an integer, prompt the user for another choice.
	while (cin.fail())
	{
		cout << "\nError, input must be a number.\n";
		cin.clear();
		cin.ignore(INT8_MAX, '\n');
		cout << "Please enter a number: ";
		cin >> input;
	}
}
