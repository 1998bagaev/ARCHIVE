#include "stdafx.h"
#include <iostream>
using namespace std;

class Boolean_function
{
	int k; //количество переменных
	int n; //длина вектора значений
public:
	bool *function;
	Boolean_function()
	{
		k = 0;
		n = 1;
		function = new bool[n];
	}

	

	Boolean_function(int _k)
		:k(_k)
	{
		n = (int)pow(2., k);
		function = new bool[n];
	}
	void set_function()
	{
		for (int i = 0; i < n; i++)
			cin >> function[i];
	}

	void print()
	{
		for (int i = 0; i < n; i++)
			cout << function[i] << " ";
	}
	 friend Boolean_function conjunction(Boolean_function a, Boolean_function b);
	 friend Boolean_function disjunction(Boolean_function a, Boolean_function b);
	 friend Boolean_function xor(Boolean_function a, Boolean_function b);
	 friend Boolean_function negation(Boolean_function a);
	 friend Boolean_function ecvivalence(Boolean_function a, Boolean_function b);
	 friend Boolean_function Sheffer_stroke(Boolean_function a, Boolean_function b);
	 friend Boolean_function Piers_arrow(Boolean_function a, Boolean_function b);
	 friend Boolean_function implication(Boolean_function a, Boolean_function b);

	 ~Boolean_function()
	 {}

};

      Boolean_function conjunction(Boolean_function a, Boolean_function b)
{

	Boolean_function result(a.k);
	for (int i = 0; i < a.n; i++)
		result.function[i] = a.function[i] & b.function[i];
	return result;
}

      Boolean_function disjunction(Boolean_function a, Boolean_function b)
{
	Boolean_function result(a.k);
	for (int i = 0; i < a.n; i++)
		result.function[i] = a.function[i] | b.function[i];
	return result;
}

      Boolean_function xor(Boolean_function a, Boolean_function b)
{
	Boolean_function result(a.k);
	for (int i = 0; i < a.n; i++)
		result.function[i] = a.function[i] ^ b.function[i];
	return result;
}

Boolean_function negation(Boolean_function a)
{
	Boolean_function result(a.k);
	for (int i = 0; i < a.n; i++)
		result.function[i] = !a.function[i];
	return result;
}

Boolean_function ecvivalence(Boolean_function a, Boolean_function b)
{
	Boolean_function result(a.k);
	for (int i = 0; i < a.n; i++)
		result.function[i] = !a.function[i] ^ b.function[i];
	return result;
}


Boolean_function Sheffer_stroke(Boolean_function a, Boolean_function b)
{

	Boolean_function result(a.k);
	for (int i = 0; i < a.n; i++)
		result.function[i] = !a.function[i] & !b.function[i];
	return result;
}


Boolean_function Piers_arrow(Boolean_function a, Boolean_function b)
{
	Boolean_function result(a.k);
	for (int i = 0; i < a.n; i++)
		result.function[i] = !a.function[i] | !b.function[i];
	return result;
}


Boolean_function implication(Boolean_function a, Boolean_function b)
{
	Boolean_function result(a.k);
	for (int i = 0; i < a.n; i++)
		result.function[i] = !a.function[i] | b.function[i];
	return result;
}


int main(){
	Boolean_function x1(2);
	Boolean_function x2(2);

	x1.set_function();
	cout << endl;
	x2.set_function();
	cout << endl;

	conjunction(x1, x2).print();
	cout << endl;
	disjunction(x1, x2).print();
	cout << endl;
	xor(x1, x2).print();
	cout << endl;
	negation(x1).print();
	cout << endl;
	ecvivalence(x1, x2).print();
	cout << endl;
	Sheffer_stroke(x1, x2).print();
	cout << endl;
	Piers_arrow(x1, x2).print();
	cout << endl;
	implication(x1, x2).print();
	cout << endl;

	

	

	system("pause");
	return 0;
}
