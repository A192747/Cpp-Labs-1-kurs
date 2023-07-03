#include "ExpressionÑheck.h"
#include "ExpressionEqual.h"
#include "Stack.h"
#include <string>
#include <limits>
#include "queue.h"


int cheñkMaxDeep(const std::string& text)
{
	int maxDeep = 0;
	for (int i = 0; i < text.size(); i++)
	{
		if ((text[i] == '(') or (text[i] == '[') or (text[i] == '{'))
		{
			maxDeep++;
		}
	}
	return maxDeep;
}

bool checkBalanceBrackets(const std::string& text, const int maxDeep)
{
	//text - àíàëèçèðóåìûé òåêñò, ñîäåðæàùèé ñêîáêè
	//maxDeep - ìàêñèìàëüíî âîçìîæíûé óðîâåíü âëîæåííîñòè ñêîáîê

	std::string str = "";
	for (int i = 0; i < text.size(); i++)
	{
		if ((text[i] == '(') or (text[i] == ')') or (text[i] == '[') or (text[i] == ']') or (text[i] == '{') or (text[i] == '}'))
		{
			str = str + text[i];
		}
	}
    if (!str.size())
        return 1;
	StackArray <char> stk(str.size());
	int count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i] == '(') or (str[i] == '[') or (str[i] == '{'))
		{
			stk.push(str[i]);
			count++;
		}
		else
		{
			if ((str[i] == ')'))
			{
                if (!stk.isEmpty())
                {
                    if (stk.top() == '(')
                        stk.pop();
                    else
                        break;
                }
                else
                    return 0;
			}
			else
			{
                if (!stk.isEmpty())
                {
                    if (str[i] == ']')
                    {
                        if (stk.top() == '[')
                            stk.pop();
                        else
                            break;
                    }
                    else
                    {
                        if (!stk.isEmpty())
                        {
                            if (str[i] == '}')
                            {
                                if (stk.top() == '{')
                                    stk.pop();
                                else
                                    break;
                            }
                        }
                        else
                            return 0;
                    }
                }
                else
                    return 0;
			}
		}

	}
    if (maxDeep != count)
        return 0;
	if (stk.isEmpty())
		return 1;
	else
		return 0;
}

bool getPostfixFromInfix(const std::string& infix, std::string& postfix, const size_t stackSize)
{
    StackArray <char> stack(stackSize);
    Queue <char> queue;
    char item = ' ';
    if(!checkBalanceBrackets(infix, cheñkMaxDeep(infix)))
        return 0;
    for (long unsigned int i = 0; i < infix.length(); ++i) 
    {
        try {
            switch (getCategory(infix[i])) 
            {
            case 0:
                return 0;
            case 1:
                queue.push(infix[i]);
                break;
            case 2:
                stack.push(infix[i]);
                break;
            case 3:
                item = ' ';
                while (!stack.isEmpty()) 
                {
                    item = stack.pop();
                    if (item != '(') {
                        queue.push(item);
                    }
                    else {
                        break;
                    }
                }
                if (item != '(') {
                    return 0;
                }
                break;
            case 4:
                switch (infix[i]) {
                case '+':
                    while (!stack.isEmpty()) 
                    {
                        item = stack.pop();
                        if ((item != '(') && (item != ')') && (item != '*') && (item != '/') && (item != '%')) 
                        {
                            queue.push(item);
                        }
                        else {
                            stack.push(item);
                            break;
                        }
                    }
                    stack.push(infix[i]);
                    break;
                case '-':
                    while (!stack.isEmpty()) 
                    {
                        item = stack.pop();
                        if ((item != '(') && (item != ')') && (item != '*') && (item != '/') && (item != '%')) 
                        {
                            queue.push(item);
                        }
                        else {
                            stack.push(item);
                            break;
                        }
                    }
                    stack.push(infix[i]);
                    break;
                case '*':
                    while (!stack.isEmpty()) 
                    {
                        item = stack.pop();
                        if ((item != '(')
                            && (item != ')')) 
                        {
                            queue.push(item);
                        }
                        else 
                        {
                            stack.push(item);
                            break;
                        }
                    }
                    stack.push(infix[i]);
                    break;
                case '/':
                    while (!stack.isEmpty()) 
                    {
                        item = stack.pop();
                        if ((item != '(') && (item != ')') && (item != '*')) 
                        {
                            queue.push(item);
                        }
                        else 
                        {
                            stack.push(item);
                            break;
                        }
                    }
                    stack.push(infix[i]);
                    break;
                case '%':
                    while (!stack.isEmpty()) 
                    {
                        item = stack.pop();
                        if ((item != '(') && (item != ')') && (item != '*') && (item != '/')) 
                        {
                            queue.push(item);
                        }
                        else 
                        {
                            stack.push(item);
                            break;
                        }
                    }
                    stack.push(infix[i]);
                    break;
                }
                break;
            case 5:
                queue.push(infix[i]);
                break;
            }
        }
        catch (const std::exception& e) {
            return 0;
        }
    }

    while (!stack.isEmpty()) 
    {
        item = stack.pop();
        if (item == '(' || item == ')') {
            return 0;
        }
        queue.push(item);
    }
    std::string infix2 = "";
    while (!queue.isEmpty()) 
    {
        try 
        {
            infix2 += queue.pop();
        }
        catch (const std::exception& e) {
            return 0;
        }
    }
    postfix = infix2;
}

