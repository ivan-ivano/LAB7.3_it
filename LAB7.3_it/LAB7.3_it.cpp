#include <iostream>
#include <iomanip>

using namespace std;
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int sumInRowsWithNegative(int** a, const int rowCount, const int colCount);
void Part2_SaddlePoint(int** a, const int rowCount, const int colCount);
bool IsSaddlePoint(int** a, const int n, const int k, const int rowCount, const int colCount);

int main()
{
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	cout << "Sum elements in row with negative elements = " << sumInRowsWithNegative(a, rowCount, colCount) << endl << endl;
	Part2_SaddlePoint(a, rowCount, colCount);
	cout << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Input(int** a, const int rowCount, const int colCount)
{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int sumInRowsWithNegative(int** matrix, int rows, int cols) {
	int sum = 0;

	for (int i = 0; i < rows; ++i) {
		bool hasNegative = false;
		for (int j = 0; j < cols; ++j) {
			if (matrix[i][j] < 0) {
				hasNegative = true;
				break;
			}
		}
		if (hasNegative) {
			for (int j = 0; j < cols; ++j) {
				sum += matrix[i][j];
			}
		}
	}

	return sum;
}

bool IsSaddlePoint(int** a, const int n, const int k, const int rowCount, const int colCount)
{
	int element = a[n][k];
	
	for (int j = 0; j < colCount; j++) {
		if (a[n][j] < element) {
			return false;
		}
	}

	for (int i = 0; i < rowCount; i++) {
		if (a[i][k] > element) {
			return false;
		}
	}
	return true;
}

void Part2_SaddlePoint(int** a, const int rowCount, const int colCount)
{
	cout << "Saddle points: max in row & min in col" << endl;
	cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
	int No = 0;
	for (int n = 0; n < rowCount; n++) {
		for (int k = 0; k < colCount; k++) {
			if (IsSaddlePoint(a, n, k, rowCount, colCount)) {
				cout << setw(4) << ++No << setw(6) << n << setw(6) << k << endl;
			}
		}
	}
}
