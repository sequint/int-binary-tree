// Steven Quintana
// Ch. 21 Assignment - Binary Tree Project
// July 29, 2020

// Implementation file for the IntBinaryTree class.

#include <iostream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;


//*******************************************************************************************
//								 PRIVATE MEMEBER FUNCTIONS									*
//*******************************************************************************************

//*******************************************************************************************
// insert Function																			*
//																							*
// This function takes the reference of two pointers (root & new) and traverses the tree	*
// for the next null node, then insert the new node there. The traverse compares the		*
// two pointers and continues the traverse two the left or right depending on the value.	*
//*******************************************************************************************

void IntBinaryTree::insert(TreeNode*& nodePtr, TreeNode*& newNode)
{
	// If the pointer is pointing to a null node, insert the new node.
	if (nodePtr == nullptr)
		nodePtr = newNode;
	// Else, if the new node value is less than the pointer's, continue to traverse to the left.
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);
	// Otherwise, continue the traverse to the right.
	else
		insert(nodePtr->right, newNode);
}

//*******************************************************************************************
// destroySubTree Function																	*
//																							*
// This function deletes all nodes in the tree.												*
//*******************************************************************************************

void IntBinaryTree::destroySubTree(TreeNode* nodePtr)
{
	// If the current node exists, continue the traverse.
	if (nodePtr)
	{
		// If a left node exists, continue the traverse left.
		if (nodePtr->left)
			destroySubTree(nodePtr->left);

		// If a right node also exists, continue the traverse right.
		if (nodePtr->right)
			destroySubTree(nodePtr->right);

		// Once a leaf is reached, delete the node and each node traversed as the recursive function continues each iteration.
		delete nodePtr;
	}
}

//*******************************************************************************************
// displayInOrder Function																	*
//																							*
// This function displays the tree in order from small to large by traversing each nodes	*
// left side first until null then displaying those values in reverse, then it traverses	*
// right and continues to do the same until there are no more left child nodes.				*
//*******************************************************************************************

void IntBinaryTree::displayInOrder(TreeNode* nodePtr) const
{
	// If the node exists, continue the traverse (base case).
	if (nodePtr)
	{
		// Point to the next lowest value (traverse left).
		displayInOrder(nodePtr->left);

		// Display values that have been traversed through.
		cout << " " << nodePtr->value;

		// Traverse the right side of the node.
		displayInOrder(nodePtr->right);
	}
}

//*******************************************************************************************
// leafCount Function																		*
//																							*
// This function traverses through the tree and counts every leaf node.						*
//*******************************************************************************************

int IntBinaryTree::leafCount(TreeNode* nodePtr)
{
	// If the node is empty return 0.
	if (nodePtr == nullptr)
		return 0;
	// Else, if the node is a leaf (no left or right children) return 1.
	else if (nodePtr->left == nullptr && nodePtr->right == nullptr)
		return 1;
	// Otherwise, continue the traverse on each side while adding results together for a running total to be returned.
	else
		return leafCount(nodePtr->left) + leafCount(nodePtr->right);
}

//*******************************************************************************************
// treeHeight Function																		*
//																							*
// This function traverses each side of the tree and counts the heights, then returns		*
// the larger number, indicating the max tree height.										*
//*******************************************************************************************

int IntBinaryTree::treeHeight(TreeNode* nodePtr)
{
	// If the node is empty return 0.
	if (nodePtr == nullptr)
		return -1;
	// Else, if the only node is the root, return a '0' height.
	else if (nodePtr->left == nullptr && nodePtr->right == nullptr)
		return 0;
	// Otherwise, traverse each side and get the max height.
	else
	{
		int leftHeight = treeHeight(nodePtr->left) + 1,    // Recursivly count left side height and store the number.
			rightHeight = treeHeight(nodePtr->right) + 1;  // Recursivly count right side height and store the number.

		// Return the height of the larger side.
		if (leftHeight > rightHeight)
			return leftHeight;
		else
			return rightHeight;
	}
}

//*******************************************************************************************
// treeLevelWidth Function																	*
//																							*
// This function takes a desired level to search for along with the root as it's			*
// arguments, then traverses to that level and adds each right and left node together		*
// to get the total number of nodes on the level.											*
//*******************************************************************************************

int IntBinaryTree::treeLevelWidth(TreeNode* nodePtr, int level)
{
	// If the pointer is null, the amount traversed in a certain directection has been reached, return '0'.
	if (nodePtr == nullptr)
		return 0;

	// If the root level is reached return 1. (Used as a counter for each level of traverse on either side)
	if (level == 0)
		return 1;
	// Otherwise, while the level is greater than the root level add the amount of traversed levels on both sides together.
	else
		return treeLevelWidth(nodePtr->left, level - 1) + treeLevelWidth(nodePtr->right, level - 1);
}



//*******************************************************************************************
//								   BINARY TREE OPERATIONS									*
//*******************************************************************************************

//*******************************************************************************************
// getTreeWidth Function																	*
//																							*
// This function finds the level of each tree, then returns the number of nodes in the		*
// widest level found.																		*
//*******************************************************************************************

int IntBinaryTree::getTreeWidth()
{
	int largestLevel = 0,			   // Holds the number of nodes in the largest tree level.
		levelWidth = 0,				   // Temporarily holds the width of each tree level.
		treeHeight = getTreeHeight();  // Holds the height of the tree.

	// If the tree height is -1, then the tree is empty, return -1.
	if (treeHeight == -1)
		return -1;
	// Otherwise, find the largest level's width.
	else
	{
		// Loop through each level of the tree.
		for (int count = 0; count <= treeHeight; count++)
		{
			// Get the current level's width and store the number into levelWidth.
			levelWidth = treeLevelWidth(root, count);

			// If the current level's width is larger than the largest level so far, make the current level the largest.
			if (levelWidth > largestLevel)
				largestLevel = levelWidth;
		}
		return largestLevel;
	}
}

//*******************************************************************************************
// insertNode Function																		*
//																							*
// This function dynamically creates a new tree node with the user's passed num value,		*
// then stores it into the tree by passing the new number into the insert function.			*
//*******************************************************************************************

void IntBinaryTree::insertNode(int num)
{
	TreeNode* newNode = nullptr;  // Pointer to the new node.

	// Create a new tree node and store num in it.
	newNode = new TreeNode;
	newNode->value = num;

	// Initialize the new node's left and right value to null.
	newNode->left = newNode->right = nullptr;

	// Insert the new node into the next available node in the tree.
	insert(root, newNode);
}

//*******************************************************************************************
// isEmpty Function																			*
//																							*
// This funtion tests if the root node is empty and returns true if it is and false if it	*
// is not.																					*
//*******************************************************************************************

bool IntBinaryTree::isEmpty() const
{
	bool status;  // Returns the status of an empty or filled tree.

	if (root == nullptr)
		return true;
	else
		return false;
}