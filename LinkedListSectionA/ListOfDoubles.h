#pragma once
#include "DoubleListNode.h"

class ListOfDoubles // LinkedList
{
	friend class DoubleListNode;

public:
	ListOfDoubles();
	~ListOfDoubles();
	bool insert(double data);
	void displayList();
	double deleteMostRecent();
	double deleteDouble(int position);

private:
	DoubleListNode *head;
};
typedef ListOfDoubles *List;
