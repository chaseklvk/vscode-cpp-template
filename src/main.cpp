//
//  main.cpp
//  CS20_BinaryTree
//
//  Created by Bill Komanetsky
//

#include <iostream>
#include <iomanip>
using namespace std;
#include "BinaryTree.hpp"

int main(int argc, const char * argv[]) {
    
    const int MAXSIZE = 20;
    int failedAdds = 0;
    BinaryTree* myTree = new BinaryTree();
    
    
    cout << "Inserting Nodes into Binary Search Tree" << endl;
    
    //Out-Of-Balance Tree, heavy on the left
    myTree->insert(5);
    myTree->insert(3);
    myTree->insert(2);
    myTree->insert(1);
    myTree->insert(4);
    myTree->insert(6);
    
    //Out-Of-Balance Tree, heavy on the right
    //    myTree->insert(5);
    //    myTree->insert(7);
    //    myTree->insert(9);
    //    myTree->insert(11);
    //    myTree->insert(6);
    //    myTree->insert(4);
    
    
    //In-Balance Tree
    //    myTree->insert(3);
    //    myTree->insert(1);
    //    myTree->insert(5);
    
    //
    //Calculate the height and size of your tree
    cout << endl;
    cout << "The height of your tree is: " << myTree->height() << endl;
    cout << "Size of your tree is: " << myTree->size() << endl << endl;
    
    //
    //Check the balance of the tree
    if (myTree->isInBalance()) {
        cout << "Your tree is in balance" << endl;;
    }//if
    else {
        cout << "Your tree is NOT in balance" << endl;
    }//else
    
    cout << "The largest balance factor in your tree is: " << myTree->largestBF() << endl;
    
    
    cout << endl << "Balance factor of 5 is " << myTree->getBalanceFactor(5) << endl << endl;
    
    
    
    //
    //Print the tree
    cout << endl << "Your Tree printed in reverse order" << endl;
    myTree->printTreeInRevOrder();
    cout << endl << "Your Tree printed in order" << endl;
    myTree->printTreeInFwdOrder();
    
    //
    //Delete a node from the tree
    int valueToDelete = 1807;
    if (myTree->remove(valueToDelete)) {
        cout << valueToDelete << " deleted successfully" << endl;
    }
    else {
        cout << valueToDelete << " not deleted or not found" << endl;
    }
    cout << endl << "Your Tree printed in order" << endl;
    myTree->printTreeInFwdOrder();
    
    //
    //Clean up the tree.  The destructor calls clear(), so we don't need to do it
    delete myTree;
    //myTree->clear();
    
    cout << "Program ending, have a nice day" << endl;;
    return 0;
}//main



