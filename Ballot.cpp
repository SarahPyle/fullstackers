#include "Ballot.h"
#include <iostream>
#include <string>
using namespace std;

Ballot::Ballot() {
	FilledIn = false;
	BallotID = -1;
	DistrictID = -1;
	GovernorVote = -1;
	SenatorVote = -1;
	PresidentialVote = -1;
}
Ballot::~Ballot() {

}
Ballot::Ballot(double BallotID1, double DistrictID1, double GovernorVote1, double SenatorVote1, double PresidentialVote1, bool FilledIn1) {
	BallotID = BallotID1;
	DistrictID = DistrictID1;
	GovernorVote = GovernorVote1;
	SenatorVote = SenatorVote1;
	PresidentialVote = PresidentialVote1;
	FilledIn = FilledIn1;
}
Ballot::Ballot(Ballot &ballot)
{
	BallotID = ballot.GetBallotID();
	DistrictID = ballot.GetDistrictID();
	GovernorVote = ballot.GetGovVoteCandidate();
	SenatorVote = ballot.GetSenVoteCandidate();
	PresidentialVote = ballot.GetPresVoteCandidate();
	FilledIn = ballot.GetFilledIn();
}

bool Ballot::IDsEqual(Ballot ballot)
{
	return (ballot.GetBallotID() == BallotID);
}

void Ballot::VerifyFilledIn() {
	if (BallotID == -1) { FilledIn = false; }
	if (DistrictID == -1) { FilledIn = false; }
	if (SenatorVote == -1) { FilledIn = false; }
	if (GovernorVote == -1) { FilledIn = false; }
	if (PresidentialVote == -1) { FilledIn = false; }
}

void Ballot::Print() {
	cout << "-----------------" << endl;
	cout << "BallotID: " << BallotID << endl;
	cout << "DistrictID: " << DistrictID << endl;
	cout << "Governor Vote: " << GovernorVote << endl;
	cout << "Senator Vote: " << SenatorVote << endl;
	cout << "Presidential Vote: " << PresidentialVote << endl;
	cout << "Ballot Filled In: " << FilledIn << endl;
	cout << "------------------" << endl;
}