int sum(int a, int b)
{
    if (a > 0 && b > 0) {
        const int max_int = INT_MAX;
        if (max_int - a < b) {
            throw std::overflow_error("Error: Overflow");
        }
    }
    if (a < 0 && b < 0) {
        const int min_int = INT_MIN;
        if (min_int - a > b) {
            throw std::overflow_error("Error: Overflow");
        }
    }
    return a + b;
}

int mult(int a, int b)
{
    if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
        const int max_int = INT_MAX;
        if (a > max_int / b)
        {
            throw std::overflow_error("Error: Overflow");
        }
    }
    else if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
        const int min_int = INT_MIN;
        if (a < min_int / b) {
            throw std::overflow_error("Error: Overflow");
        }
    }
    return a * b;
}

int evaluatePostfix(const std::string& infix, const size_t stackSize)
{
    std::string infixPostfix = "";
    try 
    {
        getPostfixFromInfix(infix, infixPostfix, stackSize);
    }
    catch (const std::exception& e) 
    {
        throw e;
    }

    StackArray <int> stack(stackSize);
    std::string infixNumber = "";
    int result = 0;
    int operand1 = 0;
    int operand2 = 0;
    for (unsigned int i = 0; i < infixPostfix.size(); ++i) 
    {
        if (getCategory(infixPostfix[i]) == 5) 
        {
            infixNumber += infixPostfix[i];
        }
        if (getCategory(infixPostfix[i]) == 4) 
        {
            if ((i != 0) && (getCategory(infixPostfix[i - 1]) == 5)) 
            {
                try 
                {
                    result = std::stoll(infixNumber, nullptr, 10);
                    stack.push(result);
                }
                catch (const std::exception& e) {
                    throw e;
                }
            }
            infixNumber = "";
            try 
            {
                switch (infixPostfix[i]) 
                {
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
                    }
                    else {
                        result = operand2 % operand1;
                    }
                    stack.push(result);
                    break;
                }
            }
            catch (const std::exception& e) 
            {
                throw e;
            }
        }
        if (getCategory(infixPostfix[i]) == 1) 
        {
            if ((i != 0) && (getCategory(infixPostfix[i - 1]) == 5)) 
            {
                try 
                {
                    result = std::stoll(infixNumber, nullptr, 10);
                    stack.push(result);
                }
                catch (const std::exception& e) 
                {
                    throw e;
                }
                infixNumber = "";
            }
        }
    }
    try 
    {
        if (!stack.isEmpty()) 
        {
            result = stack.pop();
        }
        else 
        {
            result = std::stoll(infixNumber, nullptr, 10);
        }
    }
    catch (const std::exception& e) 
    {
        throw e;
    }
    return result;
}
