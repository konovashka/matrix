// Дана квадратная матрица, найти скалярное произведение столбца и строки, которые содержат совершенное число

#include <iostream>
using namespace std;
int** memory(int n, int m);
void fill(int** a, int n, int m);
int sp(int* arr1, int* arr2, int n);
bool number(int** a, int n, int m, int& is, int& js);
int* mass(int n, int js, int** A);
int main()
{
	int n, m;
	printf("vvedite razmernost'\n");
	scanf_s("%d\n", &n);
	scanf_s("%d\n", &m);
	int** A = memory(n, m);
	printf("zapolnite massiv\n");
	fill(A, n, m);
}
//выделение памяти
int** memory(int n, int m)
{
    int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	return a;
}
//заполнение элементов
void fill(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
}
//вычисление скалярного произведения
int sp(int* arr1, int* arr2, int n)
{
	int sp = 0;
	for (int i = 0; i < n; i++)
	{
		sp = sp + (arr1[i] * arr2[i]);
	}
	return sp;
}
//проверка на соверенность
bool sovv(int n)
{
	int sd = 1;
	int n1 = n / 2;
	for (int i = 2; i < n1; i++)
	{
		if (n % i == 0)

			sd = sd + i;
	}
	if (sd == n)
		return true;
	else
		return false;
}
//поиск совершенного числа в матрице
bool number(int** a, int n, int m, int& is, int& js)
{
	is = js = -1;
	bool fl = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (sovv(a[i][j]))
			{
				is = i;
				js = j;
				fl = true;
				break;
			}
		}
		if (fl)
			break;
	}
	return fl;
}
//создание и заполнение массива
int* mass(int n,int js, int** A)
{
	int* arr2 = new int [n];
	for (int i = 0; i < n; i++)
	{
		arr2[i] = A[i][js];
	}
	return arr2;
}