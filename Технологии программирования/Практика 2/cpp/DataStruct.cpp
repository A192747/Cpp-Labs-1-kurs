#include <iostream>
#include <string>
#include "DataStruct.hpp"
#include "Check.hpp"

std::istream& operator >> (std::istream& in, DataStruct& data)
{
    DataStruct input_data;
    std::string str = "";
    std::string subStr = "";
    std::string key1 = "";
    std::string key2 = "";
    std::string key3 = "";
    std::string key2N = "";
    std::string key2D = "";
    std::string acronymStr = "";
    int i = 0;
    int j = 0;
    int count = 0;
    std::getline(in, str);
    while (!checkStr(str) and !in.eof())
    {
        std::getline(in, str);
    }
        
    if (checkStr(str))
    {
        for (size_t k = 0; k < 3; k++)
        {
            while (!((str[i] >= '1') and (str[i] <= '3')))
            {
                if ((str[i] != '(') and !((str[i] >= '1') and (str[i] <= '3')))
                    subStr = subStr + str[i];
                i++;
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
                    }
                    for (size_t h = 0; h < key1.size(); h++)
                    {
                        if (!((key1[h] >= '0') and (key1[h] <= '9')))
                            acronymStr += key1[h];
                    }
                    data.key1 = std::stoll(key1, nullptr, 10);
                    data.acronym = acronymStr;
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
                    }
                    j += 4;
                    while (key2[j] != ':')
                    {
                        key2N += key2[j];
                        j++;
                    }
                    j += 3;
                    while (key2[j] != ':')
                    {
                        key2D += key2[j];
                        j++;
                    }
                    data.key2 = std::make_pair(std::stoll(key2N, nullptr, 10), std::stoll(key2D, nullptr, 10));
                    break;
                case '3':
                    i += 2;
                    while (str[i] != ':')
                    {
                        key3 = key3 + str[i];
                        i++;
                    }
                    data.key3 = key3;
                    break;
                }
            }
            else
            {
                k = 3;
            }
            subStr = "";
            key1 = "";
            key2 = "";
            key3 = "";
            key2N = "";
            key2D = "";
            acronymStr = "";
        }

    }
    else
    {
        if (!checkInStream(in))
        {
            return in;
        }
    }
   /* data = input_data;*/
    return in;
}

std::ostream& operator << (std::ostream& out, const DataStruct& data)
{
    if (!checkOfStream(out))
    {
        return out;
    }
    out << "(:key1 " << data.key1 << data.acronym << ":key2 (:N " << data.key2.first << ":D " << data.key2.second << ":):key3 " << data.key3 << ":)";
    return out;
}

bool comparator(const DataStruct& lhs, const DataStruct& rhs) 
{
    if (lhs.key1 != rhs.key1)
    {
        return lhs.key1 < rhs.key1;
    }
    else if (lhs.key2 != rhs.key2)
    {
        return lhs.key2 < rhs.key2;
    }
    else
    {
        return lhs.key3.size() < rhs.key3.size();
    }
}
