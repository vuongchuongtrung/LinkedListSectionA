#include "ListOfDoubles.h"
#include <string>
#include <iostream>
using namespace std;

ListOfDoubles::ListOfDoubles()
	:head(NULL)
{
	cout << "This linked list is similar to Stack: LIFO (Last In First Out)" << endl;
}

ListOfDoubles::~ListOfDoubles()
{
	ListNodePtr tempPtr;
	while (head)
	{
		tempPtr = head;
		head = head->next;
		delete tempPtr;
	}
}

// perform insert at the front/start of the list
bool ListOfDoubles::insert(double data)
{
	DoubleListNode* newNode = new DoubleListNode(data);
	if (!newNode)
	{
		return false; // failure
	}
	newNode->next = head;
	head = newNode;
	return true; // success
}

void ListOfDoubles::displayList()
{
	ListNodePtr tempPtr = head;
	if (!tempPtr)
	{
		cout << "The list is empty, nothing to be displayed!\n" << endl;
	}
	else
	{
		while (tempPtr != NULL)
		{
			cout << tempPtr->theData << endl;
			tempPtr = tempPtr->next;
		}
	}
}

double ListOfDoubles::deleteMostRecent()
{
	double data = 0;
	if (!head) // empty list
	{
		cout << "Delete cannot be done with an empty list!\n" << endl;
	}
	else // because insert at the front/start => most recent will be at front/start
	{
		ListNodePtr tempPtr = head;
		head = head->next;
		data = tempPtr->theData;
		cout << "\nDeleting most recent! Data = " << data << endl;
		delete tempPtr;
	}	
	return data;
}

double ListOfDoubles::deleteDouble(int position)
{	
	double data = 0;

	if (position >= 0) // node must start from 0 
	{
		ListNodePtr tempPtr = head;

		if (!tempPtr) // empty list
		{
			cout << "Delete cannot be done with an empty list!\n" << endl;
			data = 0;
		}

		else if (position == 0) // delete head
		{
			head = tempPtr->next;
			data = tempPtr->theData;
			cout << "\nDeleting node position " << position << "! Data = " << data << endl;
			//free(tempPtr);
			delete tempPtr;
		}
		else
		{
			// traverse to the position for deleting
			for (int i = 0; i < position - 1 && tempPtr != NULL; i++)
			{
				tempPtr = tempPtr->next;
			}

			if (tempPtr->next == NULL)
			{
				cout << "\nDeleting node position " << position << "! Data = NULL ==> Cannot be done!" << endl;
				data = 0;
			}
			else
			{
				ListNodePtr nodeToDelete = tempPtr->next;
				data = nodeToDelete->theData;
				tempPtr->next = nodeToDelete->next;
				cout << "\nDeleting node position " << position << "! Data = " << data << endl;
				//free(nodeToDelete);
				delete nodeToDelete;
			}
		}
	}
	else
	{
		cout << "\nPosition cannot be a negative value!" << endl;
	}
	return data;
}
