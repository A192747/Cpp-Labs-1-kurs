#include <iostream>
#include <fstream>
#include <iomanip>
#include "Element.hpp"
#include "Functions.hpp"


int main(int argc, char* argv[])
{
    std::ifstream input;
    if (argc == 2)
    {
        input.open(argv[1]);
    }
    else
    {
        std::cerr << "<INVALID FILENAME>" << std::endl;
        return 1;
    }
    std::istream_iterator< Element > inputStart(input);
    std::istream_iterator< Element > inputEnd;
    std::vector< Element > vector;
    while (!input.eof())
    {
        input.clear();
        std::copy(inputStart, inputEnd, std::back_inserter(vector));
    }
    input.close();
    outInfo(std::cout);
    while (!std::cin.eof())
    {
        
        std::cin.clear();
        try
        {
            coutResult(std::cin, vector, std::cout);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what();
        }
    }
    return 0;
}
