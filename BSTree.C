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

/*------------------------------------------------------------------
adds a new element to the BSTree

Preconditions: none.
Postconditions: BSTreeSize++
------------------------------------------------------------------*/
void BSTree::Insert(BNode *node, sType name){

    BNode *newNode = new BNode;
    newNode->LastName = name;

    //if tree is empty
    if(root == NULL){
        root = newNode;
        BSTreeSize++;
        return;
    }

    if(node->LastName > name){
        if(node->left != NULL){
            Insert(node->left, name);
        }
        else{
            node->left = newNode;
            BSTreeSize++;
            return;
        }
    }
    else{
        if(node->right != NULL){
            Insert(node->right, name);
        }
        else{
            node->right = newNode;
            BSTreeSize++;
        }
    }
}

/*------------------------------------------------------------------
Prints the BSTree in order. least to greatest

Preconditions: none.
Postconditions: none
------------------------------------------------------------------*/
void BSTree::PrintInOrder(BNode *node){
    if (node == NULL){
        //cout << "Tree is Empty" << endl;
        return;
    }
 
     /* first recur on left child */
     PrintInOrder(node->left);
 
     /* then print the data of node */
     cout << node->LastName << endl;  
 
     /* now recur on right child */
     PrintInOrder(node->right);
}

/*------------------------------------------------------------------
searches the tree for any last name

Preconditions: none.
Postconditions: none
------------------------------------------------------------------*/
void BSTree::Find(BNode* startNode, string target, BNode** location){
    if(startNode == NULL){
        return;
    }
    if(startNode->LastName == target){
        location = &startNode;
        return;
    }
    if(startNode->left != NULL){
        Find(startNode->left, target, location);
    }
    if(startNode->right != NULL){
        Find(startNode->right, target, location);
    }
}


/*------------------------------------------------------------------
Returns an integer equal to the number of nodes in the tree

Preconditions: none.
Postconditions: none
------------------------------------------------------------------*/
int BSTree::Count(){

    return(BSTreeSize);
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

/*------------------------------------------------------------------
pass in a node and this function will find the smallest node greater than it

Preconditions: none.
Postconditions: none
------------------------------------------------------------------*/
BNode* BSTree::Successor(BNode *node){

    return(FindMin(node)); 
}

/*------------------------------------------------------------------
pass in a node and this function will find the greatest node smaller than it

Preconditions: none.
Postconditions: none
------------------------------------------------------------------*/
BNode* BSTree::Predecessor(BNode *node){

    return(FindMax(node));
}

/*------------------------------------------------------------------
finds the smallest element in the tree

Preconditions: none.
Postconditions: none
------------------------------------------------------------------*/
BNode* BSTree::FindMin(BNode *node){
    if(node->left == NULL){
        return(node);
    }
    else{
        FindMin(node->left);
    }
}


/*------------------------------------------------------------------
finds the largest element in the tree

Preconditions: none.
Postconditions: none
------------------------------------------------------------------*/
BNode* BSTree::FindMax(BNode *node){
    if(node->right == NULL){
        return(node);
    }
    else{
        FindMin(node->right);
    }
}