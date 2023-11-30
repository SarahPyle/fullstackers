#include "Candidate.h"
using namespace std;

Candidate::Candidate() {
	CandidateID = -1;
	FName = "";
	LName ="";
	TotalVotes = 0;
	BallotList = BallotLinkedList();
	//DistrictIDs = {0};
	//^ fills in the values of candidate with blank or null values
};

Candidate::~Candidate() {
};

Candidate::Candidate(Candidate& candidate) {
	CandidateID = candidate.GetCandidateID();
	FName = candidate.GetFName();
	LName = candidate.GetLName();
	TotalVotes = candidate.GetTotalVotes();
	BallotList = candidate.GetBallotList();
	//DistrictIDs = { 0 };
	//^ copies the values currently stored in the candidate class
};

Candidate::Candidate(string first, string last, double ID) {
	CandidateID = ID;
	FName = first;
	LName = last;
	TotalVotes = 0;
	BallotList = BallotLinkedList();
	//DistrictIDs = { 0 };
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
	cout << "Total Votes: " << TotalVotes << std::endl;
	//cout << "This Candidate is a part of these districts: ";
	
	//cout << "This candidate holds these ballots: " << endl;

	cout << "----------------" << endl;

	//^ displays the Candidate's ID, first name, and last name in order
	//perhaps add statements to display other information, like district
};







BallotLinkedList Candidate::GetBallotList() {
	return BallotList;
	//^ returns the list of ballots

}


void Candidate::AddVote()
{
	TotalVotes++;
}
