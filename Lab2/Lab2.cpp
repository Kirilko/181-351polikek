
#include "pch.h"
#include <iostream>


int main()
{
	std::cout << "TYPE" << "\t" << "\t" << "SIZE" << "\t" << "MIN" << "\t" << "\t" << "\t" << "MAX" << "\n";
	std::cout << "int" << "\t" << "\t" << sizeof(int) << "\t" << INT32_MIN << "\t" << "\t" << INT32_MAX<<"\n";
	std::cout << "long" << "\t" << "\t" << sizeof(long) << "\t" << LONG_MIN << "\t" << "\t" << LONG_MAX << "\n";
	std::cout << "double" << "\t" << "\t" << sizeof(double) << "\t" << DBL_MIN << "\t" << "\t" << DBL_MAX << "\n";
	std::cout << "short" << "\t" << "\t" << sizeof(short) << "\t" << SHRT_MIN << "\t" << "\t" << "\t" << SHRT_MAX << "\n";
	std::cout << "char" << "\t" << "\t" << sizeof(char) << "\t" << CHAR_MIN << "\t" << "\t" << "\t" << CHAR_MAX << "\n";
	std::cout << "bool" << "\t" << "\t" << sizeof(bool) << "\t" << 0 << "\t" << "\t" << "\t" << 1 << "\n";
	std::cout << "long long" << "\t" << sizeof(long long) << "\t" << LLONG_MIN << "\t" << LLONG_MAX<< "\n";
}

// Д/З : Шифр Цезаря; Решето Эратосфена
