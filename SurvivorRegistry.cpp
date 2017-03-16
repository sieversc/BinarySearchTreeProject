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


void SurvivorRegistry::Add(string name){
	survivors->Insert(survivors->root, name);
}

void SurvivorRegistry::Remove(string name){

}

void SurvivorRegistry::PrintSurvivors(){
	survivors -> PrintInOrder(survivors->root);
}

void SurvivorRegistry::Count(){
	cout << survivors -> Count() << endl;
}