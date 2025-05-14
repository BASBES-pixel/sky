#include <iostream>
#include <fstream>
#include "TrueVec.h"
#include "calculus.h"
#include "bubble.h"

using namespace std;

int main(int argc, char* argv[]) {

//TrueVec Check
	cout<<"TrueVec Check"<<endl;
	CVec V1(1,2,5), V2(1.2,2.3,3.1);
	cout<< "V1 =" << V1 <<endl;
	cout<< "V2 =" << V2 <<endl;
	cout<<"V1 + V2 =" << V1 + V2<<endl;
	cout<< "V1 - V2 =" <<V1 - V2 <<endl;
	cout<< "V1 * 2 = " <<V1.dot(2) <<endl;
	cout<< "V1.len() = " <<V1.len() <<endl;
	cout<< "V1.getx() = " <<V1.getx() << endl;
	cout<< "V1.nVec = "<<V1.nVec() <<endl;
//CBubble Check
	cout<<"\nCBubble Check"<<endl;

	CBubble Bub1( "Bub1", CVec(1,2,3), CVec(1.1,4.4,9.9), 42, 37);

	cout<< "Bub = " << Bub1 << endl;
	cout<< "Mass = " << Bub1.get_Mass() << endl;
	cout<< "Vel = " << Bub1.get_Vel() << endl;
	cout<< "Rad = " << Bub1.get_Rad() << endl;
	cout<< "Cord = " << Bub1.get_Cord() << endl;
	
 	try 
	{
        	Bub1.change_Mass(-1);
	}
 	catch (const std::invalid_argument& e)
       	{
		cerr << "Invalid argument error: " << e.what() << endl;
	}
	catch (const std::runtime_error& e)
       	{
		cerr << "Runtime error: " << e.what() << endl;
	}
	catch (...)
       	{
		cerr << "Unknown error occurred" << endl;
	}

	try
       	{
		CBubble bubble( "WRONG", CVec(), CVec(), -1, -1);
	}
 	catch (const std::invalid_argument& e)
       	{
		cerr << "Invalid argument error: " << e.what() << endl;
	}
	catch (const std::runtime_error& e)
       	{
		cerr << "Runtime error: " << e.what() << endl;
	}
	catch (...)
       	{
		cerr << "Unknown error occurred" << endl;
	}	
	
	Bub1.change_Mass(1337);

	cout<< "Bub = " << Bub1 << endl;

//Calculus Check
	cout<<"\nCalculus Check"<<endl;
	CBubble Bub2( "Bub2", CVec(7,8,10), CVec(1,4,9), 42, 37), Bub3( "Bub3", CVec(2,7,8), CVec(11,44,99), 42, 37);

	cout<< "GrFi(Bub2,Bub3) = " << GrFi(Bub2,Bub3) << endl;
	
	try
	{
		GrFi(Bub1,Bub1);
	}
 	catch (const std::invalid_argument& e)
       	{
		cerr << "Invalid argument error: " << e.what() << endl;
	}
	catch (const std::runtime_error& e)
       	{
		cerr << "Runtime error: " << e.what() << endl;
	}
	catch (...)
       	{
		cerr << "Unknown error occurred" << endl;
	}	
	
	std::cout<<std::endl;
	vector<CBubble> Foam = {Bub1, Bub2, Bub3};
	std::vector<CVec> acc = Accel(Foam);
	for(const auto& a: acc)
	{
		cout<< "Acceleration =  " << a << endl;
	}
	cout<<"Before\n"<<endl;
	for(const auto& b: Foam)
	{
		cout<< b <<endl;
	}

	Knot(Foam, 0.1);
	
	cout<<"After"<<endl;
	for(const auto& b: Foam)
	{
		cout<< b <<endl;
	}

	return 0;
}
