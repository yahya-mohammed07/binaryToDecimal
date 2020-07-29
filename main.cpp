#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
//*
int rBinToDec(unsigned long& real) //* takes the real numbers form the binary
{
    long long i = 0;
    unsigned long long result = 0;
    //
    while(real != 0)
    {
        result += (real % 10) * std::pow(2,i);
        if(real % 10 > 1 || real % 10 < 0)  //* to check if the number is bin or not
        {
            throw std::domain_error("not binary system!"); //* throw run-time error if the the number is not binary
        }
        real  = real / 10;
        i++;
    }
    return result;
}
//*
double fracBinToDec(unsigned long& frac) //* takes the fraction from the bin number
{
    long long i = -1;
    float result = 0;
    //
    while(frac != 0)
    {
        result += (frac % 10) * std::pow(2,i);
        if(frac % 10 > 1 || frac % 10 < 0)  //* to check if the number is bin or not
        {
            throw std::domain_error("not binary system!");
        }
        frac  = frac / 10;
        i--;
    }
    std::string temp = std::to_string(result);
    std::string theFraction = "";
    //*
    for (int i=temp.length()-1 ; i>0;i--)
    {
        if(temp[i]== '.') break;
        theFraction += temp[i];
    }
    std::reverse(theFraction.begin(),theFraction.end());
    result = std::stol (theFraction);
    return result;
}
int main()
{
    std:: cout<<"----------------------------------------------------------------"<<std:: endl;
    std:: cout<<"- enter a binary number: "<<std:: flush;
    std::string input = "";
    std::getline(std::cin, input);
    std::string sReal = "";
    std::string sFraction = "";
    bool check = false;
    //*
    for (int i: input)
    {
        if(i == '.') 
        {
            check = true; 
            break;
        }
        sReal += i;
    }
    for (int i = input.length()-1; i>0;i--)
    {
        if (input[i] == '.') break;
        sFraction += input[i];
    }
    //*
    if(check == false)
    {
        unsigned long  rDecimal = std::stoull(input);
        std::cout<<"- result in Decimal system: ("<<rBinToDec(rDecimal)<<")10"<<std::endl;
    }
    else
    {
        unsigned long  real = std::stoul(sReal);
        unsigned long  frac = std::stoul(sFraction);
        std::cout<<"- the result in Decimal system: ("<<rBinToDec(real)<<"."<<fracBinToDec(frac)<<")10"<<std::endl;
    }
    std:: cout<<"----------------------------------------------------------------"<<std:: endl;
    std::cin.get();
}