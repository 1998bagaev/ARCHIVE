#include <iostream>

enum TypeOfRoad
{
CounryRoad = 1,
CityRoad = 2,
IceRoad = 3,
Water = 4
};

class Car
{
private:
	char * _govNumber;
	int _horsepower;

public:
Car()
{}

Car(char * govNumber, int horsepower)
	:_govNumber(govNumber),_horsepower(horsepower)
{}

~Car()
{
	std::cout << ".dcor Car" << std::endl;
}

virtual bool canMove(TypeOfRoad typeOfRoad) const
{
	if (typeOfRoad == 1 || typeOfRoad == 2)
	return true;
	else return false;
}
};

class Lorry : public Car
{
private:
	int _capacity;

public:
	Lorry()
	{}

	Lorry(char * govNumber, int horsepower, int capacity)
	{
		govNumber = 0;
		horsepower = 0;
		capacity = 0;

	}

	bool canMove(TypeOfRoad typeOfRoad) const
	{
		if (typeOfRoad == 2)
			return true;
		else return false;
	}

	~Lorry()
	{
		std::cout << ".dcor Lorry" << std::endl;
	}
};

class CrossCountry : public Car
{
public:
	CrossCountry()
	{}

	CrossCountry(char * govNumber, int horsepower)
	{
		govNumber = 0;
		horsepower = 0;
	}

	~CrossCountry()
	{
		std::cout << ".dcor CrossCountry" << std::endl;
	}
	
	bool canMove(TypeOfRoad typeOfRoad) const
	{
		return true;
	}
};
