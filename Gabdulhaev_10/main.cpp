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

//��������� ����� �������
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

	cout << "��������� ��� ������� ������� � ����������" << endl;

	ifstream f1("f1.txt");

	int** matrix = new int*[10]; //������� (��������� �� ������)

	// ���� ���� ����������
	if (!f1.good())
	{
		create_file();
	}
	f1 = ifstream("f1.txt");

	for (int i = 0; i < 10; i++)
	{
		matrix[i] = new int[15]; //�������� ������ ��� ������
		for (int j = 0; j < 15; j++)
		{
			int t;
			f1 >> t;
			matrix[i][j] = t;
		}
	}
	f1.close();

	// 1 - �������
	// 2 - ����������
	// 3 - ��������

	double k1, k2, k3;
	cout << "������� ���� �������� ������: ";
	cin >> k1;
	cout << "������� ���� ����������� ������: ";
	cin >> k2;
	cout << "������� ���� ��������� ������: ";
	cin >> k3;

	cout << "�� ����� �������\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cout << setw(2) << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	//��������� �������
	double total = proc_matrix(matrix, k1, k2, k3);

	cout << "��������� ��������� �������: " << total << "\n";

	system("pause");

	return 0;
}
