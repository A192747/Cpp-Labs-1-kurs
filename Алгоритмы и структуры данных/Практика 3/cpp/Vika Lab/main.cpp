#include <iostream>
#include <fstream>
#include <stdexcept>
#include "expressionEvaluation.h"
#include "stack.h"

int main(int argc, char* argv[])
{
  std::ifstream input;
  if (argc > 1) {
    input.open(argv[1]);
    if (!input.is_open()) {
      std::cerr << "Error: unable to open file" << std::endl;
      return 1;
    }
  }
  std::istream& in = argc > 1 ? input : std::cin;
  std::string line = "";
  voronova::Stack <long long> stack;
  try {
    while (std::getline(in, line)) {
        if (line != "") {
            stack.push(voronova::solveExpression(line));
      }
    }
    if (!stack.isEmpty()) {
      std::cout << stack.pop();
    }
    while (!stack.isEmpty()) {
      std::cout << ' ' << stack.pop();
    }
    std::cout << '\n';
    input.close();
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
