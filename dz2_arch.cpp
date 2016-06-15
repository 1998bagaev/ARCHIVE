#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <map>
#include "Header.h"


#define ADDpassen 5
#define SEARCH1 3
#define UPDATE1 4
#define EXIT 10
#define SAVE 9
#define SHOWDATA 0
#define ADDdriver 1
#define ADDautom 2


using namespace std;



map<int, driver> drivers;
map<int, autom> automobiles;
map<int, passen> passengers;


void loadBASE()
{
	int count;
	char temp[3];

	

	ifstream f("BASE.txt");

	f >> count;
	f.getline(temp, 2);
	for (int i = 0; i < count; ++i)
	{
		driver driver;
		driver.load(f);
		drivers[driver.id] = driver;
	}

	f >> count;
	f.getline(temp, 2);
	for (int i = 0; i < count; ++i)
	{
		autom autom;
		autom.load(f);
		automobiles[autom.id] = autom;
	}

	f >> count;
	f.getline(temp, 2);
	for (int i = 0; i < count; ++i)
	{
		passen passen;
		passen.load(f);
		passengers[passen.id] = passen;
	}

	f.close();

}


void saveBASE()
{
	int count;
	char temp[3];

	
	ofstream f("BASE.txt");


	count = drivers.size();
	f << count << endl;
	for (map<int, driver>::iterator it = drivers.begin(); it != drivers.end(); ++it)
		it->second.save(f);

	count = automobiles.size();
	f << count << endl;
	for (map<int, autom>::iterator it = automobiles.begin(); it != automobiles.end(); ++it)
		it->second.save(f);

	count = passengers.size();
	f << count << endl;
	for (map<int, passen>::iterator it = passengers.begin(); it != passengers.end(); ++it)
		it->second.save(f);

	f.close();

}



void addDriver()
{
	driver driver;
	cin >> driver;
	drivers[driver.id] = driver;
}

void addAutom()
{
	autom autom;
	cin >> autom;
	automobiles[autom.id] = autom;
}

void addPassen()
{
	passen passen;
	cin >> passen;
	passengers[passen.id] = passen;
}

void showData()
{
	cout << "Drivers:" << endl;
	for (map<int, driver>::iterator it = drivers.begin(); it != drivers.end(); ++it)
	{
		cout << it->second;
	}
	cout << endl;


	cout << "Automobiles:" << endl;
	for (map<int, autom>::iterator it = automobiles.begin(); it != automobiles.end(); ++it)
	{
		cout << it->second;
	}
	cout << endl;

	cout << "Passengers:" << endl;
	for (map<int, passen>::iterator it = passengers.begin(); it != passengers.end(); ++it)
	{
		cout << it->second;
	}
	cout << endl;

}

driver &searchDriverById()
{
	int id;
	char temp[3];
	cout << "Input id: ";
	cin >> id;
	cin.getline(temp, 2);

	return drivers[id];

}

void searchAndShowDriverById()
{
	cout << searchDriverById();
}

void updateDriverById()
{
	driver driver = searchDriverById();

	cout << "Input new fio: ";
	cin.getline(driver.fio, 49);
	drivers[driver.id] = driver;
}




int main()
{
	loadBASE();
	bool isFinished = false;


	while (!isFinished)
	{
		int choise;
		char temp[3];
		cout << "Choise action: " << endl;
		cout << SHOWDATA << " - show data" << endl;
		cout << ADDdriver << " - add new driver" << endl;
		cout << ADDautom << " - add new automobile" << endl;
		cout << SEARCH1 << " - search driver by id" << endl;
		cout << UPDATE1 << " - update driver info by id" << endl;
		cout << ADDpassen << " - add new passen" << endl;
		cout << SAVE << " - save BASE" << endl;
		cout << EXIT << " - EXIT" << endl;


		cin >> choise;
		cin.getline(temp, 2);

		switch (choise)
		{
		case SHOWDATA:
			showData();
			cout << "Complete!!!" << endl << endl;
			break;
		case ADDdriver:
			addDriver();
			cout << "Complete!!!" << endl << endl;
			break;
		case ADDautom:
			addAutom();
			cout << "Complete!!!" << endl << endl;
			break;

		case SEARCH1:
			searchAndShowDriverById();
			cout << "Complete!!!" << endl << endl;
			break;

		case UPDATE1:
			updateDriverById();
			cout << "Updated!!!" << endl << endl;
			break;

		case SAVE:
			saveBASE();
			cout << "Saved!!!" << endl << endl;

			break;

		case ADDpassen:
			addPassen();
			cout << "Complete!!!" << endl << endl;
			break;

		case EXIT:
			isFinished = true;
			break;
		}


	}


}
