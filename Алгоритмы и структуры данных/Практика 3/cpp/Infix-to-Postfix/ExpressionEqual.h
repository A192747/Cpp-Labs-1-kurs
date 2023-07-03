#ifndef EXPRESSIONEQUAL_H
#define EXPRESSIONEQUAL_H


enum charCategory
{
    Null,
    Space,
    OpenBracket,
    CloseBracket,
    Operator,
    Number
};
charCategory getCategory(char symbol);

#endif
