#ifndef TREENODE_HPP_
#define TREENODE_HPP_

class TreeNode {
public:
  TreeNode();
  virtual ~TreeNode();
  int Data;
  TreeNode* left;
  TreeNode* right;
  int balanceFactor;
private:
};

#endif