#include "stdafx.h"
#include "Header.h"


/*

int main()
{
	
	int n1 = 0;
	int n2 = 0;
	std::cout << "Enter N : ";
	int N;
	std::cin >> N;
	std::thread sum_1(sum1, std::ref(n1), N);
	std::thread sum_2(sum2, std::ref(n2), N);
	sum_1.join();
	sum_2.join();
	auto time_s1 = clock();
	std::cout << "Sum = " << n1 + n2 << std::endl;
	std::cout << "Time=" << time_s1 << std::endl;
	system("pause");
	return 0;


}
*/

/*
int main()
{

	int n3=0;
	std::cout << "Enter N : ";
	int N;
	
	std::cin >> N;
	for (size_t i = 0; i <= N; i++)
		n3 += i;
	auto time_s2 = clock();
	std::cout << "Sum = " << n3 << std::endl;
	std::cout << "Time=" << time_s2 << std::endl;
	system("pause");
	return 0;


}

*/









/*


int main() {
    std::cout << "Enter N : ";
    int N;
    std::cin >> N;
    int n1 = N;
    int n2 = N-1;
    std::thread fact1(fact_1, std::ref(n1));
    fact1.join();
    std::thread fact2(fact_2, std::ref(n2));
    fact2.join();
    auto time_f1 = clock();
    std::cout << "Fact(N) = " << n1 * n2 << std::endl;
	std::cout << "Time=" << time_f1 << std::endl;
    system("pause");
    return 0;
}

*/

/*
int main()
{

	long long n3 = 1;
	std::cout << "Enter N : ";
	int N;

	std::cin >> N;
	for (int i = 1; i <= N; i++)
		n3 *= i;
	auto time_f2 = clock();
	std::cout << "Factorial = " << n3 << std::endl;
	std::cout << "Time=" << time_f2 << std::endl;
	system("pause");
	return 0;

}

*/












/*
int main() {
std::cout << "Enter n : ";
int n;
std::cin >> n;
std::cout << "Enter k : ";
int k;
std::cin >> k;
int d = n - k;
long long C;
std::thread factN(fact, std::ref(n));
std::thread factK(fact, std::ref(k));
std::thread factN_K(fact, std::ref(d));
factN.join();
factK.join();
factN_K.join();
auto time_fs = clock();
C = n / k / d;
std::cout << "C(n)k = " << C << std::endl;
std::cout << "Time=" << time_fs << std::endl;
system("pause");
return 0;
}
*/



int _tmain(int argc, _TCHAR* argv[])
{
	int **pA, **pB, **pC;
	int n = 3, m = 4, l = 4;
	
	
	pA = new int *[n];
	pB = new int *[m];
	pC = new int *[n];
	std::cout << "A:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		pA[i] = new int[m];
		for (int j = 0; j < m; j++)
			std::cout << (pA[i][j] = rand() % 10) << " ";
		std::cout << std::endl;
		pC[i] = new int[l];
	}
	std::cout << "B:" << std::endl;
	for (int i = 0; i < m; i++)
	{
		pB[i] = new int[l];
		for (int j = 0; j < l; j++)
			std::cout << (pB[i][j] = rand() % 10) << " ";
		std::cout << std::endl;

	}
	
	std::thread ***pT = new std::thread **[n];
	for (int i = 0; i < n; i++) {
		pT[i] = new std::thread *[l]; // Создаем массив указателей на потоки
		for (int j = 0; j < l; j++)
		{
			pT[i][j] = new std::thread(MyMatr, pA, pB, pC, m, i, j); // Создаем поток для умножения i-й строки на j-й столбец 
		}
	}
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < l; j++)
		{
			pT[i][j]->join(); delete pT[i][j]; // Ожидаем завершения потоки и удаляем объект
		}
	}

	std::cout << "C:" << std::endl;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < l; j++)
			std::cout << pC[i][j] << " ";
		std::cout << std::endl;

	}

	auto time_fm = clock();
	std::cout << "Time=" << time_fm << std::endl;
	system("pause");
	return 0;
}



