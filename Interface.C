/********************
Written by Chris Sievers
********************/

#include <iostream>
#include "BSTree.h"

using namespace std;

int MAX = 5;

int main(){

	BSTree *list = new BSTree();

	list -> Insert(list->root, "c");

	list -> Insert(list->root, "a");

	list -> Insert(list->root, "b");

	list -> Insert(list->root, "e");

	list -> Insert(list->root, "d");

	list -> Insert(list->root, "f");

	list -> Insert(list->root, "z");


	cout << list ->Search("a") << endl;

	return(0);

}
