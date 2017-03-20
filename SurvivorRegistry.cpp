#include "SurvivorRegistry.h"
#include "BSTree.h"
#include "BNode.h"

#include <iostream>
#include <cstdlib>
#include <string>

SurvivorRegistry::SurvivorRegistry(){
	survivors = new BSTree();
	int count = 0;
}

SurvivorRegistry::~SurvivorRegistry(){

	survivors -> ~BSTree();
}


void SurvivorRegistry::Add(string lName, string fName){

	if(!survivors->Search(lName)){
		survivors->Insert(survivors->root, lName);
	}

	BNode *temp = survivors->BSearch(lName, survivors->root);
	temp->AddFirstName(fName);
	count++;
}

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

void SurvivorRegistry::PrintSurvivors(){

	if(survivors->Count()>0){
		survivors -> PrintInOrder(survivors->root);
	}

	else{
		cout << "No Survivors have been registered" << endl;
	}
}

void SurvivorRegistry::Count(){

	cout << "Number of Recorded Survivors: " << count << endl;
}

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