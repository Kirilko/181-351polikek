
#include "pch.h"
#include <iostream>
#include "Windows.h"

/* 1. Загрузка DLL в ОП
	HINSTANCE hDLL; - ссылка (указатель) на загруженную DLL, которая будет загружаться
	hDLL = LoadLibrary(L"Lab8.dll"); - L означает использование 16 - битных символов -- только для 64х
	std::cout << hDLL << endl; - проверка, загрузилась ли библиотека ( 0 если нет)
	
   2. Поиск в загруженной DLL функции по строковому имени
	FUNC2 fnc2explicit = (FUNC2)GetProcAddress(hDLL,"fnc2"); - поиск и возвращение указателя на функцию
	
   3. Вызов внешней функции
	std::cout << fnc2explicit << endl; - проверка, нашлась ли функция (0 если нет)*/
//Формат файла должен быть не .exe, а .dll

typedef int(CALLBACK * FUNC) (double, double, double);
//extern "C" __declspec(dllimport) void disc(double a, double b, double c);
int main()
{
	setlocale(LC_ALL, "Russian");

	HINSTANCE hDLL;
	hDLL = LoadLibrary(L"C:/Users/Kira/Desktop/Проекты/Labs/x64/Debug/Dll.dll");
	std::cout << hDLL << std::endl;
	FUNC discr = (FUNC)GetProcAddress(hDLL, "disc");
	std::cout << discr;
	//int a, b, c;
	//std::cout << "Введите коэффициенты: ";
	//std::cin >> a >> b >> c;
	//disc(a, b, c);
	}


