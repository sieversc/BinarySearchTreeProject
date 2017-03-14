#ifndef _BSTree_H
#define _BSTree_H

/*------------------------------------------------------------------
Written by Chris Sievers 
------------------------------------------------------------------*/

#include <string>
#include <iostream>
using namespace std;

// Definition of what the BSTree can store.
typedef string sType;

// Definition of a BSTree node.
class BNode {
    public:
        sType LastName;
        sType FirstName;
        BNode *left;
        BNode *right;

    private:
};


class BSTree {
    
  public:

    BNode *root;
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
    void Insert(BNode *node, sType name);   

								   
  private:
    // Object instance data

    int BSTreeSize;


    //helper functions

    void Clear(BNode *n);
};

#endif
