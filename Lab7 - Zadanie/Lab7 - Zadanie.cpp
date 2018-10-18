#include "pch.h"
#include <iostream>

class matrix {

private:
	int rows;
	int columns;
	double matr[10][10];
 
public:
	matrix();
	~matrix();

	bool input();
	void print();
	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	bool transp();

	int getRows();
	int getColumns();
	double getElem(int row, int col);
};


int main()
{

}

bool matrix::input()
{
	std::cin >> rows;
	if (rows < 1 || rows>10)
		return false;
	std::cin >> columns;
	if (columns < 1 || columns>10)
		return false;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cin >> matr[i][j];
		}
	}
	return true;
}

void matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matr[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

bool matrix::summMatrix(matrix matr2)
{
	double result[10][10];
	if ((rows == matr2.getRows()) && (columns == matr2.getColumns())) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				result [i][j] = matr[i][j] + matr2.getElem(i, j);
			}
		}
		return true;
	}
	else return false;
}

bool matrix::multMatrix(matrix matr2)
{
	double matr3[10][10];
	if (columns == matr2.getRows()) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < columns; j++) {
				for (int k = 0; k < columns; k++) {
					matr3[i][j] = matr[i][k] * matr2.getElem(k, j);
				}
			}
		}
		return true;
	}
	else return false;
}

bool matrix::transp() // не работает с неквадратынми матрицами. Доработать!
{
	for (int i = 0; i < rows; i++) {
		for (int j = i; i < columns; j++) {
			matr[i][j] = matr[j][i];
		}
	}
	return true;
}

int matrix::getRows()
{
	return rows;
}

int matrix::getColumns()
{
	return columns;
}

double matrix::getElem(int row, int col)
{
	if (row<rows && col<columns && row>-1 && col>-1)
		return matr[row][col];
	else
		return -11111111111;
	std::cout << "Error!\n";
	return -1;
}
