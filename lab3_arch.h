#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <cstring>

class ComplexNum
{
	double _x, _iy; 
public:
	ComplexNum()
	{
		std::cout << "default";
	}
	void print()
	{
		std::cout << _x << "+" << _iy << "i" << std::endl;
	}
	ComplexNum(double x, double iy)
		:_x(x), _iy(iy)
	{
	}
	ComplexNum& ComplexNum::operator+=(ComplexNum a)
	{
		_x += a._x;
		_iy += a._iy;
		return *this;
	}

	ComplexNum& ComplexNum::operator-=(ComplexNum a)
	{
		_x -= a._x;
		_iy -= a._iy;
		return *this;
	}

	ComplexNum& ComplexNum::operator*=(ComplexNum a)
	{
		_x *= a._x;
		_iy *= a._iy;
		return *this;
	}

	ComplexNum& ComplexNum::operator/=(ComplexNum a)
	{
		_x /= a._x;
		_iy /= a._iy;
		return *this;
	}

	friend ComplexNum operator + (const ComplexNum& first, const ComplexNum& second)
	{
		return complex(first._x + second._x, first._iy + second._iy);
	}

	friend ComplexNum operator - (const ComplexNum& first, const ComplexNum& second)
	{
		return ComplexNum(first._x - second._x, first._iy - second._iy);
	}

	friend ComplexNum operator * (const ComplexNum& first, const ComplexNum& second)
	{
		return ComplexNum(first._x * second._x - first._iy * second._iy, first._x * second._iy + first._iy * second._x);
	}

	friend ComplexNum operator / (const ComplexNum& first, const ComplexNum& second)
	{
		double k = second._x * second._x;
		return ComplexNum((first._x * second._x + first._iy * second._iy) / k, (first._x * second._iy - first._iy * second._x) / k);
	}
};
	
