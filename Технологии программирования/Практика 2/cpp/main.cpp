#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "DataStruct.hpp"

/* 
*  Вариант 13
*  key1         key2
*  SLL LIT      RAT LSP
* 
* В качестве входных данных используйте ввод из файла.
* Для сортировки используйте алгоритм std::sort() с
* собственным компаратором.
* 
* 
* 
*/


int main()
{
    std::ifstream file("input.txt");
    std::ofstream ofile ("output.txt");
    std::istream_iterator <DataStruct> input(file);
    std::istream_iterator <DataStruct> inputEnd;

    std::vector <DataStruct> vector;
    while (!file.eof())
    {
        std::copy(input, inputEnd, std::back_inserter(vector));
    }
    file.close();
    std::sort(vector.begin(), vector.end(), comparator);
    std::copy(vector.begin(), vector.end(), std::ostream_iterator <DataStruct> (ofile, "\n"));
    ofile.close();
    return 0;
}
