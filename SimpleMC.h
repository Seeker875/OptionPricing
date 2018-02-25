//
//                SimpleMC.h
//
//

#ifndef SIMPLEMC_H
#define SIMPLEMC_H

#include "hw2payoff.h"

double SimpleMonteCarlo2(const PayOff& thePayOff, 
                         double Expiry, 
						 double Spot,
						 double Vol, 
						 double r, 
						 unsigned long NumberOfPaths);


#endif
