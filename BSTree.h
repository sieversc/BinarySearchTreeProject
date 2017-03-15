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

        BNode();

        ~BNode();

        bool Search(sType target);


    /**************************************
    ------------------Accessors-------------
    ****************************************/
        sType GetLastName();    //returns lastName field

        void PrintName();       //prints lastname

    private:
};

//SurvivorRegistry description
class SurvivorRegistry{

    void Add(sType Name);
    void Remove(sType Name);
    void PrintSurvivors();
    

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





//--------------------------accessor methods------------------------------


    /*------------------------------------------------------------------
    Prints the BSTree in order. least to greatest

    Preconditions: pass in the root node
    Postconditions: prints the last names of each node in the tree
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
    bool Search(sType value);










    /*------------------------------------------------------------------
    Non-Lazy deletes    -   based on 3 base cases
        1. node passed in is a leaf
        2. node passed in has only one child
        3. node passed in has 2 children
    Preconditions: none.
    Postconditions: none
    ------------------------------------------------------------------*/
    void Delete(BNode *root, sType target);

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


    /*------------------------------------------------------------------
    clears the tree of all nodes

    Preconditions: none.
    Postconditions: deletes all nodes in tree. BSTreeSize = 0
    ------------------------------------------------------------------*/
    void Clear(BNode *n);

    /*------------------------------------------------------------------
    pass in a node and this function will find the smallest node greater than it

    Preconditions: none.
    Postconditions: none
    ------------------------------------------------------------------*/
    BNode* Successor(BNode *node);

    BNode* Predecessor(BNode *node);

    BNode* FindMax(BNode *node);

    BNode* FindMin(BNode *node);


};

#endif
