

#include "pch.h"
#include <iostream>

char a[50] = {};
char func()
{
	for (int i = 0; i < strlen(a); i++) {
		a[i] += 3;
		if (((a[i] > 'Z') && (a[i] < 'a')) || (a[i] > 'z'))
			a[i] = a[i] - 26;
	}
	return 0;
}
int main()
{
	std::cin >> a;
	func();
	std::cout << a;
}
