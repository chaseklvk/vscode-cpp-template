/*
 * BinaryTree.cpp
 *
 * 
 *      Author: bkomanet
 */

#include <iostream>
#include <iomanip>
#include "BinaryTree.hpp"
using namespace std;

//
//Default constructor
BinaryTree::BinaryTree() {
	// TODO Auto-generated constructor stub
}//BinaryTree()

//
//Destructor
BinaryTree::~BinaryTree() {
	// TODO Auto-generated destructor stub
	this->clear();
}//~BinaryTree()

//***********************************************************
//Public Functions
//***********************************************************

//
//Public function which inserts an integer into the tree
bool BinaryTree::insert(int anInt) {
	TreeNode* newNode = new TreeNode();
	newNode->Data = anInt;

	if (insertNode(rootNode, newNode)) {
		return true;
	}//if
	else {
		delete newNode;
		return false;
	}//else
}//insert

//
//Public function which will print the tree in forward order
void BinaryTree::printTreeInFwdOrder(void) {
	if (this->size() > 0) {
		cout << right << setw(8) << "Data" << setw(16) << "Balance Factor" << endl;
		cout << right << setw(8) << "----" << setw(16) << "--------------" << endl;
		printNodesFwd(rootNode);
	}//if
	else {
		cout << endl << "The tree is empty" << endl << endl;
	}
}//printTreeInFwdOrder;

//
//Public function which will print the tree in reverse order
void BinaryTree::printTreeInRevOrder(void) {
	if (this->size() > 0) {
		cout << right << setw(8) << "Data" << setw(16) << "Balance Factor" << endl;
		cout << right << setw(8) << "----" << setw(16) << "--------------" << endl;
		printNodesRev(rootNode);
	}//if
	else {
		cout << endl << "The tree is empty" << endl << endl;
	}
}//printTreeInRevOrder;

//
//Public function which will calculate the size of the tree (number of nodes)
int BinaryTree::size(void) {
	return treeSize(rootNode);
}//getTreeSize

//
//Public function which will delete/clear all nodes in the tree
void BinaryTree::clear(void) {
	clearTree(rootNode);
}//clear

//
//Public function which will return whether or not a tree is in balance
//True if the tree is in balance, False if it is not
bool BinaryTree::isInBalance(void) {
	calculateBalance(rootNode);			//Calculate all Balance Factors in the tree
	int anInt = largestBF();			//Find the largest balanace factor
	if (abs(anInt) > 1) {				//If it is > 1 or < -1, the tree is out of balance
		return false;
	}//if
	else {
		return true;
	}//else
}//isInBalance

//
//Public function which will remove a node with a certain value
bool BinaryTree::remove(int valueToFind) {
	return deleteNode(rootNode, valueToFind);
}//remove

//
//Public function which calls the private function calculateHeight to get the height of the tree
int BinaryTree::height(void) {
	return calculateHeight(rootNode);
}//height

//
//Public function which calls findNode with an int value and then returns its balance factor
int BinaryTree::getBalanceFactor(int valueToFind) {
	TreeNode* aNode = findNode(rootNode, valueToFind);
	if (aNode == nullptr) {
		return -999;
	}//if
	else {
		return aNode->BalanceFactor;
	}//else
}//getBalanceFactor

//
//Public function which returns the largest balance factor in the tree.  Used by function isInBalance
int BinaryTree::largestBF(void) {
	return getLargestBF(rootNode);
}


//***********************************************************
//Private Functions
//***********************************************************

//
//Private function called by the public insert function to add a new node to the
//tree
bool BinaryTree::insertNode(TreeNode* &rootNode, TreeNode* newNode) {
    if (rootNode == nullptr) {
        rootNode = newNode;
        return true;
    }//if
    else if (newNode->Data < rootNode->Data) {
        return insertNode(rootNode->Left, newNode);
    }//else if
    else if (newNode->Data > rootNode->Data) {
        return insertNode(rootNode->Right, newNode);
    }//else if
    else {
        return false;
    }//else
}//isnertNode

//
//Private function called by printTreeInFwdOrder to print the tree in forward order
void BinaryTree::printNodesFwd(TreeNode* rootNode) {
    if (rootNode != nullptr) {
    	printNodesFwd(rootNode->Left);
        cout << right << setw(8) << rootNode->Data << setw(16) << rootNode->BalanceFactor << endl;
        printNodesFwd(rootNode->Right);
    }//if
}//printTree;

//
//Private function called by printTreeInRevOrder to print the tree in reverse order
void BinaryTree::printNodesRev(TreeNode* rootNode) {
    if (rootNode != nullptr) {
    	printNodesRev(rootNode->Right);
        cout << right << setw(8) << rootNode->Data << setw(16) << rootNode->BalanceFactor << endl;
        printNodesRev(rootNode->Left);
    }//if
}//printNodesRev

//
//Private function called by the public function size to return the number of nodes in the tree
int BinaryTree::treeSize(TreeNode* rootNode) {
    if (rootNode != nullptr) {
        int aValue = treeSize(rootNode->Left);
        aValue += treeSize(rootNode->Right);
        return ++aValue;
    }//if
    else {}

    return 0;
}//treeSize;

//
//Private function called by the public function size and will clear all nodes in the tree
void BinaryTree::clearTree(TreeNode* &rootNode) {
    if (rootNode != nullptr) {
        clearTree(rootNode->Left);
        clearTree(rootNode->Right);
        delete rootNode;
    }//if
}//clearTree;

