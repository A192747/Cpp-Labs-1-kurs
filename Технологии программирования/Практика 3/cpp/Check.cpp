#include <string>
#include "Check.hpp"
#include <iostream>

bool isNumber(const std::string& str)
{
    bool long_ = 0;
    bool lastNumb = 0;
    size_t number = 0;
    std::string subStr = "";

    if (str[0] == '-')
        number = 1;
    for (size_t i = number; i < str.size(); i++)
    {
        if (!((str[i] >= '0') && (str[i] <= '9')))
            subStr += str[i];
    }
    if (str.size() != 0 && (str[str.size() - 1] >= '0') && (str[str.size() - 1] <= '9'))
        lastNumb = 1;
    if ((str.size() != 0 && str.find("ull") != std::string::npos && subStr.find("ull") != std::string::npos && subStr.size() == 3)
       ||(str.find("ll") != std::string::npos && subStr.find("ll") != std::string::npos && subStr.size() == 2)
       ||(str.find("l") != std::string::npos && subStr.find("l") != std::string::npos && subStr.size() == 1)
       ||(str.find("u") != std::string::npos && subStr.find("u") != std::string::npos && subStr.size() == 1)
       ||(str.find("LL") != std::string::npos && subStr.find("LL") != std::string::npos && subStr.size() == 2)
       ||(str.find("L") != std::string::npos && subStr.find("L") != std::string::npos && subStr.size() == 1)
       ||(str.find("Ul") != std::string::npos && subStr.find("Ul") != std::string::npos && subStr.size() == 2)
       ||(str.find("ULL") != std::string::npos && subStr.find("ULL") != std::string::npos && subStr.size() == 3)
       ||(str.find("U") != std::string::npos && subStr.find("U") != std::string::npos && subStr.size() == 1))
    {
        long_ = 1;
    }
    if ((str.size() == 1) && (!number))
        return 1;
    if (str.size() == 0||str[0] == '0')
        return 0;
    if ((lastNumb) && (long_))
        return 0;
    if ((!lastNumb) && (long_))
        return 1;
    if ((subStr.size() == 0))
        return 1;
    if ((!long_) && (subStr.size() == 0))
        return 1;

    return 0;
}

bool checkStr(const std::string& str)
{
    size_t i = 0;
    size_t count = 0;
    std::string numberStr = "";
    while ((str[i] != ' ') && (i != str.size()))
    {
        numberStr += str[i];
        i++;
        if (i == str.size())
            return 0;
    }
    if (!isNumber(numberStr)||numberStr[0] == '-')
        return 0;
    i++;
    count = std::stoll(numberStr, nullptr, 10);
    for (size_t k = 0; k < count; k++)
    {
        numberStr = "";
        if (i >= str.size())
            return 0;
        if (str[i] == '(')
        {
            i++;
            while (str[i] != ';')
            {
                numberStr += str[i];
                i++;
                if (i == str.size())
                    return 0;
            }
            if (!isNumber(numberStr))
                return 0;
            i++;
            numberStr = "";
            while (str[i] != ')')
            {
                numberStr += str[i];
                i++;
                if (i == str.size())
                    return 0;
            }
            if (!isNumber(numberStr))
                return 0;
            i += 2;
        }
        else
            return 0;
    }
    return 1;
}

bool checkOfStream(std::ostream& out)
{
    std::ostream::sentry sentry(out);
    if (!sentry)
    {
        return false;
    }
    return true;
}

bool checkInStream(std::istream& in)
{
    std::istream::sentry sentry(in);
    if (!sentry)
    {
        return false;
    }
    return true;
}
