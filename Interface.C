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


	BNode *location = new BNode();
	BSTree *temp = new BSTree();

	list->Find(list->root, "a", &location);
	temp-> Insert(temp->root, location->LastName);

	temp->PrintInOrder(temp->root);
	//cout << list -> Count() << endl;

	//list -> PrintInOrder(list->root);





/*
	sType response;

	BSTree *list = new BSTree();

	cin >> response;

	list -> Insert(list->root, response);
*/
	return(0);

}
