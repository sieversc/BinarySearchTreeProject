#ifndef _SurvivorRegistry_H
#define _SurvivorRegistry_H

/*------------------------------------------------------------------
Written by Chris Sievers 
------------------------------------------------------------------*/

#include <string>
#include <iostream>
#include <set>
#include "BSTree.h"
#include "BNode.h"

using namespace std;

//SurvivorRegistry description
class SurvivorRegistry{

	public:


        int count;	//number of first names in BSTree
		BSTree *survivors;	//BSTree pointer that holds all nodes

	    /*------------------------------------------------------------------
	    The default SurvivorRegistry constructor.

	    Preconditions: none.
	    Postconditions: survivors BSTree and int count fields
	    ------------------------------------------------------------------*/		
	    SurvivorRegistry();

	    /*------------------------------------------------------------------
	    The default BSTree destructor.

	    Preconditions: none.
	    Postconditions: deletes all nodes in BSTree survivors 
	    ------------------------------------------------------------------*/
	    ~SurvivorRegistry();

	    /*------------------------------------------------------------------
	    Adds a node to the bstree survivors if necessary. Always adds a 
	    first name to a node in survivors

	    Preconditions: pass in string. last name (lName) and first name (fName)
	    Postconditions: count++ and Size of BSTree may increase by 1.
	    ------------------------------------------------------------------*/
		void Add(string lName, string fName);

		/*------------------------------------------------------------------
	    Removes one person from the Tree. May delete a node if set of first 
	    names in that node == 0 after removal

	    Preconditions: pass in string. last name (lName) and first name (fName)
	    Postconditions: count-- and Size of BSTree may decrease by 1.
	    ------------------------------------------------------------------*/
	    void Remove(string lName, string fName);

	    /*------------------------------------------------------------------
	    Prints all the names of survivors in the tree:
	    	LastName		{	FirstName	}
		prints error message if no survivors registered

	    Preconditions: none
	    Postconditions: none
	    ------------------------------------------------------------------*/
	    void PrintSurvivors();


	    /*------------------------------------------------------------------
	    prints the number of survivors currently registered. accessor
		
	    Preconditions: none
	    Postconditions: none
	    ------------------------------------------------------------------*/
        void Count();

	    /*------------------------------------------------------------------
	    Searches for a Last Name in the tree. If found, prints all first names
	    registered. If not found, prints error message
		
	    Preconditions: none
	    Postconditions: none
	    ------------------------------------------------------------------*/
        void Search(string lname);

    private:    
};

#endif