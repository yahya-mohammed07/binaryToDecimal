#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include "myPow.h"h

//
int intBin(const std::string & integer, const int & size);
double fracBin(const std::string & frac, const int & size);
//
int main()
{
    std::cout<<"- enter a binary number: "<<std::flush;
    std::string input = "";
    std::cin>>input;
    std::cin.ignore();
    // taking input from the user will make it little bit slower
    auto start = std::chrono::high_resolution_clock::now();
    // to extract the integer numbers
    std::string integer = "";
    bool check = false;
    for (unsigned char i : input)
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
    // if there is no floating point
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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration(end - start);
    printf("time: %0.4f millsecond\n\n", duration.count() * 1000);

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
double fracBin(const std::string & frac, const int & size) 
{
    int power = -1;
    double result = 0;
    for (int i = size-1; i >=0; i--, power--)
    {
        if((frac[i]) != '1' && (frac[i]) != '0') return 0;
        result += (frac[i] - '0') * powFloat(2,power);
    }
    
    return result;
}