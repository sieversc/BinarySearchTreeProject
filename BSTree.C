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
void BSTree::Insert(BNode *node, string name){

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
            delete newNode;
        }
        else{
            newNode->parent = node;
            node->left = newNode;
            BSTreeSize++;

        }
    }
    else{
        if(node->right != NULL){
            Insert(node->right, name);
            delete newNode;
        }
        else{
            newNode->parent = node;
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
Returns an integer equal to the number of nodes in the tree

Preconditions: none.
Postconditions: none
------------------------------------------------------------------*/
int BSTree::Count(){

    return(BSTreeSize);
}

/*------------------------------------------------------------------
Non-Lazy delete    -   based on 3 base cases
    1. node passed in is a leaf
    2. node passed in has only one child
    3. node passed in has 2 children
Preconditions: none.
Postconditions: none
------------------------------------------------------------------*/
void BSTree::Delete(BNode *node){

    if(node == NULL){
        return;
    }

    //leaf case
    if(node->left == NULL && node->right == NULL){

        if(node->parent -> left == node){
            node->parent->left = NULL;
        }

        if(node->parent->right == node){
            node->parent->right = NULL;
        }
        delete node;
        return;
    }

    //case 2, only one child
    if(node->left == NULL || node->right == NULL){
        if(node->left == NULL){
            node->right->parent = node -> parent;

            if(node==node->parent->left){
            node->parent->left = node -> right;
            }

            else{
                node->parent->right = node->right;
            }
        }
        if(node->right == NULL){
            node->left->parent = node -> parent;
            
            if(node==node->parent->left){
            node->parent->left = node -> left;
            }
            else{
                node->parent->right = node->left;
            }
        }
    }

    //case 3, node has 2 children
    else{
        BNode *temp = Successor(node);
        Delete(Successor(node));


        temp -> parent = node -> parent;
        temp -> left = node -> left;
        // temp -> right  = node -> right;

        node->left->parent = temp;
        node-> right -> parent = temp;

        if(node==node->parent->left){
            node -> parent -> left = temp;
        }

        else{
            node -> parent -> right = temp;
        }

        

    }

    delete node;
}

/*------------------------------------------------------------------
finds a given element in the tree

Preconditions: pass in a last name.
Postconditions: returns true or false whether the name is in tree
------------------------------------------------------------------*/
bool BSTree::Search(string target){
    BNode *temp = root;

    while(temp!=NULL){
        if(temp->LastName==target){
            break;
        }

        if(target>temp->LastName){
            temp = temp->right;
        }

        if(target<temp->LastName){
            temp = temp->left;
        }
    }

    if(temp==NULL){
        return false;
    }

    if(temp->LastName==target){
        return true;
    }
}

/*------------------------------------------------------------------
finds a given element in the tree. will return null pointer if element
is not in tree

Preconditions: pass in a last name.
Postconditions: returns pointer to node searched for. may return null
if target is not in tree.
------------------------------------------------------------------*/
BNode* BSTree::BNodeSearch(string target){

    BNode *temp = root;

    while(temp!=NULL){
        if(temp->LastName==target){
            break;
        }

        if(target>temp->LastName){
            temp = temp->right;
        }

        if(target<temp->LastName){
            temp = temp->left;
        }
    }

    return temp;
}




/********************************************************************

----------------------Private Functions-----------------------------

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