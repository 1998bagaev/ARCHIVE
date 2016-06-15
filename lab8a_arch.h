#include <iostream>
#include <thread>
#include <fstream>
#include <string>

/*
 Сумма от 0 до N
*/

void sum1(int &n1, int N)
{
	for (std::size_t i = 1; i <= N; i += 2)
		n1 += i;
}

void sum2(int &n2, int N) 
{
	for (std::size_t i = 0; i <= N; i += 2)
		n2 += i;
}



/*
 Факториал числа N
*/

void fact_1(int &N)
{
	
	for (int i = N - 2; i > 0; i -= 2)
		N *= i;
}


void fact_2(int &N)
{
	
	for (int i = N - 2; i > 0; i -= 2)
		N *= i;

}

/* Выборка С из n по k*/



void fact(int &N)
{

	for (std::size_t i = N-1; i > 0; --i)
		N *= i;
}

/* Матрица */






void MyMatr(int **pA, int** pB, int **pC, int m, int i, int j)
{
	pC[i][j] = 0;
	for (int k = 0; k < m; k++)
		pC[i][j] += pA[i][k] * pB[k][j];
}
