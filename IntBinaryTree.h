// Specification file for the IntBinaryTree class.

#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

class IntBinaryTree
{
private:
	struct TreeNode
	{
		int value;	  // Holds the value in the node.
		TreeNode* left;   // Pointer to the left child node.
		TreeNode* right;  // Pointer to the right child node.
	};

	TreeNode* root;		  // Pointer to the root node.

	// Private Member Functions
	void insert(TreeNode*&, TreeNode*&);
	void destroySubTree(TreeNode*);
	void displayInOrder(TreeNode*) const;
	int leafCount(TreeNode*);
	int treeHeight(TreeNode*);
	int treeLevelWidth(TreeNode*, int);

public:
	// Constructor
	IntBinaryTree()
	{
		root = nullptr;
	}

	// Destructor
	~IntBinaryTree()
	{
		destroySubTree(root);
	}


	// Binary Tree Operations
	void displayInOrder() const
	{
		displayInOrder(root);
	}
	int getLeafCount()
	{
		return leafCount(root);
	}
	int getTreeHeight()
	{
		return treeHeight(root);
	}

	int getTreeWidth();
	void insertNode(int);
	bool isEmpty() const;
};
#endif
