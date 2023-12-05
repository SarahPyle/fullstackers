// Tabulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
// version 0.1

//#include "FileReader.h"
#include "Candidate.h"
#include "CandidateLinkedList.h"
#include "CandidateNode.h"
#include "Ballot.h"
#include "BallotLinkedList.h"
#include "BallotNode.h"
#include "Counter.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string Version = "0.1";

int main()
{
	Counter counter = *(new Counter());
	 


	counter.SenLinkedList.AddItemToFront(*(new Candidate("Andrew", "Fink", double(1))));
	counter.SenLinkedList.AddItemToFront(*(new Candidate("Patricia", "Perrera", double(2))));
	counter.SenLinkedList.AddItemToFront(*(new Candidate("Kimberly", "Lowe", double(3))));
	counter.SenLinkedList.AddItemToFront(*(new Candidate("Gavin", "Grigg", double(4))));


	counter.GovLinkedList.AddItemToFront(*(new Candidate("Scarlet", "Green", double(5))));
	counter.GovLinkedList.AddItemToFront(*(new Candidate("Kyle", "Farley", double(6))));
	counter.GovLinkedList.AddItemToFront(*(new Candidate("Chad", "Murna", double(7))));
	counter.GovLinkedList.AddItemToFront(*(new Candidate("Sebastian", "Loxley", double(8))));

	counter.PresLinkedList.AddItemToFront(*(new Candidate("Peter", "Griffin", double(9))));
	counter.PresLinkedList.AddItemToFront(*(new Candidate("Chandler", "Colombus", double(10))));

	counter.BallotList.AddItemToFront(*(new Ballot(1.0, 1.0, 5.0, 2.0, 9.0, true)));
	counter.BallotList.AddItemToFront(*(new Ballot(2.0, 1.0, 5.0, 2.0, 9.0, true)));
	counter.BallotList.AddItemToFront(*(new Ballot(3.0, 1.0, 6.0, 3.0, 9.0, true)));
	counter.BallotList.AddItemToFront(*(new Ballot(4.0, 1.0, 6.0, 3.0, 9.0, true)));
	counter.BallotList.AddItemToFront(*(new Ballot(5.0, 1.0, -1, 4.0, 10.0, true)));
	counter.BallotList.AddItemToFront(*(new Ballot(6.0, 1.0, 7.0, 4.0, 10.0, true)));
	counter.BallotList.AddItemToFront(*(new Ballot(7.0, 1.0, 8.0, 1.0, 10.0, true)));
	counter.BallotList.AddItemToFront(*(new Ballot(8.0, 1.0, 8.0, 1.0, -1, true)));

	counter.BallotListPrint();
	system("pause");
	system("cls");
	counter.GovernorPrint();
	counter.SenatorPrint();
	counter.PresidentPrint();
	system("pause");
	system("cls");

	//counter.BallotListPrint();

	counter.CountAllVotes();
	cout << "Counting votes...\n\n\n";
	counter.GovernorPrint();
	counter.SenatorPrint();
	counter.PresidentPrint();
	//system("pause");
	
}

