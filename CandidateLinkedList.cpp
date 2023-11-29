
#pragma once
#include "CandidateLinkedList.h"
#include "CandidateNode.h"
#include "Candidate.h"
#include <string>

CandidateLinkedList::CandidateLinkedList()
{
	head = NULL;
	tail = NULL;

}

CandidateLinkedList::~CandidateLinkedList()
{
	while (!Empty())
	{
		RemoveFront();
	}
}

void CandidateLinkedList::RemoveFront()
{
	if (!Empty())
	{
		CandidateNode* temp = head;
		head = temp->next;
		delete temp;
	}
}



void CandidateLinkedList::AddItemToFront(Candidate& candidate)
{
	CandidateNode* temp = new CandidateNode;
	temp->candidate = candidate;
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

Candidate& CandidateLinkedList::ReturnFrontItem()
{
	return head->candidate;
}

void CandidateLinkedList::RemoveItem(Candidate& candidate)
{
	if (!Empty())
	{
		
		CandidateNode* temp = head;
		CandidateNode* prev = head;
		CandidateNode* next = head;
		while (temp != NULL)
		{
			
			if (temp->candidate.IDsEqual(candidate))
			{
				next = temp->next;
				prev = temp->prev;
				
				if (prev != NULL) //If there is an item before this in the list
				{
					prev->next = next;
				}
				else //If this candidate is the first in the list the head will be the next item
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

Candidate& CandidateLinkedList::FindCandidate(double candidateID)
{
	if (!Empty())
	{
		CandidateNode* temp = head;
		while (temp != NULL)
		{
			if (temp->candidate.GetCandidateID() == candidateID)
			{

				return temp->candidate;
			}
			temp = temp->next;
		}
	}
	return *(new Candidate());
}

CandidateLinkedList CandidateLinkedList::Copy()
{
	CandidateLinkedList list = CandidateLinkedList();
	CandidateNode* temp = head;
	while (temp != NULL)
	{
		list.AddItemToFront(temp->candidate);
		//list.ReturnFrontItem().BallotList = temp->candidate.BallotList.Copy();
		temp = temp->next;
	}
	return list;

}


bool CandidateLinkedList::Empty()
{
	return(head == NULL);
}
