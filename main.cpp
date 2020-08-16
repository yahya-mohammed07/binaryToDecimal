#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
//*
int rBinToDec(const std::string & integer);
float fracBinToDec(const std::string & frac);
int myPowInt(const int & number, const int & times); //* to get rid of std::pow
float myPowFloat(const int & number, const int & times);


//*
int main()
{
    std::cout<<"- enter a binary number: "<<std::flush;
    std::string input = "";
    std::getline(std::cin, input);
    //*
    std::string integer = ""; //* to extract the integer numbers
    for (char i : input)
    {
        if(i == '.') break;
        integer += i;
    }
    bool check = false;
    std::string fraction = ""; //* to extract the fractions after the decimal point
    for (int i = input.length() - 1; i > 0; i--)
    {
        if (input[i] == '.') 
        {
            check = true; //* to check if the number has decimal point
            break;
        }
        fraction += input[i];
    }
    //*
    std::reverse(fraction.begin(),fraction.end()); //* reverse the number to get the left most numbers
    if(check == false)
    {
        std::cout<<"- result in Decimal system: ("<<rBinToDec(integer)<<")10\n";
    }
    else
    {
        std::cout<<"- the result in Decimal system: ("<<std::setprecision(21)<<rBinToDec(integer)+fracBinToDec(fraction)<<")10\n";
    }
    std:: cout<<"----------------------------------------------------------------\n";
}
//*
int rBinToDec(const std::string & integer) //* takes the real numbers form the binary
{
    int result = 0,  power = 0;
    for (int i = integer.length()-1; i >= 0; i--, power++)
    {
        if((integer[i]) != '1' && (integer[i]) != '0') return 0;
        result += (integer[i] - '0') * myPowInt(2,power);
    }

    return result;
}
//*
float fracBinToDec(const std::string & frac) //* takes the fraction from the bin number
{
    int power = -1;
    float result = 0;
    for (std::size_t i = 0; i < frac.length(); i++, power--)
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
float myPowFloat(const int & number, const int & times)
{
    float result = 1;
    for (int i = 0; i < std::abs(times); ++i)
    {
        result *= (1.0 / number);
    }
    
    return result;
}