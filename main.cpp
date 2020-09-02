#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "myPow.h" // got rid of math.h
//
int intBin(const std::string & integer, const int & size);
float fracBin(const std::string & frac, const int & size);
//
int main()
{
    std::cout<<"- enter a binary number: "<<std::flush;
    std::string input = "";
    std::cin>>input;
    // to extract the integer numbers
    std::string integer = "";
    bool check = false;
    for (char i : input)
    {
        if(i == '.') 
        {
            // to check if the number has floating point
            check = true; 
            break;
        }
        integer += i;
    }
    int sizeInteger = integer.length();
    //
    if(check == false)
    {
        std::cout<<"- result in Decimal system: ("<<intBin(integer, sizeInteger)<<")10\n";
    }
    else
    {
        // to extract the fractions after the decimal point
        std::string fraction = ""; 
        std::reverse(input.begin(), input.end());
        for (char i : input)
        {
            if(i == '.') break;
            fraction += i;
        }
        //
        int sizeFrac = fraction.length();
        std::cout<<"- the result in Decimal system: ("<<std::setprecision(21)<<intBin(integer, sizeInteger)+fracBin(fraction, sizeFrac)<<")10\n";
    }
    std:: cout<<"----------------------------------------------------------------\n";
}
// takes the int numbers form the bin
int intBin(const std::string & integer, const int & size) 
{
    int result = 0,  power = 0;
    for (int i = size -1; i >= 0; i--, power++)
    {
        if((integer[i]) != '1' && (integer[i]) != '0') return 0;
        result += (integer[i] - '0') * powInt(2,power);
    }

    return result;
}
// takes the fraction from the bin
float fracBin(const std::string & frac, const int & size) 
{
    int power = -1;
    float result = 0;
    for (int i = size-1; i >=0; i--, power--)
    {
        if((frac[i]) != '1' && (frac[i]) != '0') return 0;
        result += (frac[i] - '0') * powFloat(2,power);
    }
    
    return result;
}