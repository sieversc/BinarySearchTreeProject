#include "SurvivorRegistry.h"
#include "BSTree.h"
#include "BNode.h"

#include <iostream>
#include <cstdlib>
#include <string>

/*------------------------------------------------------------------
The default SurvivorRegistry constructor.

Preconditions: none.
Postconditions: survivors BSTree and int count fields
------------------------------------------------------------------*/
SurvivorRegistry::SurvivorRegistry(){
	survivors = new BSTree();	//BSTree pointer that holds all nodes
	int count = 0;		//number of first names in BSTree
}

/*------------------------------------------------------------------
The default BSTree destructor.

Preconditions: none.
Postconditions: deletes all nodes in BSTree survivors 
------------------------------------------------------------------*/
SurvivorRegistry::~SurvivorRegistry(){

	survivors -> ~BSTree();
}

/*------------------------------------------------------------------
Adds a node to the bstree survivors if necessary. Always adds a 
first name to a node in survivors

Preconditions: pass in string. last name (lName) and first name (fName)
Postconditions: count++ and Size of BSTree may increase by 1.
------------------------------------------------------------------*/
void SurvivorRegistry::Add(string lName, string fName){

	if(!survivors->Search(lName)){
		survivors->Insert(survivors->root, lName);
	}

	BNode *temp = survivors->BSearch(lName, survivors->root);
	temp->AddFirstName(fName);

	count++;
}

/*------------------------------------------------------------------
Removes one person from the Tree. May delete a node if set of first 
names in that node == 0 after removal

Preconditions: pass in string. last name (lName) and first name (fName)
Postconditions: count-- and Size of BSTree may decrease by 1.
------------------------------------------------------------------*/
void SurvivorRegistry::Remove(string lName, string fName){

	BNode *temp = survivors->BSearch(lName, survivors->root);

	if(count==1){
		survivors->Clear(survivors->root);
	}
	if(temp==NULL){
		return;
	}

	else{
		temp->RemoveFirstName(fName);

		if(temp->count == 0){
			survivors->Delete(temp);

		}
	}
	count--;
}

/*------------------------------------------------------------------
Prints all the names of survivors in the tree:
	LastName		{	FirstName	}
prints error message if no survivors registered

Preconditions: none
Postconditions: none
------------------------------------------------------------------*/
void SurvivorRegistry::PrintSurvivors(){

	if(survivors->Count()>0){
		survivors -> PrintInOrder(survivors->root);
	}

	else{
		cout << "No Survivors have been registered" << endl;
	}
}


/*------------------------------------------------------------------
prints the number of survivors currently registered. accessor

Preconditions: none
Postconditions: none
------------------------------------------------------------------*/
void SurvivorRegistry::Count(){

	cout << "Number of Recorded Survivors: " << count << endl;
}


/*------------------------------------------------------------------
Searches for a Last Name in the tree. If found, prints all first names
registered. If not found, prints error message

Preconditions: none
Postconditions: none
------------------------------------------------------------------*/
void SurvivorRegistry::Search(string lname){
	BNode *temp = survivors->BSearch(lname, survivors->root);

	if(temp == NULL){
		cout << lname << " family has not been registered" << endl;
		return;
	}

	else{
		cout << "Members of the " << lname << " family include: ";
		temp->PrintFirstNames();
	}
}