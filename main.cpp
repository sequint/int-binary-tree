// Main function file for Binary Tree Project.

#include <iostream>
#include <string>
#include "IntBinaryTree.h"
#include "functions.h"
using namespace std;

int main()
{
	IntBinaryTree tree;  // Binary Tree object.

	int choice;	     // Variable that holds the menu choice.

 // While the choice is not EXIT_PROGRAM, continue printing the menu.
	do
	{
		// Print the menu, get the user's choice.
		menu(choice);

		// Perform the user's choice.
		switch (choice)
		{
		case INSERT_INT:
			insertInteger(tree);
			break;
		case DISPLAY_IN_ORDER:
			displayTree(tree);
			break;
		case LEAF_COUNT:
			displayLeafCount(tree);
			break;
		case DISPLAY_HEIGHT:
			displayTreeHeight(tree);
			break;
		case DISPLAY_WIDTH:
			displayTreeWidth(tree);
			break;
		case EXIT_PROGRAM:
			goodbyeMessage();
			break;
		default:
			menuChoiceError(choice);
			break;
		}

	} while (choice != EXIT_PROGRAM);

	return 0;
}
