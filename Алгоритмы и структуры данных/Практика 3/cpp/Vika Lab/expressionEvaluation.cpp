#include <iostream>
#include <string>
#include <limits>
#include "expressionEvaluation.h"
#include "ExpressionCheck.h"
#include "queue.h"
#include "stack.h"

std::string  convertToPostfix(const std::string& line)
{
  voronova::Stack <char> stack;
  voronova::Queue <char> queue;
  char item = ' ';

  for (long unsigned int i = 0; i < line.length(); ++i) {
    try {
      switch (voronova::getCategory(line[i])) {
      case 0:
        throw std::logic_error("Error: Arithmetic expression specified incorrectly");
      case 1:
        queue.push(line[i]);
        break;
      case 2:
        stack.push(line[i]);
        break;
      case 3:
        item = ' ';
        while (!stack.isEmpty()) {
          item = stack.pop();
          if (item != '(') {
            queue.push(item);
          } else {
            break;
          }
        }
        if (item != '(') {
          throw std::logic_error("Error: Arithmetic expression specified incorrectly");
        }
        break;
      case 4:
        switch (line[i]) {
        case '+':
          while (!stack.isEmpty()) {
            item = stack.pop();
            if ((item != '(')
             && (item != ')')
             && (item != '*')
             && (item != '/')
             && (item != '%')) {
              queue.push(item);
            } else {
              stack.push(item);
              break;
            }
          }
          stack.push(line[i]);
          break;
        case '-':
          while (!stack.isEmpty()) {
            item = stack.pop();
            if ((item != '(')
             && (item != ')')
             && (item != '*')
             && (item != '/')
             && (item != '%')) {
              queue.push(item);
            } else {
              stack.push(item);
              break;
            }
          }
          stack.push(line[i]);
          break;
        case '*':
          while (!stack.isEmpty()) {
            item = stack.pop();
            if ((item != '(')
             && (item != ')')) {
              queue.push(item);
            } else {
              stack.push(item);
              break;
            }
          }
          stack.push(line[i]);
          break;
        case '/':
          while (!stack.isEmpty()) {
            item = stack.pop();
            if ((item != '(')
             && (item != ')')
             && (item != '*')) {
              queue.push(item);
            } else {
              stack.push(item);
              break;
            }
          }
          stack.push(line[i]);
          break;
        case '%':
          while (!stack.isEmpty()) {
            item = stack.pop();
            if ((item != '(')
             && (item != ')')
             && (item != '*')
             && (item != '/')) {
              queue.push(item);
            } else {
              stack.push(item);
              break;
            }
          }
          stack.push(line[i]);
          break;
        }
        break;
      case 5:
        queue.push(line[i]);
        break;
      }
    }
    catch (const std::exception& e) {
      throw e;
    }
  }

  while (!stack.isEmpty()) {
    try {
      item = stack.pop();
      if (item == '(' || item == ')') {
        throw std::logic_error("Error: Arithmetic expression specified incorrectly");
      }
      queue.push(item);
    }
    catch (const std::exception& e) {
      throw e;
    }
  }
  std::string line2 = "";
  while (!queue.isEmpty()) {
    try {
      line2 += queue.pop();
    }
    catch (const std::exception& e) {
      throw e;
    }
  }
  return line2;
}

long long sum (long long a, long long b)
{
  if (a > 0 && b > 0) {
    const long long max_int = std::numeric_limits< long long >::max();
    if (max_int - a < b) {
      throw std::overflow_error("Error: Overflow");
    }
   }
   if (a < 0 && b < 0) {
     const long long min_int = std::numeric_limits< long long >::min();
     if (min_int - a > b) {
       throw std::overflow_error("Error: Overflow");
     }
   }
  return a + b;
}

long long mult(long long a, long long b)
{
  if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
    const long long max_int = std::numeric_limits< long long >::max();
    if (a > max_int / b)
    {
      throw std::overflow_error("Error: Overflow");
    }
  } else if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
      const long long min_int = std::numeric_limits< long long >::min();
      if (a < min_int / b) {
        throw std::overflow_error("Error: Overflow");
      }
  }
  return a * b;
}


long long voronova::solveExpression(const std::string& line)
{
  std::string linePostfix = "";
  try {
    linePostfix = convertToPostfix(line);
  }
  catch (const std::exception& e) {
    throw e;
  }

  voronova::Stack <long long> stack;
  std::string lineNumber = "";
  long long result = 0;
  long long operand1 = 0;
  long long operand2 = 0;
  for (long unsigned int i = 0; i < linePostfix.length(); ++i) {
    if (voronova::getCategory(linePostfix[i]) == 5) {
      lineNumber += linePostfix[i];
    }
    if (voronova::getCategory(linePostfix[i]) == 4) {
      if ((i != 0) &&
          (voronova::getCategory(linePostfix[i - 1]) == 5)) {
        try {
          result = std::stoll(lineNumber, nullptr, 10);
          stack.push(result);
        }
        catch (const std::exception& e) {
          throw e;
        }
      }
      lineNumber = "";
      try {
        switch (linePostfix[i]) {
        case '+':
          operand1 = stack.pop();
          operand2 = stack.pop();
          result = sum(operand1, operand2);
          stack.push(result);
          break;
        case '-':

          operand1 = stack.pop();
          operand2 = stack.pop();
          result = operand2 - operand1;
          stack.push(result);
          break;
        case '*':
          operand1 = stack.pop();
          operand2 = stack.pop();
          result = mult(operand2, operand1);
          stack.push(result);
          break;
        case '/':
          operand1 = stack.pop();
          operand2 = stack.pop();
          result = operand2 / operand1;
          stack.push(result);
          break;
        case '%':
          operand1 = stack.pop();
          operand2 = stack.pop();
          if (operand2 < 0) {
            result = operand2 + operand1 * (-1 * operand2 / operand1 + 1);
          } else {
            result = operand2 % operand1;
          }
          stack.push(result);
          break;
        }
      }
      catch (const std::exception& e) {
        throw e;
      }
    }
    if (voronova::getCategory(linePostfix[i]) == 1) {
      if ((i != 0) &&
          (voronova::getCategory(linePostfix[i - 1]) == 5)) {
        try {
          result = std::stoll(lineNumber, nullptr, 10);
          stack.push(result);
        }
        catch (const std::exception& e) {
          throw e;
        }
        lineNumber = "";
      }
    }
  }
  try {
    if (!stack.isEmpty()) {
      result = stack.pop();
    } else {
      result = std::stoll(lineNumber, nullptr, 10);
    }
  }
  catch (const std::exception& e) {
    throw e;
  }
  return result;
}
