//(Рекурсивний спосіб)(1 Завдання)
#include <iostream>
#include <Windows.h>
#include <iomanip>

void matriz_create(int** matriz, const int line, const int column, int index, int index_j);
void matriz_print(int** matriz, const int line, const int column, int index, int index_j);
int matriz_sum(int** matriz, const int line, const int column, int index, int index_jl, int sum);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	using std::cout;
	using std::endl;
	using std::cin;

	int line = 3;
	int column = 3;

	int** matriz = new int* [line];
	for (int index = 0; index < line; index++)
		matriz[index] = new int[column];

	matriz_create(matriz, line, column, 0, 0);
	cout << "Сформований масив: " << endl;
	cout << endl;
	matriz_print(matriz, line, column, 0, 0);
	cout << endl;

	int suma = matriz_sum(matriz, line, column, 0, 0, 0);
	cout << endl;
	cout << "Сума елементів матриці за вказаним критерієм: " << suma << endl;
	cout << endl;

	delete[] matriz;

	return 0;
}


void matriz_create(int** matriz, const int line, const int column, int index, int index_j)
{
	using std::cout;
	using std::endl;
	using std::cin;
	cout << "a[" << index << "][" << index_j << "] = ";
	cin >> matriz[index][index_j];
	if (index_j < column - 1)
		matriz_create(matriz, line, column, index, index_j + 1);
	else
		if (index < line - 1)
		{
			cout << endl;
			matriz_create(matriz, line, column, index + 1, 0);
		}
		else
			cout << endl;
}

void matriz_print(int** matriz, const int line, const int column, int index, int index_j)
{
	using std::cout;
	using std::endl;
	cout << std::setw(4) << matriz[index][index_j];
	if (index_j < column - 1)
		matriz_print(matriz, line, column, index, index_j + 1);
	else
		if (index < line - 1)
		{
			cout << endl;
			matriz_print(matriz, line, column, index + 1, 0);
		}
}

int matriz_sum(int** matriz, const int line, const int column, int index, int index_jl, int sum)
{
	if (matriz[index][index_jl] < 0)
	{
		for (int index_j = 0; index_j < column; index_j++)
			sum += matriz[index][index_j];
		index_jl = column;
	}
	if (index_jl < column - 1)
		matriz_sum(matriz, line, column, index, index_jl + 1, sum);
	else
		if (index < line - 1)
			return matriz_sum(matriz, line, column, index + 1, 0, sum);
		else
			return sum;
}