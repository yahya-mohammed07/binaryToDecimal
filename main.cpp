#include <iomanip>
#include <algorithm>
#include <chrono>

#include "binToDec.hpp"
//
auto main() -> int
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
            // to check if the number has decimal point
            check = true;
            break;
        }
        integer += i;
    }
    std::size_t sizeInteger = integer.length();
    // if there is no decimal point
    if(check == false)
    {
        out("- result in Decimal system: (",intBin(integer, sizeInteger),")10\n");
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
        std::size_t sizeFrac = fraction.length();
        out("- the result in Decimal system: ("
        ,std::setprecision(21),intBin(integer, sizeInteger)+fracBin(fraction, sizeFrac),")10\n");
    }
    out("----------------------------------------------------------------\n");
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration(end - start);
    printf("time: %0.4f ms\n\n", duration.count() * 1000);
}