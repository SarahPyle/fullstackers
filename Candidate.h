#pragma once


#include <iostream>
#include<string>
#include "BallotLinkedList.h"

using namespace std;

class Candidate {

public:
		Candidate(); //default constructor
		Candidate(Candidate& candidate); //copy constructor
		Candidate(string first, string last, double ID, double votes); //manual constructor
		double GetCandidateID(); //retrieves Candidate ID
		double GetTotalVotes(); //retrieves the total number of votes collected
		string GetFName(); //retrieves a candidate's first name
		string GetLName(); //retrieves a candidate's last name
		bool Equals(Candidate candidate);
		void Print();
		void CheckForDuplicates(BallotLinkedList BallotList);
		void CountVotes();
		BallotLinkedList GetBallotList();
		void AddBallot(Ballot ballot);
		void RemoveBallot(Ballot ballot);

		string FName;
		string LName;
		double CandidateID;
		double TotalVotes;
		BallotLinkedList BallotList;
		// BallotLinkedList CandBallotList;

};
