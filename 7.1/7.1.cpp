#include <iostream>
#include <cmath>
#include <time.h>
#include <Windows.h>
#include <iomanip>

using namespace std;


void create_matrix(int** Q, const int rows, const int cols, const int Low, const int High)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			Q[i][j] = Low + rand() % (High - Low + 1);
	}
}

void print_matrix(int** Q, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << setw(4) << Q[i][j];
		cout << endl;
	}
	cout << endl;
}

void Change(int** Q, const int col1, const int col2, const int rows)
{
	int tmp;
	for (int i = 0; i < rows; i++)
	{
		tmp = Q[i][col1];
		Q[i][col1] = Q[i][col2];
		Q[i][col2] = tmp;
	}
}

void Sort(int** Q, const int rows, const int cols)
{
	for (int i0 = 0; i0 < cols - 1; i0++)
		for (int i1 = 0; i1 < cols - i0 - 1; i1++)
			if ((Q[0][i1] < Q[0][i1 + 1])
				|| (Q[0][i1] == Q[0][i1 + 1] && Q[1][i1] < Q[1][i1 + 1])
				|| (Q[0][i1] == Q[0][i1 + 1] && Q[1][i1] == Q[1][i1 + 1]
					&& Q[2][i1] < Q[2][i1 + 1]))
				Change(Q, i1, i1 + 1, rows);
}

int elements_counter(int** Q, const int rows, const int cols)
{
	int counter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			if (Q[i][j] % 2 == 0 && (i + j) % 8 !=0)
				counter++;
	}
	return counter;
}

int elements_sum(int** Q, const int rows, const int cols)
{
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			if (Q[i][j] % 2 == 0 && (i + j) % 8 != 0)
				sum += Q[i][j];
	}
	return sum;
}

void elements_replace(int** Q, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			if (Q[i][j] % 2 == 0 && (i + j) % 8 != 0)
				Q[i][j] = 0;
	}
}


int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 62;

	int rows = 7;
	int cols = 6;

	int** Q = new int* [rows];
	for (int i = 0; i < rows; i++)
		Q[i] = new int[cols];
	create_matrix(Q, rows, cols, Low, High);
	cout << "Q : " << endl;
	print_matrix(Q, rows, cols);

	Sort(Q, rows, cols);
	cout << "Sorted matrix : " << endl;
	print_matrix(Q, rows, cols);

	cout << "Elements amount : " << elements_counter(Q, rows, cols) << endl;
	cout << "Sum of elements : " << elements_sum(Q, rows, cols) << endl;
	elements_replace(Q, rows, cols);
	print_matrix(Q, rows, cols);

	return 0;
}

