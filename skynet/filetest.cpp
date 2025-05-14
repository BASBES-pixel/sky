#include <iostream>
#include <fstream>
#include "TrueVec.h"
#include "calculus.h"
#include "bubble.h"
#include "fileWork.h"

using namespace std;

int main(int argc, char* argv[]) 
{

	vector<CBubble> Foam = readFile("enter.txt");
	for(const auto& b: Foam)
	{
		cout<< b <<endl;
	}

	writeCSV( Foam, "filetest.csv", 777);

	return 0;

}
