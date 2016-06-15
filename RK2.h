#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>

class Military
{
protected:
	int power;
	int armor;
	int cost;
public:
	Military(int power, int armor, int cost);
	int Getpower();
	int Getarmor();
	int Getcost();
	virtual void GetInfo();
	virtual void ChangeParams(int IQ)
	{
		this->cost = cost;
	};

virtual ~Military()
{}

};
void Military::GetInfo()
{
	std::cout << "power= " << power;
	std::cout << "armor= " << armor;
	std::cout << "cost= " << cost;
};





class Tank : public Military
{
private:
	double speed;
public:
	Tank(int power, int armor, int , double speed) : Military(power, armor, cost)
	{
		this->speed = speed;
	}
	void GetInfo() { Military::GetInfo(); std::cout << "speed = %f" << speed; };
	void ChangeParams(int cost, double _speed)
	{ Military::ChangeParams(cost); speed = _speed; };
};



class Helicopter : public Military
{
private:
	double weapon;
public:
	Helicopter(int power, int armor, int cost, double weapon) : Military(power, armor, cost)
	{
		this->weapon = weapon;
	}
	void GetInfo() { Military::GetInfo(); std::cout << "weapon = %f" << weapon; };
	void ChangeParams(int IQ, double _weapon)
	{ Military::ChangeParams(IQ); weapon = _weapon; };
};

Military::Military(int power, int armor, int cost)
{
	assert(power > 0 && armor> 0 && cost > 0);
	this->power = power;
	this->armor = armor;
	this->cost = cost;
}

int Military::Getpower()
{
	return this->power;
}

int Military::Getarmor()
{
	return this->armor;
}

int Military::Getcost()
{
	return this->cost;
}

int main()
{
	Military m1(50, 114, 110), m2(25, 764, 120);
	Tank t1(20, 184, 120, 19), t2(25, 1754, 12, 95);
	Helicopter h1(30, 175, 125, 100), h2(306, 19, 128, 120);


	Military *pointer = &h1;
	pointer->GetInfo();
	pointer = &t1;
	pointer->GetInfo();

	std::vector<Military *> data;
	data.push_back(&m1);
	data.push_back(&t1);
	data.push_back(&h1);

	for (std::vector<Military *>::iterator i = data.begin(); i < data.end(); i++)
		printf("%d ", (*i)->Getpower());
	return 0;
}
