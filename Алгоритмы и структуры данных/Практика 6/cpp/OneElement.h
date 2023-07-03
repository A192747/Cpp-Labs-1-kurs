#ifndef ONEELEMENT_H
#define ONEELEMENT_H

struct OneElement
{
    OneElement() : letter_(-1), ind_(-1), size_(-1) {}
    OneElement(const OneElement& str)
    {
        letter_ = str.letter_;
        size_ = str.size_;
        ind_ = str.ind_;
    }
    ~OneElement() = default;

    void size(const int& size)
    {
        size_ = size;
    }
    void ind(const int& ind)
    {
        ind_ = ind;
    }
    void letter(const int& letter)
    {
        letter_ = letter;
    }
    int& get_size()
    {
        return size_;
    }
    int& get_ind()
    {
        return ind_;
    }
    int& get_letter()
    {
        return letter_;
    }

private:
    int letter_;
    int ind_;
    int size_;
};
#endif