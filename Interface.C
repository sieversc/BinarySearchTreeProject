/********************
Written by Chris Sievers
********************/

#include <fstream>
#include <iostream>
#include "BSTree.h"
#include "BNode.h"
#include "SurvivorRegistry.h"

using namespace std;

enum EntryCode {ADD, REMOVE, PRINT, COUNT, SEARCH, QUIT};

int main(){
	int response;
	string fName;
	string lName;

	SurvivorRegistry *reg = new SurvivorRegistry();

	//-----------------file IO ---------------------

		// ifstream myInputFile;
		// myInputFile.open("names.txt");

		// myInputFile >> lName >> fName;
		// while(!myInputFile.eof()){
		// 	reg -> Add(lName, fName);
		// 	myInputFile >> lName >> fName;
		// }

		// myInputFile.close();


	cout << "\nEnter Action:" << endl; 
	cout << " 0: Add\n 1: Remove\n 2: Print\n 3: Count\n 4: Search\n 5: Quit";
	cout << endl << ">";
	cin >> response;
	cout << endl;

	while(response != QUIT){
		switch(response){
			
			case ADD:
				cout << "Enter Name:" << endl;

				cout << "First Name >"; 
				cin >> fName;

				cout << "Last Name >";
				cin >> lName;
				reg->Add(lName, fName);

				break;
			
			case REMOVE:
				cout << "Enter Name: " << endl;

				cout << "First Name >";
				cin >> fName;

				cout << "Last Name >";
				cin >> lName;

				reg->Remove(lName, fName);

				break;

			case PRINT:
				reg->PrintSurvivors();

				break;

			case COUNT:
				reg->Count();

				break;

			case SEARCH:
				cout << "Enter Name: " << endl;

				cout << "Last Name >";
				cin >> lName;

				reg->Search(lName);

				break;
		}

	cout << "\nEnter Action:" << endl; 
	cout << " 0: Add\n 1: Remove\n 2: Print\n 3: Count\n 4: Search\n 5: Quit";
	cout << endl << ">";
	cin >> response;
	cout << endl;

	}


	return(0);

}
