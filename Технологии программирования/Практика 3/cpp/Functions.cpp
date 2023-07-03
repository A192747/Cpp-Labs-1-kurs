#include "Functions.hpp"
#include "Point.hpp"
#include "Check.hpp"
#include <string>
#include <iostream>
#include <exception> 
#include <algorithm> 
#include <iomanip> 
#include <cmath> 
#include <limits>  

static size_t NUMB = 0;
std::vector< Point > VECTOR;

size_t getCategory(const std::string& str)
{
    size_t i = 0;
    std::string comandStr = "";
    std::string argumentStr = "";
    while (str[i] != ' ' && i != str.size())
    {
        comandStr += str[i];
        i++;
    }
    if(i != str.size())
        i++;
    while (i != str.size())
    {
        argumentStr += str[i];
        i++;
    }
    if (comandStr == "AREA")
    {
        if (argumentStr == "EVEN")
        {
            return 1;
        }
        if (argumentStr == "ODD")
        {
            return 2;
        }
        if (argumentStr == "MEAN")
        {
            return 3;
        }
        if (isNumber(argumentStr) && (argumentStr[0] != '-'))
        {
            NUMB = std::stoll(argumentStr, nullptr, 10);
            return 4;
        }
    }
    if (comandStr == "MAX")
    {
        if (argumentStr == "AREA")
        {
            return 5;
        }
        if (argumentStr == "VERTEXES")
        {
            return 6;
        }
    }
    if (comandStr == "MIN")
    {
        if (argumentStr == "AREA")
        {
            return 7;
        }
        if (argumentStr == "VERTEXES")
        {
            return 8;
        }
    }
    if (comandStr == "COUNT")
    {
        if (argumentStr == "EVEN")
        {
            return 9;
        }
        if (argumentStr == "ODD")
        {
            return 10;
        }
        if (isNumber(argumentStr) && (argumentStr[0] != '-'))
        {
            NUMB = std::stoll(argumentStr, nullptr, 10);
            return 11;
        }
    }
    if (comandStr == "RECTS")
    {
        return 12;
    }
    if (comandStr == "SAME")
    {
        if (checkStr(argumentStr))
        {
            VECTOR.clear();
            size_t k = 0;
            size_t count = 0;
            std::string numberStr = "";
            while ((argumentStr[k] != ' ') && (k != argumentStr.size()))
            {
                numberStr += argumentStr[k];
                k++;
            }
            k++;
            count = std::stoll(numberStr, nullptr, 10);
            Point point;

            for (size_t j = 0; j < count; j++)
            {
                numberStr = "";
                point.x = 0;
                point.y = 0;
                if (argumentStr[k] == '(')
                {
                    k++;
                    while (argumentStr[k] != ';')
                    {
                        numberStr += argumentStr[k];
                        k++;
                    }
                    point.x = std::stoll(numberStr, nullptr, 10);
                    k++;
                    numberStr = "";
                    while (argumentStr[k] != ')')
                    {
                        numberStr += argumentStr[k];
                        k++;
                    }
                    point.y = std::stoll(numberStr, nullptr, 10);
                    k += 2;
                }
                VECTOR.push_back(point);
                
            }
            return 13;
        }
    }
    throw std::logic_error("<INVALID COMM&&>\n");
}

