//Function that uses binary search algorithm to find items
//within a list
template <class elemType>
int binarySearch(const elemType listName[], int listLength,
	const elemType& item)
{
	//Initialize first postion of the array to 0
	int firstPosition = 0;

	//Initialize last position of the array to arraylength - 1
	int lastPosition = listLength - 1;

	//Variable to store the middle postion of the array
	int middlePosition;

	//Initializes bool variable "found" to false by default
	bool found = false;

	//While loop used to find the element within the list
	while (firstPosition <= lastPosition && !found)
	{
		//Equation used to find the middle position of the list
		//and store it within the middlePosition variable
		middlePosition = (firstPosition + lastPosition) / 2;

		//If statement used to check if the element in the middle position
		//of the list is the item being searched for
		if (listName[middlePosition] == item)
			found = true;

		//If the first if statement is false, then this one is executed
		//instead to find the item below the middle list position
		else if (listName[middlePosition] > item)
			lastPosition = middlePosition - 1;

		//If the second if statement is false, then this one is used to
		//to find the item above the middle list position
		else
			firstPosition = middlePosition + 1;
	}
	//If statement to return a value if the inputed item was found
	if (found)
		return middlePosition;
	
	//-1 is to be returned if the inputed item was not found
	//-1 is used in main() to determine if item is not in the given list
	else
		return -1;
} //end binarySearch

//Function to find the position of the smallest element within a list
template <class elemType>
int minLocation(elemType listName[], int firstPosition, int lastPosition)
{
	//Initialized minIndex variable to the first position of the
	//list used for this function
	int minIndex = firstPosition;

	//For loop used to find location of the smallest element within the list
	for (int listLocation = firstPosition + 1; listLocation <= lastPosition; listLocation++)
		if (listName[listLocation] < listName[minIndex])
			minIndex = listLocation;

	return minIndex;
} //end minLocation

//Function used to swap elements within the given list
template <class elemType >
void swapIndex(elemType listName[], int firstPosition, int secondPosition)
{
	//Initialized listIndex variable to store the first element of the
	//given list
	elemType listIndex = listName[firstPosition];

	//Swaps the first given list element with the second
	listName[firstPosition] = listName[secondPosition];

	//Stores the list element within the temp variable
	listName[secondPosition] = listIndex;
} //end swapIndex


//Function used to sort the elements within the given list
template <class elemType>
void selectionSort(elemType listName[], int listLength)
{
	//Variable to store smallest element within the list
	int minIndex;

	//For loop used for sorting the given list using the minLocation and
	//swap function until the base condition for the loop is met
	for (int listLocation = 0; listLocation < listLength; listLocation++)
	{
		minIndex = minLocation(listName, listLocation, listLength - 1);
		swapIndex(listName, listLocation, minIndex);
	}
} //end selectionSort