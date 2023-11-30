//Counter.h file

#pragma once
#include<iostream>
#include<string>
#include "CandidateLinkedList.h"
#include "BallotLinkedList.h"

using namespace std;

class Counter {

public:
	
	Counter();
	~Counter();

	CandidateLinkedList SenLinkedList;
	CandidateLinkedList GovLinkedList;
	CandidateLinkedList PresLinkedList;
	BallotLinkedList BallotList;

	//List of the ballots in the election
	BallotLinkedList GetBallotList();

	//List of each candidate type in the election
	CandidateLinkedList& GetSenCandidateList();
	CandidateLinkedList& GetGovCandidateList();
	CandidateLinkedList& GetPresCandidateList();

	

	//Goes through the list of ballots and adds a vote to a found candidate from the ballot votes
	void CountAllVotes();

	//overall print function / prints candidate information and their votes
	void PresidentPrint();
	void SenatorPrint();
	void GovernorPrint();
	void BallotListPrint();

};


