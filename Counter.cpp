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

//finding the ballot for that candidate
////void Counter::FindBallotCandidate() {
////
////        BallotLinkedList list = BallotList.Copy();
////        while (!list.Empty()) 
////        {
////
////            Ballot ballot = BallotList.ReturnFrontItem();
////            Candidate cand = GovLinkedList.FindCandidate(ballot.GetGovVoteCandidate());
////            cand.BallotList.AddItemToFront(ballot);
////            
////
////            cand = SenLinkedList.FindCandidate(ballot.GetSenVoteCandidate());
////            cand.BallotList.AddItemToFront(ballot);
////            
////            cand = PresLinkedList.FindCandidate(ballot.GetPresVoteCandidate());
////            cand.BallotList.AddItemToFront(ballot);
////
////            /*AssignBallotToCandidate(ballot.GetGovVoteCandidate(), ballot, "Gov");
////            AssignBallotToCandidate(ballot.GetSenVoteCandidate(), ballot, "Sen");
////            AssignBallotToCandidate(ballot.GetPresVoteCandidate(), ballot, "Pres");*/
////
////            list.RemoveFront();
////
////        }
////
////}

//assigning the ballots to the candidate // checks what the candidate type matches, if (ID) match Gov, assign ballot to Gov, etc
//void Counter::AssignBallotToCandidate(double CandidateID, Ballot& ballot, string CandidateType) {
//
//    Candidate candidate;
//    cout << "Assigning Ballot to Candidate" << endl;
//    if (CandidateType == "Gov") {
//
//
//        GovLinkedList.FindCandidate(CandidateID).AddVote();
//        //candidate.Print();
//
//        }
//    else if (CandidateType == "Sen") {
//
//        candidate = SenLinkedList.FindCandidate(CandidateID);
//
//    }
//
//    else if (CandidateType == "Pres") {
//
//        candidate = PresLinkedList.FindCandidate(CandidateID);
//
//    }
//    candidate.Print();
//    candidate.BallotList.AddItemToFront(ballot); //This might need to be ballot* or ballot&
//            
//}


void Counter::RemoveDuplicates() 
{

    BallotLinkedList temp = *(new BallotLinkedList);
    BallotLinkedList list1 = BallotList.Copy();
    while (!list1.Empty())
    {

        double tempBallID = list1.ReturnFrontItem().GetBallotID();
        double tempDistID = list1.ReturnFrontItem().GetDistrictID();
        double tempSenID = list1.ReturnFrontItem().GetSenVoteCandidate();
        double tempGovID = list1.ReturnFrontItem().GetGovVoteCandidate();
        double tempPresID = list1.ReturnFrontItem().GetPresVoteCandidate();
        double tempFilledIn = list1.ReturnFrontItem().GetFilledIn();

        int identical = 0;
        int duplicates = 0;

        list1.RemoveFront();
        BallotLinkedList list2 = list1.Copy();
        /*while (!list2.Empty())
        {*/
            if (!list2.Empty()&&list2.ReturnFrontItem().BallotID == tempBallID && list2.ReturnFrontItem().DistrictID == tempDistID) {
                duplicates++;
                if (list2.ReturnFrontItem().SenatorVote == tempSenID && list2.ReturnFrontItem().GovernorVote == tempGovID
                    && list2.ReturnFrontItem().PresidentialVote == tempPresID) {
                    identical++;

                }

            }
            if (identical == duplicates) {
                temp.AddItemToFront(*new Ballot(tempBallID, tempDistID, tempGovID, tempSenID, tempPresID, tempFilledIn));
            }
            if (list1.FindBallot(tempBallID).BallotID != -1)
            {
                list1.RemoveItem(list1.FindBallot(tempBallID));
            }
        //}
    }
    BallotList = temp;
}


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
