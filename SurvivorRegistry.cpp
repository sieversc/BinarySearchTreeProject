#include "BSTree.h"
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

	BNode *temp = survivors->BNodeSearch(lName);
	temp->AddFirstName(fName);
	count++;
}

void SurvivorRegistry::Remove(string name){

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
	BNode *temp = survivors->BNodeSearch(lname);

	if(temp == NULL){
		cout << lname << " family has not been registered" << endl;
		return;
	}

	else{
		cout << "Members of the " << lname << " family include: ";
		temp->PrintFirstNames();
	}
}