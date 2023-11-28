// Tabulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
// version 0.0.04

#include "FileReader.h"
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

string Version = "0.0.0.4";

int main()
{
	FileReader fileReader = FileReader();

	fileReader.ReadCandFile("SenCand.csv", "Sen");
	
	fileReader.ReadCandFile("GovCand.csv", "Gov");
	fileReader.ReadCandFile("PresCand.csv", "Pres");
	
	

	fileReader.ReadBallotFile("Ballots.csv");
	//fileReader.counter.BallotListPrint();
	fileReader.counter.RemoveDuplicates();
	//fileReader.counter.BallotListPrint();
	fileReader.counter.FindBallotCandidate();

	fileReader.counter.SenatorPrint();
	fileReader.counter.GovernorPrint();
	fileReader.counter.PresidentPrint();
}

