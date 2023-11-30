#pragma once


#include <iostream>
#include <vector>
#include "BallotLinkedList.h"

using namespace std;

class Candidate {

public:
		Candidate(); //default constructor
		~Candidate(); //default deconstructor
		Candidate(Candidate& candidate); //copy constructor
		Candidate(string first, string last, double ID); //manual constructor
		double GetCandidateID(); //retrieves Candidate ID
		double GetTotalVotes(); //retrieves the total number of votes collected
		string GetFName(); //retrieves a candidate's first name
		string GetLName(); //retrieves a candidate's last name
		BallotLinkedList GetBallotList(); //retrieves the list of ballots

		bool IDsEqual(Candidate candidate); //checks to make sure the candidate being input has the same ID
		void Print(); //displays the first name, last name, and ID of a candidate
		//void CheckForDuplicates(BallotLinkedList BallotList); //checks for duplicate ballots
		
		
		

		void AddVote();


		string FName=""; //stores the first name of a candidate
		string LName=""; //stores the last name of a candidate
		double CandidateID=0; //stores the ID of a candidate
		double TotalVotes=0; //stores the total number of votes collected
		BallotLinkedList BallotList = *(new BallotLinkedList()); //stores the list of ballots
		

};
