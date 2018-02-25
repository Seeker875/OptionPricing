// Payoff including double digitals

#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
{

public:

    enum  OptionType {call, put,dd};
    PayOff(double Strike_, OptionType TheOptionsType_);
    //Constructor for double digitals
    PayOff(double up_, double low_, OptionType TheOptionsType_);
    // This is for creating functor of payoff
    double operator()(double Spot) const;

private:
    // up and low limits for double digitals l
    double up,low;
    double Strike;
    OptionType TheOptionsType;

};

#endif