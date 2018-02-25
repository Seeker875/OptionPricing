//
//	                	SimpleMCMain2.cpp
//
//     
// 

/*
requires 
         hw2payoff.cpp
         Random1.cpp, 
         SimpleMC.cpp, 
*/

#include "SimpleMC.h"
#include<iostream>
using namespace std;

int main()
{

	double Expiry;
	double Strike;

	double up;
	double low;

	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter strike\n";
	cin >> Strike;

	cout << "\nEnter up \n";
	cin >> up;

	cout << "\nEnter low \n";
	cin >> low;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

    PayOff callPayOff(Strike, PayOff::call);
    PayOff putPayOff(Strike, PayOff::put);

    // payoff for dd
    PayOff ddPayOff(up,low, PayOff::dd);

	double resultCall = SimpleMonteCarlo2(callPayOff,
                                          Expiry,                                           
							              Spot, 
							              Vol, 
							              r, 
						                  NumberOfPaths);
	
    double resultPut = SimpleMonteCarlo2(putPayOff,
                                         Expiry,                                           
							             Spot, 
							             Vol, 
							             r, 
						                 NumberOfPaths);

    double resultDd = SimpleMonteCarlo2(ddPayOff,
                                         Expiry,                                           
							             Spot, 
							             Vol, 
							             r, 
						                 NumberOfPaths);


	cout <<"the prices are " << resultCall << "  for the call,  " 
                                    << resultPut << " for the put and "
                                    << resultPut << " for the double digital\n";;

    double tmp;

    cin >> tmp;

	return 0;

}
