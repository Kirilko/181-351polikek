
#include "pch.h"
#include <iostream>

int main()
{
	int a[3][3] = { {1,2,3},
				   {4,5,6},
				   {7,8,9} };
	int b[3][3] = { {9,8,7},
				   {6,5,4},
				   {3,2,1} };
	int c[3][3] = { 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			std::cout << c[i][j] << '\t';
		}
		std::cout << '\n';
	}
}
	

/* массив - блок однотипных данных, им удобно задавать: 
	1) вектора и матрицы
	2) множество точек из 2D или 3D геометрии
	3) просто какой-либо числовой ряд, таблица и т.д.
	4) строка - массив символов
	5) видеобуфер(двумерный массив, соответствующий пикселям экрана
	*/	
	//int arr[5] = {1, 5, 15, 12, 101} одномерный массив из 5 знаковых чисел

	/*Синтаксис объявления массива:
		тип_данных имя_массива [размер]
		тип_данных имя_массива [размер] = {значение_для_всех}
		тип_данных имя_массива [размер] = {значение1,значение2,значение3}
		int a[3][3] = {{a11,a12,a13},
					  {a21,a22,a23},
					  {a31,a32,a33}}
		a[1][2] = a12

		int a[3][3] = {{0}} - занулить весь массив
	*/

	// обращение к элементам массива: имя_массива[индекс]

	