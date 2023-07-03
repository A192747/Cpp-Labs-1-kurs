#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template < typename T >
class Queue 
{
public:
    Queue() : count_(0), value_(nullptr) {}
    ~Queue()
    {
        delete[] value_;
    }
    void push(const T& item)
    {
        T* value2 = value_;
        value_ = nullptr;
        value_ = new T[count_ + 1];
        for (unsigned int i = 0; i < count_; i++) {
            value_[i] = value2[i];
        }
        value_[count_] = item;
        count_++;
        delete[] value2;
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
        T item = value_[0];
        T* value2 = nullptr;
        if (count_ != 1) 
            value2 = new T[count_ - 1];
        count_--;
        if (count_ != 0) {
            for (unsigned int i = 0; i < count_; i++) 
            {
                value2[i] = value_[i + 1];
            }
        }
        if (count_ > 0) 
        {
            delete[] value_;
            value_ = value2;
        } 
        else 
        {
            delete[] value_;
            value_ = nullptr;
        }
        return item;
    }

    bool isEmpty() {
        return count_ == 0;
    }

private:
    unsigned int count_;
    T* value_;
};
#endif