//
//Private function which calculates the balance factor of a node and its branches/leafs.
//Called by isInBalance
int BinaryTree::calculateBalance(TreeNode* rootNode) {
    // If the function is passed nullptr, return zero 
    if (rootNode == nullptr) return 0;
    
    // Set the balance factor of the current node to the height of the left - the height of the right
    // This calculation itself will not be accurate because we are calculating the height of the left and right subtrees
    rootNode->BalanceFactor = calculateHeight(rootNode->Left) - calculateHeight(rootNode->Right);
    
    // If the node has a left child, add one to the balance factor to compensate for above calculation
    if (hasLeftChild(rootNode))
        rootNode->BalanceFactor += 1;
    
    // Similarly, subtract one from the balance factor if there is a right child
    if (hasRightChild(rootNode))
        rootNode->BalanceFactor -= 1;

    // Calculate the balance for the left and right nodes
    calculateBalance(rootNode->Left);
    calculateBalance(rootNode->Right);
    return 0;   // Return zero... This should probably be a void function?
}//calculateBalance

//
//Private function returning the balance factor of a particular node.  Called by isInBalance
int BinaryTree::calculateHeight(TreeNode* rootNode) {
    // Define variables to store the left and right heights
    int leftHeight = 0; 
    int rightHeight = 0;

    // If the current node is a leaf, the height is zero by definition
    if (isLeaf(rootNode)) return 0;
    
    // If the current node has a left child, calculate the height of the child and add one to the count
    if (hasLeftChild(rootNode))
        leftHeight = calculateHeight(rootNode->Left) + 1;

    // if the current node has a right child, calculate the height of the child and add one to the count
    if (hasRightChild(rootNode))
        rightHeight = calculateHeight(rootNode->Right) + 1;

    // Return the height of the larger subtree
    if (leftHeight > rightHeight)
        return leftHeight;
    else 
        return rightHeight;
    
}//calculateHeight

//
//Private function which returns the largest balance factor in the tree.  Called by largestBF
int BinaryTree::getLargestBF(TreeNode* rootNode) {
    // If we are on a leaf or the rootNode is nullptr, the balance factor will be zero
    if (rootNode == nullptr || isLeaf(rootNode)) return 0;

    int currentBF = abs(rootNode->BalanceFactor);   // Store the absolute value of the current balance factor
    int leftBF = getLargestBF(rootNode->Left);  // Grab the largest balance factor of the left subtree
    int rightBF = getLargestBF(rootNode->Right);    // Grab the largest balance factor of the right subtree

    // Store the absolute values of the balance factors for comparison
    // New variables are created so the real balance factor can be returned for display
    int absLBF = abs(leftBF);   
    int absRBF = abs(rightBF);

    // If the left/right balance factor is larger or equal to the right/left balance factor and the current balance factor, 
    // it is the largest balance factor in the subtree
    if (absLBF >= currentBF && absLBF >= absRBF) return leftBF;
    else if (absRBF >= currentBF && absRBF >= absLBF) return rightBF;
    else if (currentBF >= absLBF && currentBF >= absRBF) return rootNode->BalanceFactor; // If the current node's balance factor is larger than the left and right, it is the largest
    else return 0; // Return zero to avoid infinite recursion if all cases fail
}//getLargestBF

//
//Private function called by remove which will delete a node from the tree with a certain value
bool BinaryTree::deleteNode(TreeNode* &rootNode, int valueToFind) {
    if (rootNode == nullptr) {
        return false;
    }
    else if (rootNode->Data == valueToFind) {
        //delete the node here
        if (rootNode->Right == nullptr) {
            TreeNode* holdNode = rootNode;
            rootNode = rootNode->Left;
            delete holdNode;
        }
        else if (rootNode->Left == nullptr) {
            TreeNode* holdNode = rootNode;
            rootNode = rootNode->Right;
            delete holdNode;
        }
        else if (rootNode->Right->BalanceFactor > rootNode->Left->BalanceFactor) {
            TreeNode* rightNode = rootNode->Right;
            TreeNode* leftNode = rootNode->Left;
            delete rootNode;
            rootNode = rightNode;
            insertNode(rootNode, leftNode);
        }
        else {
            TreeNode* rightNode = rootNode->Right;
            TreeNode* leftNode = rootNode->Left;
            delete rootNode;
            rootNode = leftNode;
            insertNode(rootNode, rightNode);
        }
        return true;
    }//elseif
    else {
        if (valueToFind < rootNode->Data) {
            return deleteNode(rootNode->Left, valueToFind);
        }//if
        else {
            return deleteNode(rootNode->Right, valueToFind);
        }//else
    }
}//deleteNode

//
//Private function called by remove which will delete a node from the tree with a certain value
TreeNode* BinaryTree::findNode(TreeNode* rootNode, int valueToFind) {
    if (rootNode == nullptr) {
        return nullptr;
    }
    else if (rootNode->Data == valueToFind) {
        return rootNode;
    }//elseif
    else {
        if (valueToFind < rootNode->Data) {
            return findNode(rootNode->Left, valueToFind);
        }//if
        else {
            return findNode(rootNode->Right, valueToFind);
        }//else
    }
}//findNode

//
//Private function which will return true if a node is a leaf and false if it is a branch
bool BinaryTree::isLeaf(TreeNode* root) {
    if (root->Left == nullptr && root->Right == nullptr) {
        return true;
    }//if
    else {
        return false;
    }//else
}//isLeaf

//
//Private function which will return a true if the node has a left child, false if not
bool BinaryTree::hasLeftChild(TreeNode* root) {
    if (root->Left != nullptr) {
        return true;
    }//if
    else {
        return false;
    }//else
}//hasLeftChild

//
//Private function which will return a true if the node has a right child, false if not
bool BinaryTree::hasRightChild(TreeNode* root) {
    if (root->Right != nullptr) {
        return true;
    }//if
    else {
        return false;
    }//else
}//hasRightChild

