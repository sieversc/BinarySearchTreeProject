#ifndef _BSTree_H
#define _BSTree_H

/*------------------------------------------------------------------
Written by Chris Sievers 
------------------------------------------------------------------*/

#include "BNode.h"
#include <string>
#include <iostream>
#include <set>
using namespace std;

// Definition of a BSTree node.



class BSTree {
    
  public:

    BNode *root;


    // Constructors & destructors

    /*--------------------------------------------------------------
    The default BSTree constructor provides the caller with an 
    	initially empty BSTree.
    --------------------------------------------------------------*/
    BSTree ();
    
    /*--------------------------------------------------------------
    The default BSTree destructor: deallocates all dynamically
    	allocated memory (i.e. BNodes).
    --------------------------------------------------------------*/
    ~BSTree ();


    //--------------------------accessor methods------------------------------


        /*------------------------------------------------------------------
        Prints the BSTree in order. least to greatest. calls printfirstnames() in 
        BNode class

        Preconditions: pass in the root node
        Postconditions: prints the first and last names of each node in the tree
        ------------------------------------------------------------------*/
        void PrintInOrder(BNode *node);


        /*------------------------------------------------------------------
        Returns an integer equal to the number of nodes in the tree

        Preconditions: none.
        Postconditions: returns an integer that represents the number of nodes
        in the tree
        ------------------------------------------------------------------*/
        int Count();

    /*------------------------------------------------------------------
    searches the tree for any last name

    Preconditions: pass in last name
    Postconditions: returns true or false whether last name is in tree
    ------------------------------------------------------------------*/
    bool Search(string target);


    /*------------------------------------------------------------------
    finds a given element in the tree. 
    
    warning: 
        will return null pointer if element
        is not in tree

    Preconditions: pass in a last name and root of tree.
    Postconditions: returns pointer to node searched for. may return null
    if target is not in tree.
    ------------------------------------------------------------------*/
    BNode* BSearch(string target, BNode *node);



    /*------------------------------------------------------------------
    Non-Lazy delete    -   based on 3 base cases
        1. node passed in is a leaf
        2. node passed in has only one child
        3. node passed in has 2 children
    Preconditions: pass in node to be deleted.
    Postconditions: node is deleted. BSTree structure is preserved in all
    3 cases above. 
    ------------------------------------------------------------------*/
    void Delete(BNode *node);

    /*--------------------------------------------------------------
    Adds a single node to the BSTree
    preconditions: pass in the root of the tree and the name to be added
    Postconditions: BSTreeSise++
    --------------------------------------------------------------*/
    void Insert(BNode *node, string name);   
    
    /*------------------------------------------------------------------
    clears the tree of all nodes

    Preconditions: none.
    Postconditions: deletes all nodes in tree. BSTreeSize = 0
    ------------------------------------------------------------------*/
    void Clear(BNode *n);							   
  

  private:
    // Object instance data

    int BSTreeSize;


    //---------------helper functions---------------------
    
        /*------------------------------------------------------------------
        pass in a node and this function will find the smallest node greater than it

        Preconditions: pass in node
        Postconditions: returns BNode pointer
        ------------------------------------------------------------------*/
        BNode* Successor(BNode *node);

        /*------------------------------------------------------------------
        pass in a node and this function will find the greatest node smaller than it

        Preconditions: pass in node pointer
        Postconditions: returns node pointer
        ------------------------------------------------------------------*/
        BNode* Predecessor(BNode *node);

        /*------------------------------------------------------------------
        pass in a node and this function will find the greatest node in the tree

        Preconditions: pass in node pointer
        Postconditions: returns node pointer
        ------------------------------------------------------------------*/
        BNode* FindMax(BNode *node);

        /*------------------------------------------------------------------
        pass in a node and this function will find the smallest node in the tree

        Preconditions: pass in node pointer
        Postconditions: returns node pointer
        ------------------------------------------------------------------*/
        BNode* FindMin(BNode *node);
};


#endif
