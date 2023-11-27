#pragma once
class Ballot
{
public:
	double BallotID;
	double DistrictID;
	double GovernorVote;//Stores CandidateID
	double SenatorVote;// Stores CandiateID
	double PresidentialVote; // Stores CandidateID
	bool FilledIn;

	Ballot();//Constructors
	Ballot(double BallotID1, double DistrictID1, double GovernorVote1, double SenatorVote1, double PresidentialVote1, bool FilledIn1);
	Ballot(Ballot &ballot);
	~Ballot();//Destructor

	bool IDsEqual(Ballot ballot);
	double GetBallotID() { return BallotID; } // Fetches the BallotId
	double GetDistrictID() { return DistrictID; } //Fetches and returns DistrictID
	double GetGovVoteCandidate() { return GovernorVote; } //Fetches and returns CandidateID
	double GetSenVoteCandidate() { return SenatorVote; }//Fetches and returns CandidateID
	double GetPresVoteCandidate() { return PresidentialVote; }//Fetches and returns CandidateID
	bool GetFilledIn() { return FilledIn; }// Checks if Ballot is filled in.
	void VerifyFilledIn();// Checks if Ballot is filled in.
	void Print();//Prints the Ballot Information




};


