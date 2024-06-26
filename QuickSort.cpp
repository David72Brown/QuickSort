#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	// Hard-code some values in here to sort. You could input them from the user via the console if you prefer.
	int x[] = { 12, 7, 13, 5, 90, 77, 1, 77, 12 };
	int NumVals = sizeof(x) / sizeof(x[0]);
	int i;
	cList MyList;

	// Create a linked list of the values.
	for (i = 0; i < NumVals; i++)
	{
		MyList.AddItem(x[i]);
	}

	// Show user the list of values we're going to sort.
	cout << "List before sorting:\n";
	MyList.Print();

	// Sort the list.
	MyList.Sort();

	// Display the sorted list.
	cout << "List after sorting :\n";
	MyList.Print();
}
