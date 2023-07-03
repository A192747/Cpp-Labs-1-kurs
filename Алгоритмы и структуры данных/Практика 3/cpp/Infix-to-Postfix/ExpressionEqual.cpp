#include "ExpressionÑheck.h"
#include "ExpressionEqual.h"

charCategory getCategory(char symbol)
{
    if (symbol >= '0' &&
        symbol <= '9') {
        return Number;
    }

    switch (symbol) {
    case ' ':
        return Space;

    case '(':
    case '[':
    case '{':
        return OpenBracket;

    case ')':
    case ']':
    case '}':
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
