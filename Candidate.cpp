#include "Candidate.h"
using namespace std;

Candidate::Candidate() {
	CandidateID = -1;
	FName = "";
	LName ="";
	TotalVotes = 0;
	BallotList = BallotLinkedList();
	//^ fills in the values of candidate with blank or null values
};

Candidate::Candidate(Candidate& candidate) {
	CandidateID = candidate.GetCandidateID();
	FName = candidate.GetFName();
	LName = candidate.GetLName();
	TotalVotes = candidate.GetTotalVotes();
	BallotList = candidate.GetBallotList();
	//^ copies the values currently stored in the candidate class
};

Candidate::Candidate(string first, string last, double ID, double votes) {
	CandidateID = ID;
	FName = first;
	LName = last;
	TotalVotes = votes;
	BallotList = BallotLinkedList();
	//^ allows manual input of values for Candidate (not manually input through keyboard, instead values are passed when the constructor is called.
	// see Tabulation.cpp for an example.)
};

double Candidate::GetCandidateID() {
	return CandidateID;
	//^ returns the value currently stored in CandidateID
};

double Candidate::GetTotalVotes() {
	return TotalVotes;
	//^ returns the value currently stored in TotalVotes
};

string Candidate::GetFName() {
	return FName;
	//^ returns the value currently stored in FName
};

string Candidate::GetLName() {
	return LName;
	//^ returns the value currently stored in LName
};

bool Candidate::IDsEqual(Candidate candidate)
{
	return (candidate.GetCandidateID() == CandidateID);
	//^ returns true or false depending on whether the current value in CandidateID is the same
};

void Candidate::Print() {
	cout << "----------------" << endl;
	cout << "Candidate " << CandidateID << ": " << std::endl;
	cout << "First Name: " << FName << std::endl;
	cout << "Last Name: " << LName << std::endl;
	cout << "----------------" << endl;
	//^ displays the Candidate's ID, first name, and last name in order
	//perhaps add statements to display other information, like district
};

void Candidate::CheckForDuplicates(BallotLinkedList BallotList) {
	//under construction
	//have an outer for loop that goes through the full list of ballots, stopping
	//at each one, and in another loop going through the rest of the list comparing
	//the current ballot in the outer loop with the rest of them.
	//(also, what should this method do anything if a duplicate is found?)
};

void Candidate::CountVotes() {
	double i = 0; //creates a local variable to keep track of the total votes counted in this method
	BallotLinkedList list = BallotList.Copy(); //copies the list of ballots so the original being used isn't changed, and stores it in a local variable
	while(!list.Empty()) { //loops through the copied list one at a time until its empty
		list.RemoveFront(); //removes the front item in the list, this is why we didn't just edit the original list.
		i++; //increments our local total by 1
	}
	TotalVotes = i; //sets the value of TotalVotes to the value stored in our local variable, which should be accurate to the total number of votes
	
};

void Candidate::AddBallot(Ballot ballot) {
	BallotList.AddItemToFront(ballot);
	//^ adds a new ballot to the front of the list, using the values stored in the ballot parameter passed to the method
};

void Candidate::RemoveBallot(Ballot ballot) {
	BallotList.RemoveItem(ballot);
	//^ removes the ballot stored in the list if its values correlate to the values passed in the ballot parameter
	//may want to include an exception/catch algorithm that will display an error when the ballot passed does not exist in the list
};

BallotLinkedList Candidate::GetBallotList() {
	return BallotList;
	//^ returns the list of ballots

}
