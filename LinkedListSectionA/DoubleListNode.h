#pragma once
#include "ListOfDoubles.h"

class DoubleListNode // ListNode
{
	friend class ListOfDoubles;

public:
	DoubleListNode(double data);

private:
	double theData;
	DoubleListNode *next;
};
typedef DoubleListNode *ListNodePtr;
