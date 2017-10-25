//
//  TreeNode.hpp
//  CS20_BinaryTree
//
//  Created by Bill Komanetsky on 10/17/17.
//  Copyright © 2017 Bill Komanetsky. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

class TreeNode {
public:
    TreeNode();
    virtual ~TreeNode();
    
    int Data;
    TreeNode* Left;
    TreeNode* Right;
    int BalanceFactor;
    
private:
    
};


#endif /* TreeNode_hpp */
