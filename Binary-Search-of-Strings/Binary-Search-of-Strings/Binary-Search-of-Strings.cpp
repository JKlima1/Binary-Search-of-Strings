#include <iostream>
#include <string>
#include "binarySearch.h"

using namespace std;

int main()
{
	//Predefined string array
	string cheeseList[] = { "mozzarella", "feta", "cheddar", "brie", "provolone",
	"parmigian", "swiss", "ricotta", "gouda", "blue", "american"};

	//Initialized searchItem variable as blank string
	string searchItem = "";

	//Variables to store integers listSize and listPosition
	int listPosition;

	//Equation used to find the size of the cheeseList array by
	//using the "sizeof" function, then stores the result into
	//the listSize variable
	int listSize = sizeof(cheeseList) / sizeof(cheeseList[0]);

	//Functiond used for selection sorting
	selectionSort(cheeseList, listSize);

	//Default terminal prompt
	cout << "Binary Search Program" << endl;
	cout << "*****************************" << endl << endl;
	cout << "Common types of cheese" << endl << endl;
	cout << "*****************************" << endl;
	cout << "Enter [exit] to exit program" << endl;
	cout << "*****************************" << endl << endl;

	//repeating terminal prompt achieved by using a while loop
	//"exit" is the keyword to end the loop
	while (searchItem != "exit")
	{
		//Repeating terminal prompt
		cout << "Enter the item to be searched: ";

		//Store prompt entry into searchItem variable
		cin >> searchItem;
		cout << endl;

		//Stores the result of the binarySearch function into the
		//listPosition variable
		listPosition = binarySearch(cheeseList, listSize, searchItem);

		//If statement that outputs wheter binarySearch was able to find the
		//item entry within the list
		if (listPosition != -1)
			cout << "[Found] " << searchItem << " is in cheeseList"
			<< endl << endl << endl;
		else
			cout << "[Not Found] " << searchItem
			<< " is not in cheeseList " << endl << endl << endl;
	}
	return 0;
}