#include "BSTree.h"
#include <iostream>
#include <cstdlib>
#include <string>

SurvivorRegistry::SurvivorRegistry(){
	survivors = new BSTree();
}

SurvivorRegistry::~SurvivorRegistry(){
	survivors -> ~BSTree();
}


void SurvivorRegistry::Add(string LastName, string FirstName){
	if(!survivors->Search(LastName)){

		survivors->Insert(survivors->root, LastName);
	}
	BNode* temp = survivors->BNodeSearch(LastName);
	temp -> AddFirstName(FirstName);
}

void SurvivorRegistry::Remove(string name){

}

void SurvivorRegistry::PrintSurvivors(){
	survivors -> PrintInOrder(survivors->root);
}

void SurvivorRegistry::Count(){
	cout << survivors -> Count() << endl;
}