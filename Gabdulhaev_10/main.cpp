#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

double sum_row(int** matrix, int row_index, double k1, double k2, double k3)
{
	double sum = 0;
	double multiplier = 1;
	if (row_index >= 3 && row_index < 7)
	{
		multiplier = 2;
	}
	for (int j = 0; j < 15; j++)
	{
		switch (matrix[row_index][j])
		{
		case 1: sum += multiplier * k1;
			break;
		case 2: sum += multiplier * k2;
			break;
		case 3: sum += multiplier * k3;
			break;
		}
	}
	return sum;
}

//обработка целой матрицы
double proc_matrix(int** matrix, double k1, double k2, double k3)
{
	double sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		sum += sum_row(matrix, i, k1, k2, k3);
	}

	return sum;
}

void create_file()
{
	ofstream f1("f1.txt");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			f1 << (rand() % 3 + 1) << " ";
		}
		f1 << "\n";
	}
	f1.close();
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Программа для расчёта билетов в кинотеатре" << endl;

	ifstream f1("f1.txt");

	int** matrix = new int*[10]; //матрица (указатель на строки)

	// если файл существует
	if (!f1.good())
	{
		create_file();
	}
	f1 = ifstream("f1.txt");

	for (int i = 0; i < 10; i++)
	{
		matrix[i] = new int[15]; //выделяем память под строку
		for (int j = 0; j < 15; j++)
		{
			int t;
			f1 >> t;
			matrix[i][j] = t;
		}
	}
	f1.close();

	// 1 - обычный
	// 2 - премьерный
	// 3 - льготный

	double k1, k2, k3;
	cout << "Введите цену обычного билета: ";
	cin >> k1;
	cout << "Введите цену премьерного билета: ";
	cin >> k2;
	cout << "Введите цену льготного билета: ";
	cin >> k3;

	cout << "Вы ввели матрицу\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cout << setw(2) << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	//обработка матрицы
	double total = proc_matrix(matrix, k1, k2, k3);

	cout << "Суммарная стоимость билетов: " << total << "\n";

	system("pause");

	return 0;
}
