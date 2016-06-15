#define STUDENT_VARIANT 2
#include<iostream>
using namespace std;

class IUVector
{
	double* p;
	int n;
public:
	IUVector()
	{
		p = nullptr;
		n = 0;
	}
	IUVector(double*  pp, int nn) : n(nn)
	{
		p = new double[n];
		for (int i = 0; i < n; i++)
		{
			p[i] = pp[i];
		}
	}
	IUVector(IUVector& m) : n(m.n)
	{
		p = new double[n];
		for (int i = 0; i < n; i++)
		{
			p[i] = m.p[i];
		}

	}
	void change()
	{
		for (int i = 0; i < n; i++)
			p[i] *= 2;
	}
	double& getV(int i)
	{
		return this->p[i];
	}
	void setp(double*_p)
	{
		for (int i = 0; i < n; i++)
		{
			p[i] = _p[i];
		}
		//p = _p;
	}
	int& size()
	{
		return this->n;
	}
	double& operator[](int index)
	{
		return p[index];
	}
	IUVector& operator=(IUVector t)
	{
		if (p != nullptr) delete[] p;
		n = t.n;
		p = new double[n];
		for (int i = 0; i < n; i++)
		{
			p[i] = t.p[i];
		}

		n = t.n;
		return *this;
	}
	friend std::ostream& operator<<(ostream& out, IUVector& print);

	double* operator+(IUVector& sec)
	{
		double* vec = new double[this->n];
		for (int i = 0; i < n; i++)
			vec[i] = this->p[i] + sec[i];
		return vec;
	}
	~IUVector()
	{
		if (p != nullptr)
		{

			delete[]p;
			cout << "/dtor here " << endl;
		}
		else cout << "zero.dtor" << endl;

	}
};
std::ostream& operator<< (std::ostream& out, IUVector& print)
{
	if (print.p != nullptr)
	{
		for (int i = 0; i < print.n; i++)
			out << print[i] << " ";
	}
	else
		out << " no value";
	out << endl;
	return out;
}
