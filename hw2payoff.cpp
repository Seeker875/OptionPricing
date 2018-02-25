
// implemntation of payoff for double digitals

#include "hw2payoff.h"
#include "MinMax.h"

// constructor for call and put
PayOff::PayOff(double Strike_, OptionType TheOptionsType_)
:
    Strike(Strike_), TheOptionsType(TheOptionsType_)
{
}

// constructor for  double digital payoff

PayOff::PayOff(double up_, double low_, OptionType TheOptionsType_)
:
    up(up_),low(low_), TheOptionsType(TheOptionsType_)
{
}

double PayOff::operator ()(double spot) const
{
    switch (TheOptionsType)
    {
    case call : 
        return max(spot-Strike,0.0);

    case put:
        return max(Strike-spot,0.0);

     //Pay off for Double digital   
    case dd:
        if(spot <= up && spot >= low){ 
        return 1.0; 
        }
        else{
            return 0.0;
        }   

    default: 
        throw("unknown option type found.");

    }
}