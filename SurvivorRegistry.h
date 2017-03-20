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


        int count;
		BSTree *survivors;

	    SurvivorRegistry();

	    ~SurvivorRegistry();

		void Add(string lName, string fName);
	    void Remove(string lName, string fName);
	    void PrintSurvivors();
        void Count();
        void Search(string lname);
        void Search (string lName, string fName);

    private:    
};

#endif