#ifndef SQUARE_H
#define SQUARE_H

class Square
{
private:
	unsigned int side_;
public:
	Square() : side_(0) {};
	~Square() = default;
	unsigned int& getSide() { return side_; }
	void side(unsigned int&& size);
};

#endif
