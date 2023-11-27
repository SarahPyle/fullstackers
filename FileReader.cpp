#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;


FileReader::FileReader() { counter = Counter(); }
FileReader::~FileReader() {}

void FileReader::ReadCandFile(string fileName, string type){
    ifstream fin(fileName, ios::in); //create the stream object
    
   

    vector<string> row;
    string line, word, temp;



    Candidate newCandidate;

    if (fin.is_open())
    {
        while (fin.good())
        {
            //gets the next row in the csv
            getline(fin, line, '\n');

            //turns the line into a stream so that getline can be used on 'line'
            stringstream s(line);
           
            
            if (line != "")
            {
                while (getline(s, word, ',') )
                {

                    
                    row.push_back(word);
                    

                }
                
                //for some reason it gave access violations when writing explicitly so this is how im doing it
                //new candidate is made with the 2nd column being the first name, 3nd last name, and 1st candidate id
                newCandidate = *(new Candidate(row[1], row[2], stod(row[0])));

                if (type == "Sen")
                {
                    //adds the new candidate to the senator linked list
                    //needs to be made where it can choose which list to add to
                    counter.SenLinkedList.AddItemToFront(newCandidate);
                }
                else if (type == "Gov")
                {
                    counter.GovLinkedList.AddItemToFront(newCandidate);
                }
                else if (type == "Pres")
                {
                    counter.PresLinkedList.AddItemToFront(newCandidate);
                }
                row.clear();
                
            }
        }
        fin.close();

    }

    else { std::cout << "Unable to open file.\n"; }
}


void FileReader::ReadBallotFile(string fileName) {
    ifstream fin; //create the stream object

    fin.open(fileName);
    string str;
    vector<string> strVec(20);
    if (fin.is_open())
    {
        //implementation of create aballot objects from data

    }

    else { std::cout << "Unable to open file.\n"; }
}
