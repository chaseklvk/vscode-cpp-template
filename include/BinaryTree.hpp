/*
 * BinaryTree.hpp
 *
 * 
 *      Author: bkomanet
 */

#ifndef BINARYTREE_HPP_
#define BINARYTREE_HPP_

#include "TreeNode.hpp"

class BinaryTree {
public:
	BinaryTree();
	virtual ~BinaryTree();

    bool insert(int);
    void printTreeInFwdOrder(void);
    void printTreeInRevOrder(void);
    int size(void);
    void clear(void);
    bool remove(int);
    int height(void);
    int getBalanceFactor(int);
    int largestBF(void);
    bool isInBalance(void);

private:
    TreeNode *rootNode = nullptr;

    bool insertNode(TreeNode* &, TreeNode*);
    void printNodesRev(TreeNode*);
    void printNodesFwd(TreeNode*);
    int treeSize(TreeNode*);
    void clearTree(TreeNode* &);
    bool isLeaf(TreeNode* root);
    bool hasLeftChild(TreeNode*);
    bool hasRightChild(TreeNode*);
    bool deleteNode(TreeNode* &, int);
    TreeNode* findNode(TreeNode*, int);

    //** You need to implement these functions
    int calculateHeight(TreeNode*);
    int calculateBalance(TreeNode*);
    int getLargestBF(TreeNode*);

}; //BinaryTree

#endif /* BINARYTREE_HPP_ */
