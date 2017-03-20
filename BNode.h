#ifndef _BNode_H
#define _BNode_H

/*------------------------------------------------------------------
Written by Chris Sievers 
------------------------------------------------------------------*/

#include <string>
#include <iostream>
#include <set>
//#include "BSTree.h"
using namespace std;

class BNode {
   
    public:
   
    string LastName;    //stores family name
    set<string> FirstNames; //stores a list of first names in family
    int count;          //records the number of family members

    BNode *left;    //left child
    BNode *right;   //right child
    BNode *parent;  //parent pointer

/*------------------------------------------------------------------
The default BNode constructor.

Preconditions: none.
Postconditions: initiates count variable
------------------------------------------------------------------*/
    BNode();



/*------------------------------------------------------------------
The default BNode destructor.

Preconditions: none.
Postconditions: none
------------------------------------------------------------------*/
    ~BNode();

//---------------------Searches--------------------

    /*------------------------------------------------------------------
    Search method looks through entire tree for a given name. returns
    true if found, false if not

    Preconditions: pass in last name string.
    Postconditions: returns boolean
    ------------------------------------------------------------------*/
    bool Search(string target);

    /*------------------------------------------------------------------
    Search method looks through entire tree for a given name. returns
    true if found, false if not

    Preconditions: pass in last name string and root of tree.
    Postconditions: pointer to BNode of target. may return NULL
    ------------------------------------------------------------------*/
    BNode* BSearch(string target, BNode *node);


//---------------------Accessors--------------------


    /*------------------------------------------------------------------
    accessor returns the last name field in BNode class

    Preconditions: nonde
    Postconditions: returns string lastname
    ------------------------------------------------------------------*/       
    string GetLastName();

    /*------------------------------------------------------------------
    accessor returns the first name field in BNode class

    Preconditions: nonde
    Postconditions: returns set first name
    ------------------------------------------------------------------*/
    set<string> GetFirstName();

//--------------------Print Methods--------------------

    /*------------------------------------------------------------------
    prints Last name of a given node1

    Preconditions: none
    Postconditions: none
    ------------------------------------------------------------------*/  
    void PrintName();


    /*------------------------------------------------------------------
    prints all first names in set

    Preconditions: nonde
    Postconditions: none
    ------------------------------------------------------------------*/    
    void PrintFirstNames();


//---------------------Mutators--------------------

    /*------------------------------------------------------------------
    mutator changes last name field in BNode class

    Preconditions: pass in desired name
    Postconditions: new last name
    ------------------------------------------------------------------*/
    void SetLastName(string name);


    /*------------------------------------------------------------------
    mutator replaces first name field

    Preconditions: pass in set of strings
    Postconditions: none
    ------------------------------------------------------------------*/
    void SetFirstName(set<string> names);

    /*------------------------------------------------------------------
    mutator adds a name to the first name set in BNode

    Preconditions: pass in string
    Postconditions: length of first name set ++
    ------------------------------------------------------------------*/
    void AddFirstName(string name);

    /*------------------------------------------------------------------
    mutator removes a name from the first name set in BNode class

    Preconditions: pass in name to be removed
    Postconditions: length of first name set --
    ------------------------------------------------------------------*/
    void RemoveFirstName(string name);
    

    private:
};


#endif
