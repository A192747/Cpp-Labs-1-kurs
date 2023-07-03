#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

namespace voronova {
  template < typename T >
  class Queue;
}

template < typename T >
class voronova::Queue {
public:
  Queue() :
    count_(0),
    value_(nullptr)
  {}
  ~Queue()
  {
    delete[] value_;
  }
  void push(const T& item)
  {
    T* value2 = value_;
    value_ = nullptr;
    try {
      value_ = new T[count_ + 1];
    }
    catch (const std::bad_alloc& e) {
      delete[] value2;
      throw e;
    }
    for (unsigned int i = 0; i < count_; i++) {
      value_[i] = value2[i];
    }
    value_[count_] = item;
    count_++;
    delete[] value2;
  }

  T pop()
  {
    if (count_ == 0) {
      throw std::logic_error("Error: there are no items in the queue");
    }
    T item = value_[0];
    T* value2 = nullptr;
    try {
      if (count_ != 1) {
        value2 = new T[count_ - 1];
      }
    }
    catch (const std::bad_alloc& e) {
      throw e;
    }
    count_--;
    if (count_ != 0) {
      for (unsigned int i = 0; i < count_; i++) {
        value2[i] = value_[i + 1];
      }
    }
    if (count_ > 0) {
      delete[] value_;
      value_ = value2;
    } else {
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
