#include <iostream>
#include <cmath>
#include <cstring>
class bitset
{
	bool *array;
	int _N;
public: 
	bitset(int N)
		: _N(N)
	{
		array = new bool[_N];
	}

	bitset(const bitset& rhs)
	{
		_N = rhs._N;
		array = new bool[_N];
		memcpy(array, rhs.array, _N);
	}
	bitset& operator&= (const bitset& rhs)
	{
		for (int i = 0; i < _N; i++)
		{
			array[i] &= rhs.array[i];
		}
		return *this;
	}

	friend bitset operator &(const bitset& rhs1 , const bitset& rhs)
	{
		bitset temp(rhs1);
		temp &= rhs;
		return temp;
	}

	bitset& operator|= (const bitset& rhs)
	{
		for (int i = 0; i < _N; i++)
		{
			array[i] |= rhs.array[i];
		}
		return *this;
	}

	friend bitset& operator |(const bitset & rhs, const bitset& rhs1)
	{
		bitset temp(rhs1);
		temp |= rhs;
		return temp;
	}

	bitset& operator^= (const bitset& rhs)
	{
		for (int i = 0; i < _N; i++)
		{
			array[i] ^= rhs.array[i];
		}
		return *this;
	}

	friend bitset& operator ^(const bitset & rhs, const bitset& rhs1)
	{
		bitset temp(rhs1);
		temp ^= rhs;
		return temp;
	}

	bitset& operator<<= (const size_t pos)
	{
		size_t pos;
		for (int i = 0; i < _N; i++)
		{
			array[i] <<= pos;
		}
		return *this;
	}

	bitset& operator>>= (const size_t pos)
	{
		size_t pos;
		for (int i = 0; i < _N; i++)
		{
			array[i] >>= pos;
		}
		return *this;
	}
	
	friend bitset operator<<(const size_t pos, const bitset & rhs) 
	{
		bitset temp(rhs);
		temp <<= pos;
		return temp;
	}


	friend bitset operator>>(const size_t pos, const bitset & rhs) 
	{
		bitset temp(rhs);
		temp <<= pos;
		return temp;
	}
	bool operator== (const bitset& rhs) 
	{
		for (int i = 0; i < _N;i++)
		if (array[i] == rhs.array[i])
			return true;
		else return false;
	}
	bool operator!= (const bitset& rhs) 
	{
		for (int i = 0; i < _N; i++)
		if (array[i] != rhs.array[i])
			return true;
		else return false;
	}
		
	bool empty(const bitset & rhs)
	{
		for (int i = 0; i < _N;i++)
		if (rhs.array[i] == 0)  return true;
			else return false;		
	}


~bitset()
		{

		}

};


