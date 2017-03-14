/*------------------------------------------------------------------

------------------------------------------------------------------*/

#include "BSTree.h"
#include <iostream>
#include <cstdlib>
#include <string>


// ************************** Public Functions *********************
/*------------------------------------------------------------------
The default BSTree constructor.

Preconditions: none.
Postconditions: BSTreeSize = 0 root is NULL
------------------------------------------------------------------*/
BSTree::BSTree () {
    BSTreeSize = 0;
    root = NULL;
}


/*------------------------------------------------------------------
The default BSTree destructor.

Preconditions: none.
Postconditions: BSTreeSize = 0; root = NULL
------------------------------------------------------------------*/
BSTree::~BSTree () {
    Clear(root);
}

void BSTree::Insert(BNode *node, sType name){

    BNode *newNode = new BNode;
    newNode->LastName = name;

    //if tree is empty
    if(root == NULL){
        root -> LastName = name;
        return;
    }

    if(node->LastName > name){
        if(node->left != NULL){
            Insert(node->left, name);
        }
        else{
            node->left = newNode;
            return;
        }
    }
    else{
        if(node->right != NULL){
            Insert(node->right, name);
        }
        else{
            node->right = newNode;
        }
    }
}


/********************************************************************

Private Functions
********************************************************************/

void BSTree::Clear(BNode *n){
    if(n -> left != NULL){
        Clear(n -> left);
    }
    if(n -> right != NULL){
        Clear(n -> right);
    }
    delete n;
    n = NULL;
}