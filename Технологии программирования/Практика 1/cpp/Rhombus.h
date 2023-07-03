#ifndef RHOMBUS_H
#define RHOMBUS_H

class Rhombus
{
private:
	unsigned int side_;
public:
	Rhombus() : side_(0) {};
	Rhombus(unsigned int&& size);
	Rhombus(const Rhombus& other);
	~Rhombus() = default;
	unsigned int& getSide() { return side_; }
	void side(unsigned int&& size);
};

#endif
