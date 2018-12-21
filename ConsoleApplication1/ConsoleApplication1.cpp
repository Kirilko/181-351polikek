// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

class myClass {

private:
	char *p;
	int length;
public:
	myClass();
	~myClass();

	void input();
	void print();
	void clear(char p);
	void add(char *p);
	void add(std::string *p);
};
int main() {
	myClass a;
	a.input();
	a.print();
}
void myClass::input()
{
	std::cin >> length;
	p = new char[length];
	for (int i = 0; i < length; i++) {
		std::cin >> p[i];
	}
}

void myClass::print()
{
	for (int i = 0; i < length; i++) {
		std::cout << p[i] << ' ';
	}
	std::cout << std::endl;
}
