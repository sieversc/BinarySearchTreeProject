#ifndef _BSTree_H
#define _BSTree_H

/*------------------------------------------------------------------

------------------------------------------------------------------*/

#include <string>
#include <iostream>
using namespace std;

// Definition of what the BSTree can store.
typedef string sType;

// Definition of a BSTree node.
struct BNode {
    sType LastName;
    sType FirstName;
    BNode *left;
    BNode *right;
};


class BSTree {
    
  public:
    // Constructors & destructors
    /*--------------------------------------------------------------
    The default BSTree constructor provides the caller with an 
    	initially empty BSTree.  (IsEmpty == TRUE).
    --------------------------------------------------------------*/
    BSTree ();
    
    /*--------------------------------------------------------------
    The default BSTree destructor: deallocates all dynamically
    	allocated memory (i.e. BNodes).
    --------------------------------------------------------------*/
    ~BSTree ();
    
    /*--------------------------------------------------------------
    Adds a single person to the BSTree
    preconditions: none
    Postconditions: BSTreeSise++
    --------------------------------------------------------------*/
    AddPerson(sType LastName);   

								   
  private:
    // Object instance data
    BNode *root;
    int BSTreeSize;


    //helper functions

    void Clear(BNode *n);
};

#endif
