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

void BSTree::AddPerson(sType LastName){

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