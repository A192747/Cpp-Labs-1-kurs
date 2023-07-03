#ifndef EXPRESSIONCHECK_H
#define EXPRESSIONCHECK_H

namespace voronova
{
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
}

#endif