void area(size_t category, const std::vector<Polygon>& vector)
{
    if (category == 1)
    {
        double area = 0;
        int number = 0;
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            if (it->points.size() % 2 != 0)
            {
                //sum
                for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
                {
                    number += (element - 1)->x * element->y;
                }
                number += it->points.begin()->y * (it->points.end() - 1)->x;
                //rasn
                for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
                {
                    number -= (element - 1)->y * element->x;
                }
                number -= it->points.begin()->x * (it->points.end() - 1)->y;
                area += 0.5 * std::abs(number);
            }
            number = 0;
        }
        std::cout << std::fixed << std::setprecision(1) << area << "\n";
    }
    if (category == 2)
    {
        double area = 0;
        int number = 0;
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            if (it->points.size() % 2 == 0)
            {
                //sum
                for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
                {
                    number += (element - 1)->x * element->y;
                }
                number += it->points.begin()->y * (it->points.end() - 1)->x;
                //rasn
                for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
                {
                    number -= (element - 1)->y * element->x;
                }
                number -= it->points.begin()->x * (it->points.end() - 1)->y;
                area += 0.5 * std::abs(number);
            }
            number = 0;
        }
        std::cout << std::fixed << std::setprecision(1) << area << "\n";
    }
    if (category == 3)
    {
        double area = 0;
        int number = 0;
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            if (it->points.size() % 2 == 0)
            {
                //sum
                for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
                {
                    number += (element - 1)->x * element->y;
                }
                number += it->points.begin()->y * (it->points.end() - 1)->x;
                //rasn
                for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
                {
                    number -= (element - 1)->y * element->x;
                }
                number -= it->points.begin()->x * (it->points.end() - 1)->y;
                area += 0.5 * std::abs(number);
            }
            number = 0;
        }
        double area1 = 0;
        int number1 = 0;
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            if (it->points.size() % 2 != 0)
            {
                //sum
                for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
                {
                    number1 += (element - 1)->x * element->y;
                }
                number1 += it->points.begin()->y * (it->points.end() - 1)->x;
                //rasn
                for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
                {
                    number1 -= (element - 1)->y * element->x;
                }
                number1 -= it->points.begin()->x * (it->points.end() - 1)->y;
                area1 += 0.5 * std::abs(number1);
            }
            number1 = 0;
        }
        area += area1;
        area = area / vector.size();
        std::cout << std::fixed << std::setprecision(1) << area << "\n";
    }
    if (category == 4)
    {
        double area = 0;
        int number = 0;
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            if (it->points.size() == NUMB)
            {
                //sum
                for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
                {
                    number += (element - 1)->x * element->y;
                }
                number += it->points.begin()->y * (it->points.end() - 1)->x;
                //rasn
                for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
                {
                    number -= (element - 1)->y * element->x;
                }
                number -= it->points.begin()->x * (it->points.end() - 1)->y;
                area += 0.5 * std::abs(number);
            }
            number = 0;
        }
        std::cout << std::fixed << std::setprecision(1) << area << "\n";
    }
    if (category == 5)
    {
        double area = 0;
        double areaMax = 0;
        int number = 0;
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            //sum
            for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
            {
                number += (element - 1)->x * element->y;
            }
            number += it->points.begin()->y * (it->points.end() - 1)->x;
            //rasn
            for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
            {
                number -= (element - 1)->y * element->x;
            }
            number -= it->points.begin()->x * (it->points.end() - 1)->y;
            area = 0.5 * std::abs(number);
            number = 0;
            areaMax = std::max(area, areaMax);
        }
        std::cout << std::fixed << std::setprecision(1) << areaMax << "\n";
    }
    if (category == 7)
    {
        double area = 0;
        double areaMin = std::numeric_limits<double>::max();
        int number = 0;
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            //sum
            for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
            {
                number += (element - 1)->x * element->y;
            }
            number += it->points.begin()->y * (it->points.end() - 1)->x;
            //rasn
            for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
            {
                number -= (element - 1)->y * element->x;
            }
            number -= it->points.begin()->x * (it->points.end() - 1)->y;
            area = 0.5 * std::abs(number);
            number = 0;
            areaMin = std::min(area, areaMin);
        }
        std::cout << std::fixed << std::setprecision(1) << areaMin << "\n";
    }
}

void vertexes(size_t category, const std::vector<Polygon>& vector)
{
    if (category == 6)
    {
        size_t maxNumber = 0;
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            maxNumber = std::max(it->points.size(), maxNumber);
        }
        std::cout << maxNumber << "\n";
    }
    if (category == 8)
    {
        size_t minNumber = std::numeric_limits<size_t>::max();
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            minNumber = std::min(it->points.size(), minNumber);
        }
        std::cout << minNumber << "\n";
    }
}

void count(size_t category, const std::vector<Polygon>& vector)
{
    if (category == 9)
    {
        size_t count = 0;
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            if (it->points.size() % 2 != 0)
                count++;
        }
        std::cout << count << "\n";
    }
    if (category == 10)
    {
        size_t count = 0;
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            if (it->points.size() % 2 == 0)
                count++;
        }
        std::cout << count << "\n";
    }
    if (category == 11)
    {
        size_t count = 0;
        for (auto it = vector.begin(); it != vector.end(); ++it)
        {
            if (it->points.size() == NUMB)
                count++;
        }
        std::cout << count << "\n";
    }
}

