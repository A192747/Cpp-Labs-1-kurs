#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include "OneElement.h"


//Сортировка поразрядная (по не убыванию), в которой используется ключ, состоящий из букв латинского алфавита.

std::string* randString(const std::size_t& maxStrSize, const std::size_t& maxCount);
bool checkStrArray(const std::string* str, std::size_t size);
std::size_t getMaxSize(std::string const* array, const std::size_t& n);
void countingSort(std::string* array, const std::size_t& size, const std::size_t& place);
void radixsort(std::string* array, const std::size_t& size);
void printArray(const std::string* array, const std::size_t& size);



std::string* randString(const std::size_t& maxStrSize, const std::size_t& maxCount)
{
    srand(unsigned int (time(0)));
    std::string* str = new std::string[maxCount];
    int size = 0;
    for (std::size_t i = 0; i < maxCount; i++)
    {
        str[i] = "";
        size = 1 + rand() % maxStrSize;
        for (std::size_t j = 0; j < size; j++)
        {
            if(rand() % 2) 
                str[i] += char('a' + rand() % ('z' - 'a'));
            else
                str[i] += char('A' + rand() % ('Z' - 'A'));
        }
    }
    return str;
}

bool checkStrArray(const std::string* str, std::size_t size)
{
    for (std::size_t i = 1; i < size; i++)
    {
        if (str[i - 1] > str[i])
        {
            /*std::cout << (str[i - 1] > str[i]) << " " << str[i - 1] << " " << str[i] << std::endl;*/
            return 0;
        }
    }
    return 1;
}

