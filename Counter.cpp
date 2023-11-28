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
CandidateLinkedList Counter::GetSenCandidateList() {

    return SenLinkedList;

}

CandidateLinkedList Counter::GetGovCandidateList() {

    return GovLinkedList;

}

CandidateLinkedList Counter::GetPresCandidateList() {

    return PresLinkedList;

}

//IMPLEMENTATION METHODS

//finding the ballot for that candidate
void Counter::FindBallotCandidate() {

        BallotLinkedList list = BallotList.Copy();
        while (!list.Empty()) 
        {

            Ballot ballot = BallotList.ReturnFrontItem();
            Candidate cand = GovLinkedList.FindCandidate(ballot.GetGovVoteCandidate());
            cand.BallotList.AddItemToFront(ballot);
            

            cand = SenLinkedList.FindCandidate(ballot.GetSenVoteCandidate());
            cand.BallotList.AddItemToFront(ballot);
            
            cand = PresLinkedList.FindCandidate(ballot.GetPresVoteCandidate());
            cand.BallotList.AddItemToFront(ballot);

            /*AssignBallotToCandidate(ballot.GetGovVoteCandidate(), ballot, "Gov");
            AssignBallotToCandidate(ballot.GetSenVoteCandidate(), ballot, "Sen");
            AssignBallotToCandidate(ballot.GetPresVoteCandidate(), ballot, "Pres");*/

            list.RemoveFront();

        }

}

//assigning the ballots to the candidate // checks what the candidate type matches, if (ID) match Gov, assign ballot to Gov, etc
void Counter::AssignBallotToCandidate(double CandidateID, Ballot& ballot, string CandidateType) {

    Candidate candidate;
    cout << "Assigning Ballot to Candidate" << endl;
    if (CandidateType == "Gov") {

        candidate = GovLinkedList.FindCandidate(CandidateID);
        //candidate.Print();

        }
    else if (CandidateType == "Sen") {

        candidate = SenLinkedList.FindCandidate(CandidateID);

    }

    else if (CandidateType == "Pres") {

        candidate = PresLinkedList.FindCandidate(CandidateID);

    }
    candidate.Print();
    candidate.BallotList.AddItemToFront(ballot); //This might need to be ballot* or ballot&
            
}


void Counter::RemoveDuplicates() 
{

        BallotLinkedList list = BallotList.Copy();
        while (!list.Empty()) 
        {

            double tempBallID = list.ReturnFrontItem().GetBallotID();
            double tempDistID = list.ReturnFrontItem().GetDistrictID();
            double tempSenID = list.ReturnFrontItem().GetSenVoteCandidate();
            double tempGovID = list.ReturnFrontItem().GetGovVoteCandidate();
            double tempPresID = list.ReturnFrontItem().GetPresVoteCandidate();
            double tempFilledIn = list.ReturnFrontItem().GetFilledIn();
            bool identical = true;
            bool duplicates = false;
            list.RemoveFront();
            Ballot tempBallot = list.FindBallot(tempBallID);
            if(tempBallot.GetBallotID()!=-1 && tempBallot.GetDistrictID() == tempDistID)
            {
                duplicates = true;
                //if(tempBallot.GetDistrictID()!=tempDistID) {identical=false;}
                if(tempBallot.GetGovVoteCandidate()!=tempGovID) {identical=false;}
                if (tempBallot.GetPresVoteCandidate()!=tempPresID) {identical=false;}
                if (tempBallot.GetSenVoteCandidate()!=tempSenID) {identical=false;}
            }
            if(identical == false)
            {
                while (BallotList.FindBallot(tempBallID).GetBallotID()==tempBallID)
                {
                    BallotList.RemoveItem(BallotList.FindBallot(tempBallID));
                }
            }
            if(duplicates && identical)
            {
                while (BallotList.FindBallot(tempBallID).GetBallotID()==tempBallID)
                {
                        BallotList.RemoveItem(BallotList.FindBallot(tempBallID));
                }
                Ballot replace = *(new Ballot(tempBallID, tempDistID, tempGovID, tempSenID, tempPresID, tempFilledIn));
                BallotList.AddItemToBack(replace);
            }
            

        }

        
    
}


void Counter::CountAllVotes()
{
    CandidateLinkedList list = SenLinkedList.Copy();

    while (!list.Empty()) 
    {

        list.ReturnFrontItem().CountVotes();


        list.RemoveFront();

    }
    list  = GovLinkedList.Copy();

    while (!list.Empty()) 
    {

        list.ReturnFrontItem().CountVotes();


        list.RemoveFront();

    }
    list = PresLinkedList.Copy();

    while (!list.Empty()) 
    {

        list.ReturnFrontItem().CountVotes();


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
}

//senator print function
void Counter::SenatorPrint() {

    cout << "Printing Senator Information and Votes: " << endl;

    
    CandidateLinkedList list = SenLinkedList.Copy();

    while (!list.Empty()) {

        list.ReturnFrontItem().Print();

        list.RemoveFront();

    }
}

//governor print function
void Counter::GovernorPrint() {

    cout << "Printing Governor Information and Votes: " << endl;

    CandidateLinkedList list = GovLinkedList.Copy();

    while (!list.Empty()) {

        list.ReturnFrontItem().Print();

        list.RemoveFront();

    }
}


void Counter::BallotListPrint()
{
    cout << "Printing All Ballot Information: " << endl;
    BallotLinkedList list = BallotList.Copy();

    while (!list.Empty()) {

        list.ReturnFrontItem().Print();

        list.RemoveFront();

    }
}
