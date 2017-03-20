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
    /*
        *LastName stores family name
        *FirstNames stores a list of first names in family
        *left is left child pointer
        *right is right child pointer
        *parent is parent pointer
        *count records the number of family members
    */
    string LastName;
    set<string> FirstNames;
    int count;

    BNode *left;
    BNode *right;
    BNode *parent;

    //constructor and destructor
    BNode();

    ~BNode();

    bool Search(string target);

    bool Search(string target, BNode *node);

    BNode* BSearch(string target, BNode *node);


/**************************************
------------------Accessors-------------
****************************************/

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


    /*------------------------------------------------------------------
    prints lastname

    Preconditions: nonde
    Postconditions: prints last name.
    ------------------------------------------------------------------*/    
    void PrintName();       


    /*------------------------------------------------------------------
    prints all first names in set

    Preconditions: nonde
    Postconditions: none
    ------------------------------------------------------------------*/    
    void PrintFirstNames();


/**************************************
------------------Mutators-------------
****************************************/

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
