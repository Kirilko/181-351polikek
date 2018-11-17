
#include "pch.h"
#include <iostream>
#include <math.h>
#include "Dll.h"

void disc(double a, double b, double c) {
	double d;
	d = b * b - 4*a*c;
	if (d < 0) {
		std::cout << "Нет корней";
	}
	else {
		double x1, x2;
		x1 = (sqrt(d)-b)/(2*a);
		x2 = (0 - sqrt(d) - b) / (2 * a);
		std::cout << "Корни: " << x1 << " " << x2;
	}
}