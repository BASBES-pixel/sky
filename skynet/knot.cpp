#include <iostream>
#include <fstream>
#include "TrueVec.h"
#include "calculus.h"
#include "bubble.h"

using namespace std;

int main(int argc, char* argv[]) {

    std::vector<CBubble> SolarSystem = {
        CBubble(
            "Sun",
            CVec(0, 0, 0),
            CVec(0, 0, 0),                 
	    20,                     
            20                      
        ),
        
        CBubble(
            "Earth",
            CVec(100, 0, 0),         
            CVec(0, 20, 0),          
            3,                     
            3                       
        ),
        
        CBubble(
            "Mars",
            CVec(200, 0, 0),        
            CVec(0, 30, 0),        
            2,                     
            2                      
    	    )
    };

	for( size_t i = 1 ; i < 4 ; i++)
	{	
	cout<<i<<"\n"<<endl;
	for(const auto& b: SolarSystem)
	{
		cout<< b <<endl;
	}

	Knot(SolarSystem, 200);	

	for(const auto& b: SolarSystem)
	{
		cout<< b <<endl;
	}
	}
	return 0;
}
