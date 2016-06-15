#include "stdafx.h"
#include <iostream>
using namespace std;
class driver
{
public:
	double _exp; double _salary; char FIO[20]; int IDD; static int maxID;
	driver() = default;
	    
	driver(double exp, double salary)
		: _exp(exp), _salary(salary)
	{
	
	}
	void yearmoney(double sum)
	{
		sum += 12 * _salary;

	}

	void experiance(double staj)
	{
		staj += 12 * _exp;
	}

	void save(ostream &out)
	{
		out << IDD << endl;
		out << FIO << endl;
	}

	void load(istream &in)
	{
		in >> IDD;
		in.getline(FIO, 20);

		
	}

	friend ostream &operator<<(ostream &out, driver &driver);
	friend istream &operator>>(istream &in, driver &driver);

	~driver()
	{

	}
};

ostream &operator<<(ostream &out, driver &driver)
{
	out << driver.IDD << " " << driver.FIO << endl;
	return out;
}


istream &operator>>(istream &in, driver &driver)
{
	cout << "Input name: ";
	in.getline(driver.FIO, 20);
	return in;
}




	

class autom
{
public:
	autom() = default;
	double _mark; double _power; char _color; char NAZV[20]; int IDA; static int maxID;
	
	autom(double mark, double power, char color)
		: _mark(mark), _power(power), _color(color)
	{
	
	}

	void getmark()
	{
		cout << _mark << endl;
	}
	void getcolor()
	{
		cout << _color << endl;
	}

	virtual void upgrade(double energy)
	{
		energy += 150 * _power;
	}
	

	void save(ostream &out)
	{
		out << IDA << endl;
     	out << NAZV << endl;
	}

	void load(istream &in)
	{
	    in >> IDA;
	    in.getline(NAZV, 20);
	}

	friend ostream &operator<<(ostream &out, autom  & autom);
	friend istream &operator>>(istream &in, autom  & autom);

	virtual ~autom()
	{
		
	}
};


ostream &operator<<(ostream &out, autom &autom)
{
	    out << autom.IDA << " " << autom.NAZV << endl;
	    return out;
}


istream &operator>>(istream &in, autom &autom)
{
     	cout << "Input name: ";
    	in.getline(autom.NAZV, 20);
    	return in;
}



class econom :public autom
{
public:
	double _mark; double _power; char _color; double _cost;
	    
	econom(double mark, double power, char color, double cost)
		:_mark(mark), _power(power), _color(color), _cost(cost)
	{

	}

	void getmark()
	{
		cout << _mark << endl;
	}
	
	void showcolor()
	{
		cout << _color << endl;
	}

	virtual void upgrade(double energy) override
	{
		energy += 150 * _power;
	}
	void price(double value)
	{
		value += 15000 * _cost;
	}

	~econom()
	{
		
	}

};


class comfort :public autom
{
public:
	double _mark; double _power; char _color; double _cost;
	  comfort(double mark, double power, char color, double cost)
	  :_mark(mark), _power(power), _color(color), _cost(cost)
	{

	}

	void getmark()
	{
		cout << _mark << endl;
	}

	void showcolor()
	{
		cout << _color << endl;
	}

	void upgrade(double energy) override
	{
		energy += 150 * _power;
	}
	void price(double value)
	{
		value += 60000 * _cost;
	}

	~comfort()
	{

	}
};


class passen
{
public:
	passen() = default;
	double _distance; double _pay; double _addfunc; char NAME[20]; int IDP; 
	    passen(double distance, double pay,double addfunc)
		:_distance(distance), _pay(pay), _addfunc(addfunc)
	{

	}

	void sumway(double way)
	{
		way += _distance * 1000;
	}
	
	virtual void sumvalue(double sumpay)
	{
		sumpay += 15000 * _distance+_pay;
	}

	void cost(double sum)
	{
		sum += 60 * _addfunc;
	}

	void save(ostream &out)
	{
		out << IDP << endl;
		out << NAME << endl;
	}

	void load(istream &in)
	{
		in >> IDP;
		in.getline(NAME, 20);
	}

	friend ostream &operator<<(ostream &out, passen & passen);
	friend istream &operator>>(istream &in, passen  & passen);

	virtual ~passen()
	{

	}
};


ostream &operator<<(ostream &out, passen &passen)
{
	out << passen.IDP << " " << passen.NAME << endl;
	return out;
}


istream &operator>>(istream &in, passen &passen)
{
	cout << "Input name: ";
	in.getline(passen.NAME, 20);
	return in;
}


class person :public passen
{
public:
	person() = default;
	double _distance; double _pay; double _addfunc;
	    person(double distance, double pay, double addfunc)
		:_distance(distance), _pay(pay), _addfunc(addfunc)
	{

	}

	void sumway(double way)
	{
		way += _distance * 1000;
	}

	void sumvalue(double sumpay)override
	{
		sumpay += 15000 * _distance + _pay;
	}

	void cost(double sum)
	{
		sum += 60 * _addfunc;
	}
	~person()
	{

	}



};


class company :public passen
{
public:
	company();
	double _distance; double _pay; double _addfunc;
	    company(double distance, double pay, double addfunc)
		:_distance(distance), _pay(pay), _addfunc(addfunc)
	{

	}

	void sumway(double way)
	{
		way += _distance * 1000;
	}

	void sumvalue(double sumpay)override
	{
		sumpay += 30*(15000 * _distance + _pay);
	}

	void cost(double sum)
	{
		sum += 60 * _addfunc;
	}
	~company()
	{

	}
};

