// Lab5 - perehodi_i_cikli.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
/*int arr[10];
int* input_array()
{
	arr[10] = { 0 };
	for (int iter = 0; iter < 10; iter++)
	{
		std::cin >> arr[iter];
	}
	return arr;
}
*/

int num1 = 1, num2 = 2, res = 0;
int func(int num1, int num2)
{
	return(num1 + num2);
}
int main()
{
	/*input_array();
	for (int i = 0; i < 10; i++)
		std::cout << arr[i];*/
	res = func(num1, num2);
	std::cout << '\n' << res << " " << num1 << " " << num2;
}


