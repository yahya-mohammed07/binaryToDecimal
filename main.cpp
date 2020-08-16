#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <math.h>
//*
int intBin(const std::string & integer, const int & size);
float fracBin(const std::string & frac, const int & size);
int myPowInt(const int & number, const int & times); //* to get rid of std::pow
float myPowFloat(const int & number, int times); //* to get rid of std::pow
//*
int main()
{
    std::cout<<"- enter a binary number: "<<std::flush;
    std::string input = "1101011";
    //std::cin>>input;
    //*
    std::string integer = ""; //* to extract the integer numbers
    bool check = false;
    for (char i : input)
    {
        if(i == '.') 
        {
            check = true; //* to check if the number has decimal point
            break;
        }
        integer += i;
    }
    int sizeInteger = integer.length();
    //*
    if(check == false)
    {
        std::cout<<"- result in Decimal system: ("<<intBin(integer, sizeInteger)<<")10\n";
    }
    else
    {
        std::string fraction = ""; //* to extract the fractions after the decimal point
        for (int i = input.length() - 1; i > 0; i--)
        {
            if (input[i] == '.') break;
            fraction += input[i];
        }
        //
        std::reverse(fraction.begin(),fraction.end()); //* reverse the number to get the left most numbers
        int sizeFrac = fraction.length();
        std::cout<<"- the result in Decimal system: ("<<std::setprecision(21)<<intBin(integer, sizeInteger)+fracBin(fraction, sizeFrac)<<")10\n";
    }
    std:: cout<<"----------------------------------------------------------------\n";
}
//*
int intBin(const std::string & integer, const int & size) //* takes the int numbers form the bin
{
    int result = 0,  power = 0;
    for (int i = size -1; i >= 0; i--, power++)
    {
        if((integer[i]) != '1' && (integer[i]) != '0') return 0;
        result += (integer[i] - '0') * myPowInt(2,power);
    }

    return result;
}
//*
float fracBin(const std::string & frac, const int & size) //* takes the fraction from the bin
{
    int power = -1;
    float result = 0;
    for (std::size_t i = 0; i < size; i++, power--)
    {
        if((frac[i]) != '1' && (frac[i]) != '0') return 0;
        result += (frac[i] - '0') * myPowFloat(2,power);
    }
    
    return result;
}
//* my pow
int myPowInt(const int & base, const int & power)
{
    int result = 1;
    for (int i = 0; i < power; ++i)
    {
        result *= base;
    }
    
    return result;
}
float myPowFloat(const int & number, int times)
{
    float result = 1;
    times = std::abs(times);
    for (int i = 0; i < times; ++i)
    {
        result *= (1.0 / number);
    }
    
    return result;
}