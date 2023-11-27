#ifndef FILEREADER_H
#define FILEREADER_H
#include "Counter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class FileReader
{
public:
	Counter counter; //This is an object of our counter class
	FileReader();
	~FileReader();
	void ReadCandFile(string fileName, string type);
	void ReadBallotFile(string FileName);
};
#endif
