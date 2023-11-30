#include "pch.h"
#include "CppUnitTest.h"
#include "../Counter.h"
#include "../Candidate.h"
#include "../CandidateLinkedList.h"
#include "../CandidateNode.h"
#include "../Ballot.h"
#include "../BallotLinkedList.h"
#include "../BallotNode.h"

#include "../Counter.cpp"
#include "../Candidate.cpp"
#include "../CandidateLinkedList.cpp"

#include "../Ballot.cpp"
#include "../BallotLinkedList.cpp"




using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDraft1
{
	TEST_CLASS(UnitTestDraft1)
	{
	public:

		TEST_METHOD(TestMethodBallotBLL) {
			//Tests  AddItemtoFront and ReturnFrontItem for the BallotLinkedList class.
			Ballot ballotActual1 = *(new Ballot(1, 3, 2, 1, 1, true)); //instantiate a  ballot
			Ballot ballotActual2 = *(new Ballot(2, 3, 1, 2, 1, true)); //instantiate a  ballot
			BallotLinkedList ballotList = *(new BallotLinkedList()); //Instanttiate a LinkedList for Ballot
			ballotList.AddItemToFront(ballotActual1);
			ballotList.AddItemToFront(ballotActual2);
			Ballot ballotExpected = ballotList.ReturnFrontItem();
			Assert::AreEqual(ballotExpected.BallotID, ballotActual2.BallotID);
		}
		TEST_METHOD(TestMethodCounterInvalidBallot) {
			Counter counter = Counter(); // initializes a counter 

			counter.SenLinkedList.AddItemToFront(*(new Candidate("Andrew", "Fink", double(1))));
			counter.SenLinkedList.AddItemToFront(*(new Candidate("Patricia", "Perrera", double(2))));

			counter.GovLinkedList.AddItemToFront(*(new Candidate("Scarlet", "Green", double(5))));
			counter.GovLinkedList.AddItemToFront(*(new Candidate("Kyle", "Farley", double(6))));


			counter.PresLinkedList.AddItemToFront(*(new Candidate("Matthew", "Harley", double(9))));
			counter.PresLinkedList.AddItemToFront(*(new Candidate("Chandler", "Colombus", double(10))));

			counter.BallotList.AddItemToFront(*(new Ballot(1.0, 1.0, 5.0, 2.0, -1, true)));
			counter.BallotList.AddItemToFront(*(new Ballot(2.0, 1.0, 5.0, 2.0, -1, true)));

			counter.CountAllVotes();
			double totalVotesExpected = 0;

			Assert::AreEqual(totalVotesExpected, counter.GetGovCandidateList().FindCandidate(5.0).GetTotalVotes());
			Assert::AreEqual(totalVotesExpected, counter.GetSenCandidateList().FindCandidate(2.0).GetTotalVotes());
			Assert::AreEqual(totalVotesExpected, counter.GetPresCandidateList().FindCandidate(9.0).GetTotalVotes());
		}
		TEST_METHOD(TestMethodCounterAddingVoteCase1) {

			Counter counter = Counter(); // initializes a counter 

			counter.SenLinkedList.AddItemToFront(*(new Candidate("Andrew", "Fink", double(1))));
			counter.SenLinkedList.AddItemToFront(*(new Candidate("Patricia", "Perrera", double(2))));

			counter.GovLinkedList.AddItemToFront(*(new Candidate("Scarlet", "Green", double(5))));
			counter.GovLinkedList.AddItemToFront(*(new Candidate("Kyle", "Farley", double(6))));


			counter.PresLinkedList.AddItemToFront(*(new Candidate("Matthew", "Harley", double(9))));
			counter.PresLinkedList.AddItemToFront(*(new Candidate("Chandler", "Colombus", double(10))));

			counter.BallotList.AddItemToFront(*(new Ballot(1.0, 1.0, 5.0, 2.0, 10.0, true)));
			counter.BallotList.AddItemToFront(*(new Ballot(2.0, 1.0, 6.0, 2.0, 9.0, true)));
			counter.BallotList.AddItemToFront(*(new Ballot(3.0, 1.0, 6.0, 2.0, 9.0, true)));


			counter.CountAllVotes();
			double totalVotesExpected = 1.0;
			double totalVotesExpected2 = 2.0;
			double totalVotesExpected3 = 3.0;


			Assert::AreEqual(totalVotesExpected, counter.GetGovCandidateList().FindCandidate(5.0).GetTotalVotes());
			Assert::AreEqual(totalVotesExpected3, counter.GetSenCandidateList().FindCandidate(2.0).GetTotalVotes());
			Assert::AreEqual(totalVotesExpected2, counter.GetPresCandidateList().FindCandidate(9.0).GetTotalVotes());



		}
		TEST_METHOD(TestMethodCounterAddingVoteCase2) {
			//This test case is with one valid and one invalid ballot, to test that only the valid ballots are being tallied.

			Counter counter = Counter(); // initializes a counter 

			counter.SenLinkedList.AddItemToFront(*(new Candidate("Andrew", "Fink", double(1))));
			counter.SenLinkedList.AddItemToFront(*(new Candidate("Patricia", "Perrera", double(2))));

			counter.GovLinkedList.AddItemToFront(*(new Candidate("Scarlet", "Green", double(5))));
			counter.GovLinkedList.AddItemToFront(*(new Candidate("Kyle", "Farley", double(6))));


			counter.PresLinkedList.AddItemToFront(*(new Candidate("Matthew", "Harley", double(9))));
			counter.PresLinkedList.AddItemToFront(*(new Candidate("Chandler", "Colombus", double(10))));

			counter.BallotList.AddItemToFront(*(new Ballot(1.0, 1.0, 5.0, 2.0, -1, true)));
			counter.BallotList.AddItemToFront(*(new Ballot(2.0, 1.0, 5.0, 2.0, 9.0, true)));


			counter.CountAllVotes();
			double totalVotesExpected = 1.0;


			Assert::AreEqual(totalVotesExpected, counter.GetGovCandidateList().FindCandidate(5.0).GetTotalVotes());
			Assert::AreEqual(totalVotesExpected, counter.GetSenCandidateList().FindCandidate(2.0).GetTotalVotes());
			Assert::AreEqual(totalVotesExpected, counter.GetPresCandidateList().FindCandidate(9.0).GetTotalVotes());
		}
		TEST_METHOD(TestMethodBallotRemoval1) {
			//Tests  RemoveFront() Function of BallotLinkedList class.
			Ballot ballotActual1 = *(new Ballot(1, 3, 2, 1, 1, true)); //instantiate a  ballot
			Ballot ballotActual2 = *(new Ballot(2, 3, 1, 2, 1, true)); //instantiate a  ballot
			BallotLinkedList ballotList = *(new BallotLinkedList()); //Instantiate a LinkedList for Ballot
			ballotList.AddItemToFront(ballotActual1);
			ballotList.AddItemToFront(ballotActual2);
			ballotList.RemoveFront();
			Ballot ballotExpected = ballotList.ReturnFrontItem();
			Assert::AreEqual(ballotExpected.BallotID, ballotActual1.BallotID);
		}
		TEST_METHOD(TestMethodBallotRemoval2) {
			//Tests  RemoveItem() Function of BallotLinkedList class.
			Ballot ballotActual1 = *(new Ballot(1, 3, 2, 1, 1, true)); //instantiate a  ballot
			Ballot ballotActual2 = *(new Ballot(2, 3, 1, 2, 1, true)); //instantiate a  ballot
			BallotLinkedList ballotList = *(new BallotLinkedList()); //Instantiate a LinkedList for Ballot
			ballotList.AddItemToFront(ballotActual2);
			ballotList.AddItemToFront(ballotActual1);
			ballotList.RemoveItem(ballotActual1);
			Ballot ballotExpected = ballotList.ReturnFrontItem();
			Assert::AreEqual(ballotExpected.BallotID, ballotActual2.BallotID);
		}
		TEST_METHOD(TestMethodBallotBack) {
			//Tests  AddItemtoBack()
			Ballot ballotActual1 = *(new Ballot(1, 3, 2, 1, 1, true)); //instantiate a  ballot
			Ballot ballotActual2 = *(new Ballot(2, 3, 1, 2, 1, true)); //instantiate a  ballot
			BallotLinkedList ballotList = *(new BallotLinkedList()); //Instantiate a LinkedList for Ballot
			ballotList.AddItemToBack(ballotActual1);
			ballotList.AddItemToBack(ballotActual2);
			
			Ballot ballotExpected = ballotList.ReturnFrontItem();
			Assert::AreEqual(ballotExpected.BallotID, ballotActual1.BallotID);
		}
		TEST_METHOD(TestMethodFindBallot) {
			//Tests  FindBallot()
			Ballot ballotActual1 = *(new Ballot(1, 3, 2, 1, 1, true)); //instantiate a  ballot
			Ballot ballotActual2 = *(new Ballot(2, 3, 1, 2, 1, true)); //instantiate a  ballot
			BallotLinkedList ballotList = *(new BallotLinkedList()); //Instantiate a LinkedList for Ballot
			ballotList.AddItemToBack(ballotActual1);
			ballotList.AddItemToFront(ballotActual2);

			Ballot ballotExpected = ballotList.FindBallot(ballotActual1.BallotID);
			Assert::AreEqual(ballotExpected.BallotID, ballotActual1.BallotID);
		}
		TEST_METHOD(TestMethodCandidateCLL) {
			//This method tests the GetCandidateID() function from the CandidateLinkedList class.
			CandidateLinkedList CandidateList = *(new CandidateLinkedList);
			Candidate ExpectedCandidate = *(new Candidate("Jose", "Perrera", double(14)));
			CandidateList.AddItemToFront(ExpectedCandidate);
			Candidate ActualCandidate = CandidateList.ReturnFrontItem();
			Assert::AreEqual(ExpectedCandidate.GetCandidateID(), ActualCandidate.GetCandidateID());
		}
		TEST_METHOD(TestMethodCandidateFront) {
			//This method tests the AddItemToFront and ReturnFrontItem() functions.
			CandidateLinkedList CandidateList = *(new CandidateLinkedList);
			Candidate ActualCandidate1 = *(new Candidate("Jordan", "Shropshire", double(12)));
			Candidate ActualCandidate2 = *(new Candidate("Jordan", "Shropshires", double(14)));
			CandidateList.AddItemToFront(ActualCandidate1);
			CandidateList.AddItemToFront(ActualCandidate2);
			Candidate ExpectedCandidate = CandidateList.ReturnFrontItem();
			Assert::AreEqual(ExpectedCandidate.CandidateID, ActualCandidate2.CandidateID);
		}
		TEST_METHOD(TestMethodCandidateRemoveFront) {
			//This method tests the RemoveFront() function.
			CandidateLinkedList CandidateList = *(new CandidateLinkedList);
			Candidate ActualCandidate1 = *(new Candidate("Jordan", "Shropshire", double(12)));
			Candidate ActualCandidate2 = *(new Candidate("Jordan", "Shropshires", double(14)));
			CandidateList.AddItemToFront(ActualCandidate1);
			CandidateList.AddItemToFront(ActualCandidate2);
			CandidateList.RemoveFront();
			Candidate ExpectedCandidate = CandidateList.ReturnFrontItem();
			Assert::AreEqual(ExpectedCandidate.CandidateID, ActualCandidate1.CandidateID);
		}
		TEST_METHOD(TestMethodCandidateRemoveItem) {
			//This method tests the RemoveItem() function.
			CandidateLinkedList CandidateList = *(new CandidateLinkedList);
			Candidate ActualCandidate1 = *(new Candidate("Jordan", "Michael", double(12)));
			Candidate ActualCandidate2 = *(new Candidate("Jordan", "Shropshire", double(14)));
			Candidate ActualCandidate3 = *(new Candidate("John", "Jack", double(1)));
			CandidateList.AddItemToFront(ActualCandidate1);
			CandidateList.AddItemToFront(ActualCandidate2);
			CandidateList.AddItemToFront(ActualCandidate3);
			CandidateList.RemoveItem(ActualCandidate3);
			Candidate ExpectedCandidate = CandidateList.ReturnFrontItem();
			Assert::AreEqual(ExpectedCandidate.CandidateID, ActualCandidate2.CandidateID);
		}
		TEST_METHOD(TestMethodFindCandidate) {
			//This method tests the FindCandidate() function.
			CandidateLinkedList CandidateList = *(new CandidateLinkedList);
			Candidate ActualCandidate1 = *(new Candidate("Jordan", "Michael", double(12)));
			Candidate ActualCandidate2 = *(new Candidate("Jordan", "Shropshire", double(14)));
			Candidate ActualCandidate3 = *(new Candidate("John", "Jack", double(1)));
			CandidateList.AddItemToFront(ActualCandidate1);
			CandidateList.AddItemToFront(ActualCandidate2);
			CandidateList.AddItemToFront(ActualCandidate3);
			
			Candidate ExpectedCandidate = CandidateList.FindCandidate(12);
			Assert::AreEqual(ExpectedCandidate.CandidateID, ActualCandidate1.CandidateID);
		}

		TEST_METHOD(TestMethodVerifyFilledIn) {
			//This tests the VerifyFilledIn function from the Ballot class.
			Ballot ballotActual1 = *(new Ballot(-1, -1, -1, -1, -1, true));
			Ballot ballotActual2 = *(new Ballot(2, 2, -1, 2, -1, true));
			Ballot ballotActual3 = *(new Ballot(-1, 3, 2, 1, 1, true));
			Ballot ballotActual4 = *(new Ballot(4, -1, -1, 2, -1, true));
			Ballot ballotActual5 = *(new Ballot(5, 1, 1, 2, 1, true));
			ballotActual1.VerifyFilledIn();
			ballotActual2.VerifyFilledIn();
			ballotActual3.VerifyFilledIn();
			ballotActual4.VerifyFilledIn();
			ballotActual5.VerifyFilledIn();
			bool expected1 = false;
			bool expected2 = false;
			bool expected3 = false;
			bool expected4 = false;
			bool expected5 = true;
			Assert::AreEqual(expected1, ballotActual1.GetFilledIn());
			Assert::AreEqual(expected2, ballotActual2.GetFilledIn());
			Assert::AreEqual(expected3, ballotActual3.GetFilledIn());
			Assert::AreEqual(expected4, ballotActual4.GetFilledIn());
			Assert::AreEqual(expected5, ballotActual5.GetFilledIn());
			
		}
		TEST_METHOD(TestMethodCounterAddingVoteCase3) {
			//This test case is for testing AddVote() from the Candidate Class.

			Counter counter = Counter(); // initializes a counter 

			

			counter.GovLinkedList.AddItemToFront(*(new Candidate("Kaley", "Green", double(5))));
			counter.GovLinkedList.AddItemToFront(*(new Candidate("Sarah", "Farley", double(6))));

			counter.BallotList.AddItemToFront(*(new Ballot(1.0, 1.0, 5.0, 2.0, -1, true)));
			counter.BallotList.AddItemToFront(*(new Ballot(2.0, 1.0, 5.0, 2.0, 9.0, true)));
			counter.GetGovCandidateList().FindCandidate(5.0).AddVote();


			counter.CountAllVotes();
			double totalVotesExpected = 2.0;


			Assert::AreEqual(totalVotesExpected, counter.GetGovCandidateList().FindCandidate(5.0).GetTotalVotes());
			
		}



		
		

	};
}