void rects(const std::vector<Polygon>& vector)
{
    size_t count = 0;
    size_t side0 = 0;
    size_t side1 = 0;
    size_t side2 = 0;
    size_t side3 = 0;
    double diagonal0 = 0;
    double diagonal1 = 0;
    for (auto it = vector.begin(); it != vector.end(); ++it)
    {
        side0 = 0;
        side1 = 0;
        side2 = 0;
        side3 = 0;
        diagonal0 = 0;
        diagonal1 = 0;
        if (it->points.size() == 4)
        {
            side0 = std::sqrt(std::pow(((it->points.begin() + 1)->x - it->points.begin()->x), 2) + std::pow(((it->points.begin() + 1)->y - it->points.begin()->y), 2));
            side1 = std::sqrt(std::pow(((it->points.begin() + 2)->x - (it->points.begin() + 1)->x), 2) + std::pow(((it->points.begin() + 2)->y - (it->points.begin() + 1)->y), 2));
            side2 = std::sqrt(std::pow(((it->points.begin() + 3)->x - (it->points.begin() + 2)->x), 2) + std::pow(((it->points.begin() + 3)->y - (it->points.begin() + 2)->y), 2));
            side3 = std::sqrt(std::pow(((it->points.begin())->x - (it->points.begin() + 3)->x), 2) + std::pow(((it->points.begin())->y - (it->points.begin() + 3)->y), 2));
            diagonal0 = std::sqrt(std::pow(((it->points.begin() + 3)->x - (it->points.begin() + 1)->x), 2) + std::pow(((it->points.begin() + 3)->y - (it->points.begin() + 1)->y), 2));
            diagonal1 = std::sqrt(std::pow(((it->points.begin())->x - (it->points.begin() + 2)->x), 2) + std::pow(((it->points.begin())->y - (it->points.begin() + 2)->y), 2));
            if((diagonal0 == diagonal1) && (side1 == side3) && (side0 == side2))
                count++;
        }
    }
    std::cout << count << "\n";
}

void same(const std::vector<Polygon>& vector)
{
    double areaVect = 0;
    int numberVect = 0;
    size_t count = 0;
    //sum
    for (auto element = (VECTOR.begin() + 1); element != VECTOR.end(); ++element)
    {
        numberVect += (element - 1)->x * element->y;
    }
    numberVect += VECTOR.begin()->y * (VECTOR.end() - 1)->x;
    //rasn
    for (auto element = (VECTOR.begin() + 1); element != VECTOR.end(); ++element)
    {
        numberVect -= (element - 1)->y * element->x;
    }
    numberVect -= VECTOR.begin()->x * (VECTOR.end() - 1)->y;
    areaVect = 0.5 * std::abs(numberVect);
    double area = 0;
    int number = 0;
    for (auto it = vector.begin(); it != vector.end(); ++it)
    {
        //sum
        for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
        {
            number += (element - 1)->x * element->y;
        }
        number += it->points.begin()->y * (it->points.end() - 1)->x;
        //rasn
        for (auto element = (it->points.begin() + 1); element != it->points.end(); ++element)
        {
            number -= (element - 1)->y * element->x;
        }
        number -= it->points.begin()->x * (it->points.end() - 1)->y;
        area = 0.5 * std::abs(number);
        number = 0;
        if (areaVect >= area)
        {
            count++;
        }
    }
    std::cout << count << "\n";
}

void coutResult(std::istream& in, const std::vector<Polygon>& vector)
{
    std::string str;
    std::getline(in, str);
    size_t category = 0;
    try
    {
        category = getCategory(str);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what();
    }

    switch (category)
    {
    case 1:
        area(1, vector);
        break;
    case 2:
        area(2, vector);
        break;
    case 3:
        area(3, vector);
        break;
    case 4:
        area(4, vector);
        break;
    case 5:
        area(5, vector);
        break;
    case 6:
        vertexes(6, vector);
        break;
    case 7:
        area(7, vector);
        break;
    case 8:
        vertexes(8, vector);
        break;
    case 9:
        count(9, vector);
        break;
    case 10:
        count(10, vector);
        break;
    case 11:
        count(11, vector);
        break;
    case 12:
        rects(vector);
        break;
    case 13:
        same(vector);
        break;
    }
}
