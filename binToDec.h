#ifndef __BINTODEC_H__
#define __BINTODEC_H__

#include <string>
#include "myPow.h"
/*
* bases on algorithm witch takes for non float number the right most number and
* multiplies them with 2^0 and so on
*/
long long intBin(const std::string & integer, const std::size_t & size) 
{
    long long result = 0, power = 0;
    for (long long i = size - 1; i >= 0; i--, power++)
    {
        // returns 0 if the input was not 1 or 0
        if((integer[i]) != '1' && (integer[i]) != '0') return 0;
        //
        result += (integer[i] - '0') * powll(2,power);
    }
    return result;
}
/*
* bases on algorithm witch takes the numbers after the fraction and multiplies them with 
* 2^-1 and so on
*/
long double fracBin(const std::string & frac, const std::size_t & size) 
{
    long long power = -1;
    long double result = 0;
    for (int i = size - 1; i >= 0; i--, power--)
    {
        // returns 0 if the input was not 1 or 0
        if((frac[i]) != '1' && (frac[i]) != '0') return 0;
        //
        result += (frac[i] - '0') * powLd(2,power);
    }
    return result;
}
#endif // __BINTODEC_H__