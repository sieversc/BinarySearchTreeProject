/********************
Written by Chris Sievers
********************/

#include <iostream>
#include "BSTree.h"

using namespace std;

int MAX = 5;

int main(){

	// SurvivorRegistry *reg = new SurvivorRegistry();

	// reg -> Add("john");

	// reg -> Add("apple");

	// reg -> Add("banana");

	// reg -> Add("mark");

	// reg -> Count();

	// reg -> PrintSurvivors();


	BSTree *list = new BSTree();

	list -> Insert(list->root, "c");

	list -> Insert(list->root, "a");

	list -> Insert(list->root, "b");

	list -> Insert(list->root, "e");

	list -> Insert(list->root, "d");

	list -> Insert(list->root, "f");

	list -> Insert(list->root, "g");



	//cout << list ->Search("c") << endl;

	// cout << list->BNodeSearch("z")->LastName << endl;

	list -> Delete(list->BNodeSearch("e"));

	list -> PrintInOrder(list->root);

	return(0);

}
