#pragma once

class cItem
{
	public:
		cItem(int InitialNum);
		~cItem(void);
		int GetItemVal(void);
		void SetNext(cItem* pItem);
		cItem* GetNext(void);
		void SetPrev(cItem* pItem);
		cItem* GetPrev(void);
	private:
		int x;
		cItem* pNext;
		cItem* pPrev;
};

class cList
{
	public:
		cList(void);
		~cList(void);
		int GetNumItems(void);
		void AddItem(int NewVal);		// This method...
		void AddItem(cItem* pNewItem);	// ... and this method demonstrate "overloading" of methods. Same name, different parameters.
		void Sort(void);
		void Print(void);
	private:
		cItem* pFirstItem;
		cItem* pLastItem;
		int NumItems;
};
