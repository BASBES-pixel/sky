#include <iostream>
#include <fstream>
#include "TrueVec.h"
#include "calculus.h"
#include "bubble.h"
#include "fileWork.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	
	double  T = 1, dT = 0.05, t = 0;
	vector<CBubble> Foam = readFile("enter.txt");
	Sizes Sizes;
	Sizes = desize(Foam);
	string filename = "DATA.csv";
	for(const auto& b: Foam)
	{
		cout<< b <<endl;
	}

	std::ofstream file(filename, std::ios::trunc); 
	file.close();

	while(t <= T)
	{
		Knot(Foam, dT);
		writeCSV( Foam, filename, t,Sizes);
 		t += dT;
	}

	
	return 0;
}
