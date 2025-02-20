#include <assert.h>
#include <iostream>
#include "LinkedList.h"
using namespace std;

cItem::cItem(int InitialNum)
{
	x = InitialNum;
	// This new item isn't connected to any others to make a list yet, so its next and previous pointers are null for now.
	pNext = nullptr;
	pPrev = nullptr;
}

cItem::~cItem(void)
{
	// If this item is linked to a subsequent item in a list, we can't leave that item floating when this one is destructed,
	// so we destruct that one before we finish destructing this one.
	if (pNext)
	{
		delete pNext;
	}
}

int cItem::GetItemVal(void)
{
	return x;
}

void cItem::SetNext(cItem* pItem)
{
	pNext = pItem;
}

cItem* cItem::GetNext(void)
{
	return pNext;
}

void cItem::SetPrev(cItem* pItem)
{
	pPrev = pItem;
}

cItem* cItem::GetPrev(void)
{
	return pPrev;
}

cList::cList(void)
{
	// When we create a new list, it starts with no items in it so its first and last pointers are null.
	pFirstItem = nullptr;
	pLastItem = nullptr;
	NumItems = 0;
}

cList::~cList(void)
{
	// We can't leave the list items floating, we need to destruct them before destructing this list.
	// We only need to destruct the first one because in doing that, the cItem destructor will destruct
	// other items that it points to.
	if (pFirstItem)
	{
		delete pFirstItem;
	}
}

int cList::GetNumItems(void)
{
	return NumItems;
}

// There are 2 versions of the AddItem() method. This is called "overloading" a method. The compiler can tell which one the parent
// function wants to call because the parameter types are different. If the parent function calls AddItem() and passes in something
// of type int, the compiler knows it's trying to call the version shown below. If the parent function is passing in a cItem* then
// the compiler knows it's trying to call the other version shown lower down in this file.
void cList::AddItem(int NewVal)
{
	cItem* pNewItem;

	pNewItem = new cItem(NewVal);

	if (NumItems == 0)
	{
		// This is now the one and only item in this list.
		pFirstItem = pLastItem = pNewItem;
	}
	else
	{
		// Add the new item onto the end of the list.
		pLastItem->SetNext(pNewItem);
		pNewItem->SetPrev(pLastItem);
		pLastItem = pNewItem;
	}
	NumItems += 1;
}

// This is an overloaded method. See the explanation about the other definition of cList::AddItem() elsewhere in this file.
void cList::AddItem(cItem* pNewItem)
{
	if (NumItems == 0)
	{
		// This is now the one and only item in this list.
		pFirstItem = pNewItem;
		pLastItem = pNewItem;
	}
	else
	{
		// Add the new item onto the end of the list.
		pNewItem->SetPrev(pLastItem);
		pLastItem->SetNext(pNewItem);
		pLastItem = pNewItem;
	}
	NumItems += 1;
}

void cList::Sort(void)
{
	/*	Choose the first item in the list as the pivot, then take all the other items off the list and
		group into 2 new lists, one containing items less than the pivot, the other containing items
		more than the pivot. Then we recursively sort each of those 2 lists, and join everything together
		by concatenating the less-than-pivot list, the pivot item, and the more-than-pivot list.
	*/

	/*	Exercise: Write this quicksort function.
		To create new cList items, use e.g.:				cItem* pNewItem;
															pNewItem = new cItem(NewVal);
		To free up a cList item that is no longer needed:	delete pUnwantedItem;
	*/
}

void cList::Print(void)
{
	cItem* p;

	for (p = pFirstItem; p; p = p->GetNext())
	{
		cout << " " << p->GetItemVal();
	}
	cout << endl;
}
