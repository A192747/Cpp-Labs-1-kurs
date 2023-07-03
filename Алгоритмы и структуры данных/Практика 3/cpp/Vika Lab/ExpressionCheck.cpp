#include "ExpressionCheck.h"

voronova::charCategory voronova::getCategory(char symbol)
{
    if (symbol >= '0' &&
        symbol <= '9') {
        return Number;
    }

    switch (symbol) {
    case ' ':
        return Space;

    case '(':
        return OpenBracket;

    case ')':
        return CloseBracket;

    case '+':
    case '-':
    case '/':
    case '*':
    case '%':
        return Operator;

    default:
        return Null;
    }
}
