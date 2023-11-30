//Counter.cpp - implementing the Counter.h file

#include <iostream>
#include "Counter.h"
#include "BallotLinkedList.h"
#include "CandidateLinkedList.h"

using namespace std;

//default constructor
Counter::Counter() {
    SenLinkedList = *(new CandidateLinkedList());
    GovLinkedList = *(new CandidateLinkedList());
    PresLinkedList = *(new CandidateLinkedList());
    BallotList = *(new BallotLinkedList());
    //ask Sky when she makes the reader classes
    /*Sky here, this will instantiate a FileReader and that file reader will make Candidate
    and Ballot objects and assign them to the counter's appropriate linkedList.*/
   
}

Counter::~Counter() {

}

//GET METHODS

//gets List of the ballots
BallotLinkedList Counter::GetBallotList() {

    return BallotList;

}

//gets List of the candidates
CandidateLinkedList& Counter::GetSenCandidateList() {

    return SenLinkedList;

}

CandidateLinkedList& Counter::GetGovCandidateList() {

    return GovLinkedList;

}

CandidateLinkedList& Counter::GetPresCandidateList() {

    return PresLinkedList;

}

//IMPLEMENTATION METHODS




void Counter::CountAllVotes()
{
    //ballot object
    //check sen vote ID
    //Find a candidate with that ID
    //Add vote to that candidate

    BallotLinkedList list = BallotList.Copy();
    Ballot ballot;


    while (!list.Empty()) {

        
        ballot = list.ReturnFrontItem();
        ballot.VerifyFilledIn();
        if (ballot.GetFilledIn())
        {
            GovLinkedList.FindCandidate(ballot.GetGovVoteCandidate()).AddVote();
            SenLinkedList.FindCandidate(ballot.GetSenVoteCandidate()).AddVote();
            PresLinkedList.FindCandidate(ballot.GetPresVoteCandidate()).AddVote();
        }

        list.RemoveFront();
    }

}


//PRINT FUNCTIONS

//president print function
void Counter::PresidentPrint() {

    cout << "Printing President Information and Votes: " << endl;

    

    CandidateLinkedList list = PresLinkedList.Copy();

    while (!list.Empty()) {

        list.ReturnFrontItem().Print();


        list.RemoveFront();

    }
    cout << endl;
}

//senator print function
void Counter::SenatorPrint() {

    cout << "Printing Senator Information and Votes: " << endl;

    
    CandidateLinkedList list = SenLinkedList.Copy();

    while (!list.Empty()) {

        list.ReturnFrontItem().Print();

        list.RemoveFront();

    }
    cout << endl;

}

//governor print function
void Counter::GovernorPrint() {

    cout << "Printing Governor Information and Votes: " << endl;

    CandidateLinkedList list = GovLinkedList.Copy();

    while (!list.Empty()) {

        list.ReturnFrontItem().Print();

        list.RemoveFront();

    }
    cout << endl;
}


void Counter::BallotListPrint()
{
    cout << "Printing All Ballot Information: " << endl;
    BallotList.ReturnFrontItem().Print();
    if (!BallotList.Empty())
    {
        BallotLinkedList list = BallotList.Copy();

        while (!list.Empty()) {

            list.ReturnFrontItem().Print();

            list.RemoveFront();

        }
        cout << endl;
    }
}
