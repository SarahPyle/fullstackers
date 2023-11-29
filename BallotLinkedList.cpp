#pragma once
#include "BallotLinkedList.h"
#include <string>

BallotLinkedList::BallotLinkedList()
{
	head = NULL;
	tail = NULL;
}



BallotLinkedList::~BallotLinkedList()
{
	while (!Empty())
	{
		RemoveFront();
	}
}


void BallotLinkedList::RemoveFront()
{
	if (!Empty())
	{
		BallotNode* temp = head;
		head = temp->next;
		delete temp;
	}

}

void BallotLinkedList::AddItemToFront(Ballot& ballot)
{
	BallotNode* temp = new BallotNode;
	temp->ballot = ballot;
	temp->next = head;
	temp->prev = NULL;

	if (head == NULL)
	{
		tail = temp;
	}
	else
	{
		head->prev = temp;
	}

	head = temp;
}


void BallotLinkedList::AddItemToBack(Ballot& ballot)
{
	BallotNode* temp = new BallotNode;


	temp->ballot = ballot;   //object added to linked list

	temp->next = NULL; //end of list is now NULL
	temp->prev = tail; //current tail is now prev of our new node

	if (tail == NULL)
	{
		head = temp;
	}
	else
	{
		tail->next = temp;
	}

	tail = temp;
}

Ballot& BallotLinkedList::ReturnFrontItem()
{
	return head->ballot;
}

void BallotLinkedList::RemoveItem(Ballot& ballot)
{
	if (!Empty())
	{

		BallotNode* temp = head;
		BallotNode* prev = head;
		BallotNode* next = head;
		while (temp != NULL)
		{

			if (temp->ballot.IDsEqual(ballot))
			{
				next = temp->next;
				prev = temp->prev;

				if (prev != NULL) //If there is an item before this in the list
				{
					prev->next = next;
				}
				else //If this ballot is the first in the list the head will be the next item
				{
					head = next;
				}

				if (next != NULL) //If this is not the last item in list it changes the previous on the next item to the item before this one
				{
					next->prev = prev;
				}
				else //If this item is the last in the list then the tail will be the item before this
				{
					tail = prev;
				}

				//delete temp;
			}
			temp = temp->next;

		}

	}
}


Ballot& BallotLinkedList::FindBallot(double ballotID)
{
	if (!Empty())
	{
		BallotNode* temp = head;
		while (temp != NULL)
		{
			if (temp->ballot.GetBallotID() == ballotID)
			{

				return temp->ballot;
			}
			temp = temp->next;
		}
	}
	return *(new Ballot());
}



BallotLinkedList BallotLinkedList::Copy()
{
	BallotLinkedList list = BallotLinkedList();
	BallotNode* temp = head;
	while (temp != NULL)
	{
		list.AddItemToFront(temp->ballot);
		temp = temp->next;
	}
	return list;
}

bool BallotLinkedList::Empty()
{
	return (head == NULL);
}
