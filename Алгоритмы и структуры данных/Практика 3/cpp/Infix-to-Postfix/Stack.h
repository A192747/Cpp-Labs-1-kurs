#ifndef STRACK_H
#define STRACK_H
#include <iostream>
#include <exception>
#include "Stackflow.h"

template <class T> 
class Stack
{
public:
    virtual ~Stack() {}
    virtual void push(const T& item) = 0; // Добавление элемента в стек
    virtual T pop() = 0; // Удаление и возвращение верхнего элемента
    virtual bool isEmpty() = 0; // Проверка стека на пустоту
};

template < typename T >
class StackArray : public Stack <T>
{
public:
    StackArray() : number_(0), count_(0), value_(nullptr) {}
    StackArray(double count)
    {
        try
        {
            if ((count != int(count)) or (count < 0))
            {
                throw WrongStackSize();
            }
        }
        catch (const std::exception& e)
        {
            std::cout << e.what();
            exit(-1);
        }
        number_ = count;
        count_ = 0;
        value_ = new T[number_];
    }
    ~StackArray()
    {
        delete[]value_;
    }

    void push(const T& item)
    {

        try
        {
            if ((count_ == number_))
            {
                throw StackOverflow();
            }
        }
        catch (const std::exception& e)
        {
            std::cout << e.what();
            exit(-1);
        }
        value_[count_] = item;
        count_++;
    }

    T pop()
    {
        try
        {
            if (count_ == 0) 
            {
                throw StackUnderflow();
            }
        }
        catch (const std::exception& e)
        {
            std::cout << e.what();
            exit(-1);
        }
        T item = value_[count_ - 1];
        T* value2 = nullptr;
        if (count_ != 1) 
        {
            value2 = new T[number_];
        }
        count_--;
        if (count_ != 0) 
        {
            for (unsigned int i = 0; i < count_; i++) 
            {
                value2[i] = value_[i];
            }
        }
        if (count_ > 0) 
        {
            delete[] value_;
            value_ = value2;
        }
        /*else 
        {
            delete[] value_;
            value_ = nullptr;
        }*/
        return item;
    }


    bool isEmpty() 
    {
        return count_ == 0;
    }

    T top()
    {           
        return value_[count_ - 1];
    }

private:
    unsigned int count_;
    unsigned int number_;
    T* value_;
};
#endif