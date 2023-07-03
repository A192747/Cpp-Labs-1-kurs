#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "Point.hpp"
#include "Functions.hpp"
#include <exception> 

/*
* Variant 13 
    RECTS SAME
    SAME <Polygon> Команда подсчитывает количество фигур, совместимых наложением (без поворотов) с указанной в параметрах. Например, для фигур
    4 (0;0) (1;0) (1;1) (0;1)
    3 (0;0) (1;1) (0;1)
    4 (1;1) (2;1) (2;2) (1;2)
    Ожидается следующий результат:
    SAME 4 (-1;-1) (-1;0) (0;0) (0;-1)
    2
    SAME 3 (10;10) (11;11) (10;11)
    1
    SAME 3 (10;10) (10;11) (11;10)
    0
    • RECTS Команда подсчитывает количество прямоугольников в коллекции фигур. Например, для
    фигур
    4 (0;0) (1;0) (1;1) (0;1)
    3 (0;0) (1;1) (0;1)
    4 (1;1) (0;2) (1;3) (2;2)
    4 (-2;1) (2;3) (3;1) (-1;-1)
    Ожидается следующий результат:
    RECTS
    3

*/

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
    std::istream_iterator< Polygon > inputStart(input);
    std::istream_iterator< Polygon > inputEnd;
    std::vector< Polygon > vector;
    while (!input.eof())
    {
        input.clear();
        std::copy(inputStart, inputEnd, std::back_inserter(vector));
    }
    input.close();
    while (!std::cin.eof())
    {
        std::cin.clear();
        coutResult(std::cin, vector);  
    }
    return 0;
}
