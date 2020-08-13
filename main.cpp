#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <iomanip>
//*
int rBinToDec(const std::string & integer) //* takes the real numbers form the binary
{
    int j = 0;
    int result = 0;
    for (int i = integer.length()-1; i >= 0; i--, j++)
    {
        int intValue = integer[i] - '0';
        result += intValue * std::pow(2,j);
        if(intValue > 1 || intValue < 0)
        {
            throw std::domain_error("not binary system!");
        }
    }

    return result;
}
//*
float fracBinToDec(const std::string & frac) //* takes the fraction from the bin number
{
    int j = -1;
    float result = 0;
    for (std::size_t i = 0; i < frac.length(); i++, j--)
    {
        int intFrac = frac[i] - '0';
        result += intFrac * std::pow(2,j);
        if(intFrac > 1 || intFrac < 0)
        {
            throw std::domain_error("not binary system!");
        }
    }
    
    return result;
}
int main()
{
    std:: cout<<"- enter a binary number: "<<std:: flush;
    std::string input = "";
    std::getline(std::cin, input);
    std::string sFraction = "";
    //*
    std::string integer = "";
    for (char i : input)
    {
        if(i == '.') break;
        integer += i;
    }
    bool check = false;
    for (int i = input.length()-1; i>0;i--)
    {
        if (input[i] == '.') 
        {
            check = true;
            break;
        }
        sFraction += input[i];
    }
    //*
    if(check == false)
    {
        std::cout<<"- result in Decimal system: ("<<rBinToDec(integer)<<")10"<<std::endl;
    }
    else
    {
        std::cout<<"- the result in Decimal system: ("<<std::setprecision(21)<<rBinToDec(integer)+fracBinToDec(sFraction)<<")10"<<std::endl;
    }
    std:: cout<<"----------------------------------------------------------------"<<std:: endl;
    main();
}