/********************
Written by Chris Sievers
********************/

#include <iostream>
#include "BSTree.h"

using namespace std;

int MAX = 5;

int main(){

	BSTree *list = new BSTree();

	list -> Insert(list->root, "n");

	list -> Insert(list->root, "f");

	list -> Insert(list->root, "t");

	list -> Insert(list->root, "a");

	list -> Insert(list->root, "h");

	list -> Insert(list->root, "p");

	list -> Insert(list->root, "z");



	cout << list -> Count() << endl;

	list -> PrintInOrder(list->root);





/*
	sType response;

	BSTree *list = new BSTree();

	cin >> response;

	list -> Insert(list->root, response);
*/
	return(0);

}
