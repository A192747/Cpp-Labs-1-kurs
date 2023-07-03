#include <iostream>
#include <fstream>
#include <iomanip>
#include "ReadAndOut.h"
#include "BinarySearchTree.h"

int main()
{
    std::ifstream input("input.txt");
    BinarySearchTree MyTree;
    std::cout << "********************" << "\n";
    std::cout << "**** Lines read ****" << "\n";
    std::cout << "********************" << "\n";
    readWrite(input, std::cout, MyTree);
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "********************" << "\n";
    std::cout << "*** Table output ***" << "\n";
    std::cout << "********************" << "\n";

    MyTree.putInATable(std::cout);
    input.close();
}
