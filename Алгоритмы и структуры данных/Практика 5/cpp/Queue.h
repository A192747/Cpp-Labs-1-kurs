#ifndef QUEUE_H
#define	QUEUE_H
#include "QueueFlow.h"
#include <exception>

template <class T>
class Queue
{
public:
	virtual ~Queue() {}
	virtual void enQueue(const T& e) = 0; // Добавление элемента
	virtual T deQueue() = 0; // Удаление и возвращение элемента
	virtual bool isEmpty() = 0; // Проверка на пустоту
};

template <class T>
class MyQueue : public Queue <T>
{
private:
    T* value_;
    int front, rear;
    unsigned int number_, count_;


public:
	MyQueue() : front(-1), rear(-1), number_(0), count_(0), value_(nullptr) {}
    ~MyQueue()
    {
        delete[] value_;
    }
    MyQueue(const double & count) : front(-1), rear(-1)
    {
        try
        {
            if ((count != int(count)) or (count < 0))
            {
                throw WrongQueueSize();
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
    bool isEmpty() 
    {
        return count_ == 0;
    }

    void enQueue(const T& element) 
    {
        try
        {
            if (number_ == count_)
            {
                throw QueueOverflow();
            }
        }
        catch (const std::exception& e)
        {
            std::cout << e.what();
            exit(-1);
        }
        
        if (front == -1) 
            front = 0;
        rear = (rear + 1) % number_;
        value_[rear] = element;
        count_++;
    }

    T deQueue() {
        T element;
        try
        {         
            if (isEmpty())
            {
                throw QueueUnderflow();
            }
        }
        catch (const std::exception& e)
        {
            std::cout << e.what();
            exit(-1);
        } 
        element = value_[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } /* Q имеет только один элемент, поэтому мы удаляем очередь после удаления. */
        else 
        {
            front = (front + 1) % number_;
        }
        count_--;
        return element;
    }
};

#endif