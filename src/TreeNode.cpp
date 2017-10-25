//
//  TreeNode.cpp
//  CS20_BinaryTree
//
//  Created by Bill Komanetsky on 10/17/17.
//  Copyright © 2017 Bill Komanetsky. All rights reserved.
//

#include "TreeNode.hpp"
#include <iostream>
using namespace std;

TreeNode::TreeNode() {
    Data = 0;
    Left = nullptr;
    Right = nullptr;
    BalanceFactor = 0;
}//TreeNode()

TreeNode::~TreeNode() {
    cout << "Deleting node: " << Data << endl;
}//~TreeNode()
