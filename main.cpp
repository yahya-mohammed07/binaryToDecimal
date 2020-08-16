#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
//*
int rBinToDec(const std::string & integer);
float fracBinToDec(const std::string & frac);
int myPow(const int & base, const int & power); //* to get rid of std::pow

//*
int main()
{
    std::cout<<"- enter a binary number: "<<std::flush;
    std::string input = "1011010101.1110101";
    //std::getline(std::cin, input);
    //*
    std::string integer = "";
    for (char i : input)
    {
        if(i == '.') break;
        integer += i;
    }
    bool check = false;
    std::string fraction = "";
    for (int i = input.length()-1; i>0;i--)
    {
        if (input[i] == '.') 
        {
            check = true;
            break;
        }
        fraction += input[i];
    }
    //*
    std::reverse(fraction.begin(),fraction.end());
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
        result += (integer[i] - '0') * myPow(2,power);
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
        result += (frac[i] - '0') * std::pow(2,power); //* TODO: make myPow works on this too
    }
    
    return result;
}

int myPow(const int & base, const int & power)
{
    int result = 1;
    for (int i = 0; i < power; ++i)
    {
        result *= base;
    }
    
    return std::abs(result);
}