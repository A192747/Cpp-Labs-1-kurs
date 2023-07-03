#include "Point.hpp"
#include "Check.hpp"
#include <iostream>
#include <string>

std::istream& operator >> (std::istream& in, Polygon& data)
{
	std::string str = "";
	std::getline(in, str);
    while (!checkStr(str) and !in.eof())
    {
        std::getline(in, str);
    }
    data.points.clear();
	if(checkStr(str))
	{
        size_t i = 0;
        size_t count = 0;
        std::string numberStr = "";
        while ((str[i] != ' ') and (i != str.size()))
        {
            numberStr += str[i];
            i++;
        }
        i++;
        count = std::stoll(numberStr, nullptr, 10);
        Point point;
        
        for (size_t k = 0; k < count; k++)
        {
            numberStr = "";
            point.x = 0;
            point.y = 0;
            if (str[i] == '(')
            {
                i++;
                while (str[i] != ';')
                {
                    numberStr += str[i];
                    i++;
                }
                point.x = std::stoll(numberStr, nullptr, 10);
                i++;
                numberStr = "";
                while (str[i] != ')')
                {
                    numberStr += str[i];
                    i++;
                }
                point.y = std::stoll(numberStr, nullptr, 10);
                i += 2;
            }
            data.points.push_back(point);
        }

	}
    else
    {
        if (!checkInStream(in))
        {
            return in;
        }
    }
	return in;
}

std::ostream& operator << (std::ostream& out, const Polygon& data)
{
    if (!checkOfStream(out))
    {
        return out;
    }
    int count = 0;
    for (auto it = data.points.begin(); it != data.points.end(); ++it)
    {
        count++;
        out << count << ": " << it->x << " " << it->y << "\n";
    }
    out << "\n";
    return out;
}