// Function to get the largest element from an array
std::size_t getMaxSize(std::string const * array, const std::size_t & n) {
    std::size_t max = array[0].size();
    for (std::size_t i = 1; i < n; i++)
        if (array[i].size() > max)
            max = array[i].size();
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(std::string* array, const std::size_t& size, const std::size_t & place) {
    const std::size_t max = 52;
    std::string* output = new std::string [size];
    std::size_t* count = new std::size_t[max];
    int str_size = 0;
    std::size_t countSame = 0;
    int maxSize = getMaxSize(array, size);


    for (std::size_t i = 0; i < max; ++i)
    {
        count[i] = 0;
       
    }
    


    char letter;

    for (std::size_t i = 0; i < size; i++)
    {
        if (array[i].size() <= maxSize - place)
            str_size = array[i].size() - 1;
        else
        {
            str_size = array[i].size() - place;
            if ((maxSize - place > 0) and (array[i].size() >= maxSize - place))
                str_size = maxSize - place;
            else
                str_size = 0;
        }
        letter = (array[i])[str_size];

        if (int(letter) > 96)
        {
        
             count[((int(letter) - 6) % 65)]++;
        }
        else
        {
             count[(int(letter) % 65)]++;
        }
    }
    

    // Calculate cumulative count
    for (std::size_t i = 1; i < max; i++)
        count[i] += count[i - 1];


    int lastArrInd = -1;
    int lastind = 0;
    letter = '-';
    int lastsize = 0;
    int lastcopyInd = -1;
    int lastcopyletter = 0;
    int lastcopysize = 0;
     // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--)
    {
        if (array[i].size() <= maxSize - place)
        {
            str_size = array[i].size() - 1;
        }
        else
        {
            if ((maxSize - place > 0) and (array[i].size() >= maxSize - place))
            {
                str_size = maxSize - place;
            }
            else
            {
                str_size = 0;
            }

        }
        lastind = int(letter);
        letter = array[i][str_size];
        
        if (int(letter) > 96)
        {
            output[count[((int(letter) - 6) % 65)] - 1] = array[i];
            count[(int(letter) - 6) % 65]--;

            if ((maxSize - place == 0) and (lastArrInd != -1) and (lastsize < array[i].size()) and (lastind == int(letter)) and (lastArrInd > count[(int(letter) - 6) % 65])
                and (output[count[(int(letter) - 6) % 65]].find(output[lastArrInd]) != std::string::npos))
            {
                std::swap(output[lastArrInd], output[count[(int(letter) - 6) % 65]]);
            }
        }
        else
        {
            
                output[count[(int(letter) % 65)] - 1] = array[i];
                count[int(letter) % 65]--;

            if ((maxSize - place == 0) and (lastArrInd != -1) and (lastsize < array[i].size()) and (lastind == int(letter)) and (lastArrInd > count[(int(letter)) % 65])
                and (output[count[(int(letter)) % 65]].find(output[lastArrInd]) != std::string::npos))
            {
                
                std::swap(output[lastArrInd], output[count[(int(letter)) % 65]]);
            }
            

        }
        lastsize = array[i].size();
        
    }
    if (maxSize - place == 0)
    {
        for (int i = 1; i < size; i++)
        {
            if ((output[i].size() == 1) and (output[i - 1].size() > output[i].size()) and (output[i - 1].find(output[i]) != std::string::npos) and (output[i - 1][0] == output[i][0]))
                std::swap(output[i], output[i - 1]);
        }
    }
    /*std::cout << std::endl; */

    for (int i = 0; i < size; i++)
        array[i] = output[i];
    delete[] count;
    delete[] output;
    
    
    std::cout << "Step " << place << " - ";
    printArray(array, size);
}

// Main function to implement radix sort
void radixsort(std::string* array, const std::size_t & size)
{
    std::size_t max = getMaxSize(array, size);

    // Apply counting sort to sort elements based on place value.
    for (std::size_t i = 1; i < max + 1; i++)
    {
        
        countingSort(array, size, i);
    }
}

void printArray(const std::string * array, const std::size_t & size) {
    for (std::size_t i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

// Driver code
int main() {
    //l p j kw lAAWWnp
    std::size_t size0 = 10;
    std::size_t count0 = 5;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "----Test checkStrArray():----" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;
    std::string* array0;
    array0 = new std::string[count0];
    array0[0] = "p";               //худший вариант
    array0[1] = "lAAWWnp";
    array0[2] = "A";
    array0[3] = "pa";
    array0[4] = "l";
    
    //array0[0] = "A";             //наилучший вариант
    //array0[1] = "Abb";
    //array0[2] = "Abbb";
    //array0[3] = "AVvv";
    //array0[4] = "ffff";
    std::cout << "Array before sorting:" << std::endl;
    printArray(array0, count0);
    std::cout << std::endl;
    std::cout << "*********************" << std::endl ;
    std::cout << ((checkStrArray(array0, count0)) ? "*** All sorted OK ***" : "** All sorted BAD **") << std::endl;
    std::cout << "*********************" << std::endl;

    
    std::cout << std::endl << "Sorting steps:" << std::endl;
    radixsort(array0, count0);
    std::cout << std::endl << "Array after sorting:" << std::endl;
    printArray(array0, count0);
    std::cout << std::endl;
    
    std::cout << "*********************" << std::endl;
    std::cout << ((checkStrArray(array0, count0)) ? "*** All sorted OK ***" : "** All sorted BAD **") << std::endl;
    std::cout << "*********************" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    delete[] array0;
    








    //LnFJQDA wEC ejrBmDF w qHPadAPx
    //fKiggGYqi GXIwb JY Br f T

   // std::size_t size = 10;
   // std::size_t count = 5;
   // std::cout << "Array before sorting:" << std::endl;
   // std::string* array;
   // array = new std::string[count];
   // array[0] = "PVd";
   // array[1] = "i";
   // array[2] = "k";
   // array[3] = "ibnqMo";
   // array[4] = "jqpGHCuIq";

   ///* array[0] = "LnFJQDA";
   // array[1] = "wEC";
   // array[2] = "ejrBmDF";
   // array[3] = "w";
   // array[4] = "qHPadAPx";*/

   // /*array[0] = "fKiggGYqi";
   // array[1] = "GXIwb";
   // array[2] = "JY";
   // array[3] = "f";
   // array[4] = "T";*/

   // printArray(array, count);
   // std::cout << "*********************" << std::endl;
   // std::cout << ((checkStrArray(array, count)) ? "*** All sorted OK ***" : "** All sorted BAD **") << std::endl;
   // std::cout << "*********************" << std::endl;
   // std::cout << std::endl << "Sorting steps:" << std::endl;
   // radixsort(array, count);
   // std::cout << std::endl << "Array after sorting:" << std::endl;
   // printArray(array, count);
   // std::cout << "*********************" << std::endl;
   // std::cout << ((checkStrArray(array, count)) ? "*** All sorted OK ***" : "** All sorted BAD **") << std::endl;
   // std::cout << "*********************" << std::endl;
   // delete[] array;


   



    //

    /*std::cout << "-------------------------" << std::endl;
    std::cout   << "---- Test randString:----" << std::endl;
    std::cout << std::endl;

    std::size_t size = 10;
    std::size_t count = 10;
    std::cout << "Array before sorting:" << std::endl;
    std::string* array = randString(size, count);
    printArray(array, count);
    std::cout << "*********************" << std::endl;
    std::cout << ((checkStrArray(array, count)) ? "*** All sorted OK ***" : "** All sorted BAD **") << std::endl;
    std::cout << "*********************" << std::endl;

    radixsort(array, count);
    std::cout << std::endl;
    std::cout << "Array after sorting:" << std::endl;
    printArray(array, count);
    std::cout << "*********************" << std::endl;
    std::cout << ((checkStrArray(array, count)) ? "*** All sorted OK ***" : "** All sorted BAD **") << std::endl;
    std::cout << "*********************" << std::endl;
    std::cout << std::endl;
    std::cout << "Array after std::sort:" << std::endl;
    std::sort(array, array + count);
    printArray(array, count);
    delete[] array;*/
}
