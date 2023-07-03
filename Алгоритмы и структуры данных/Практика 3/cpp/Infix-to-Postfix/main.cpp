#include <iostream>
#include <string>
#include "Stack.h"
#include "Stackflow.h"
#include "ExpressionСheck.h"

int main()
{
    //*******************************************
    /*std::cout << "---===| Test 1 : Error: stack overflow! |===---" << std::endl;
    StackArray <int> St;
    St.push(123);*/
    //*******************************************




    //*******************************************
    /*std::cout << "---===| Test 2 : Error: stack overflow! |===---" << std::endl;
    StackArray <int> St(1);
    St.push(123);
    St.push(111);*/
    //*******************************************



    //*******************************************
    /*std::cout << "---===| Test 3 : Error: stack underflow! |===---" << std::endl;
    StackArray <int> St;
    std::cout << St.pop() << std::endl;*/
    //*******************************************



    //*******************************************
    /*std::cout << "---===| Test 4 : Error: wrong stack size! |===---" << std::endl;
    StackArray <int> St(6.6);*/
    //*******************************************



    //*******************************************
    /*std::cout << "---===| Test 5 : Check balance brackets |===---" << std::endl;
    std::string str0 = "((()))";
    std::string str1 = "((())";
    std::string str2 = "([()))";
    std::string str3 = ")([()])(";

    std::cout << (checkBalanceBrackets(str0, cheсkMaxDeep(str0)) ? "it's OK" : "it's Bad") << std::endl;
    std::cout << (checkBalanceBrackets(str1, cheсkMaxDeep(str1)) ? "it's OK" : "it's Bad") << std::endl;
    std::cout << (checkBalanceBrackets(str2, cheсkMaxDeep(str2)) ? "it's OK" : "it's Bad") << std::endl;
    std::cout << (checkBalanceBrackets(str3, cheсkMaxDeep(str3)) ? "it's OK" : "it's Bad") << std::endl;*/
    //*******************************************



    //*******************************************
    /*std::cout << "---===| Test 6 : Get Postfix From Infix and evaluate Postfix |===---" << std::endl;
    std::string inf = "(3 + 2) * 8";
    std::string post = "";
    std::cout << (getPostfixFromInfix(inf, post, 200) ? post : "it's Bad") << std::endl;
    std::cout << evaluatePostfix(inf, 2) << std::endl << std::endl;


    std::string inf1 = "((3 + 2) * 8)/ 2";
    std::string post1 = "";
    std::cout << (getPostfixFromInfix(inf1, post1, 200) ? post1 : "it's Bad") << std::endl;
    std::cout << evaluatePostfix(inf1, 3) << std::endl;*/
    //*******************************************
}
