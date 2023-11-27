#pragma once

#include "BallotNode.h"

class BallotLinkedList
{
public:
	BallotLinkedList();
	
	~BallotLinkedList();

	void RemoveFront(); //Removes the first item in the linked list
	void AddItemToFront(Ballot& ballot); //adds a ballot to the front of the linked list
	void AddItemToBack(Ballot& ballot);
	Ballot& ReturnFrontItem(); //Can be used to loop through list. Basically just look at the Front of ballot list then remove the front ballot until it returns NULL. This would delete the list so it is adviced to make a copy

	void RemoveItem(Ballot& ballot); //removes a specific ballot in the linked list by inputing a ballot

	Ballot& FindBallot(double ballotID); //Finds a ballot based on the ballotID



	
	BallotLinkedList Copy(); //makes a duplicated of a linked list *Won't effect the original list when editing the copy
	
	bool Empty(); //returns true or false depending on if the first item in the list is NULL


private:
	BallotNode* head;
	BallotNode* tail;
};

