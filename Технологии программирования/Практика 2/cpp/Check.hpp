#ifndef CHECK_H
#define CHECK_H

#include <string>
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
        if (!((str[i] >= '0') and (str[i] <= '9')))
            subStr += str[i];
    }
    if ((str[str.size() - 1] >= '0') and (str[str.size() - 1] <= '9'))
        lastNumb = 1;
    if ((str.find("ull") != std::string::npos and subStr.find("ull") != std::string::npos and subStr.size() == 3)
        or (str.find("ll") != std::string::npos and subStr.find("ll") != std::string::npos and subStr.size() == 2)
        or (str.find("l") != std::string::npos and subStr.find("l") != std::string::npos and subStr.size() == 1)
        or (str.find("u") != std::string::npos and subStr.find("u") != std::string::npos and subStr.size() == 1)
        or (str.find("LL") != std::string::npos and subStr.find("LL") != std::string::npos and subStr.size() == 2)
        or (str.find("L") != std::string::npos and subStr.find("L") != std::string::npos and subStr.size() == 1)
        or (str.find("Ul") != std::string::npos and subStr.find("Ul") != std::string::npos and subStr.size() == 2)
        or (str.find("ULL") != std::string::npos and subStr.find("ULL") != std::string::npos and subStr.size() == 3)
        or (str.find("U") != std::string::npos and subStr.find("U") != std::string::npos and subStr.size() == 1))
    {
        long_ = 1;
    }
    if (str[0] == '0')
        return 0;
    if ((lastNumb) and (long_))
        return 0;
    if ((!lastNumb) and (long_))
        return 1;
    if ((subStr.size() == 0))
        return 1;
    if ((!long_) and (subStr.size() == 0))
        return 1;
    return 0;
}

bool checkStr(const std::string& str)
{
    //:keyX (:N -2:D 3:):

    /*
    * (:key1 10ull:key2 ’c’:key3 "Data":)
    * (:key2 ’c’:key1 10ull:key3 "Data":)
    * (:key3 "Data":key2 ’c’:key1 10ull:)
    */

    std::string key1 = ":key1";
    std::string key2 = ":key2";
    std::string key3 = ":key3";
    std::string key4 = "(:N";
    std::string key5 = ":D";
    std::string key2N = "";
    std::string key2D = "";
    int countDots = 0, countOpBrack = 0, countClBrack = 0;
    bool hasN = 0;
    bool hasD = 0;
    int count = 0;
    if ((str[0] == '(') and (str[str.size() - 1] == ')') and (str[str.size() - 2] == ':') and (str[1] == ':'))
    {
        if ((str.find(key5) != std::string::npos) and (str.find(key4) != std::string::npos) and
            (str.find(key1) != std::string::npos) and (str.find(key2) != std::string::npos) and
            (str.find(key3) != std::string::npos))
        {
            for (size_t i = 0; i < str.size(); i++)
            {
                if (str[i] == ':')
                    countDots++;
                if (str[i] == '(')
                    countOpBrack++;
                if (str[i] == ')')
                    countClBrack++;
                if (str[i] == 'N')
                    hasN = 1;
                if ((str[i] == 'D') and (hasN))
                    hasD = 1;
                if ((i >= 2) and (str[i - 2] == 'D') and !((str[i] >= '0') and (str[i] <= '9')))
                    return 0;
            }
            if ((countDots == 7) and (countOpBrack == 2) and (countClBrack == 2) and (hasN) and (hasD))
            {
                std::string subStr = "";
                size_t i = 0;
                size_t j = 0;
                
                for (size_t k = 0; k < 3; k++)
                {
                    key1 = "";
                    key2 = "";
                    key3 = "";
                    subStr = "";
                    while (!((str[i] >= '1') and (str[i] <= '3')))
                    {
                        if ((str[i] != '(') and !((str[i] >= '1') and (str[i] <= '3')))
                            subStr = subStr + str[i];
                        i++;
                        if (i == str.size())
                            return 0;
                    }

                    if (subStr == ":key")
                    {
                        switch (str[i])
                        {
                        case '1':
                            i += 2;
                            while (str[i] != ':')
                            {
                                key1 = key1 + str[i];
                                i++;
                                if (i == str.size())
                                    return 0;
                            }
                            if (!isNumber(key1))
                                return 0;
                            break;
                        case '2':
                            i += 2;
                            while (!((str[i] == ':') and (count == 3)))
                            {
                                // :keyX (:N -2:D 3:):
                                if (str[i] == ':')
                                    count++;
                                key2 = key2 + str[i];
                                i++;
                                if (i == str.size())
                                    return 0;
                            }
                            j += 4;
                            while (key2[j] != ':')
                            {
                                key2N += key2[j];
                                j++;
                                if (j == key2.size())
                                    return 0;
                            }
                            j += 3;
                            while (key2[j] != ':')
                            {
                                key2D += key2[j];
                                j++;
                                if (j == key2.size())
                                    return 0;
                            }
                            if (!isNumber(key2D) or !isNumber(key2N))
                                return 0;
                            break;
                        case '3':
                            i += 2;
                            while (str[i] != ':' and i < str.size())
                            {
                                key3 = key3 + str[i];
                                i++;
                                if (i == str.size())
                                    return 0;
                            }
                            break;
                        }
                    }
                    
                }
                return 1;
            }

        }

    }
    return 0;
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

#endif
