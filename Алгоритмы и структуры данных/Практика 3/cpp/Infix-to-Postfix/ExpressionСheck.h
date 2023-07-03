#ifndef EXPRESSIONCHECK_H
#define EXPRESSIONCHECK_H
#include <string>

int cheñkMaxDeep(const std::string& text);

bool checkBalanceBrackets(const std::string& text, const int maxDeep);

bool getPostfixFromInfix(const std::string& infix, std::string& postfix, const size_t stackSize);

int mult(int a, int b);

int sum(int a, int b);

int evaluatePostfix(const std::string& infix, const size_t stackSize);

#endif