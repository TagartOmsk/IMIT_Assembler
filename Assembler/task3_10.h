#pragma once
#include <cmath>
/*Нахождение корней уравнений

     Найти  корень уравнения f(x)=0 на отрезке [a, b] с погрешностью epsilon,
если известно, что корень на указанном отрезке всего один, методом, указанным
в задании.
     Решение оформить в виде функции
     double  имя_метода(double  a,  double b,  double  (*pf)(double),  
			double epsilon = 1e-2);.*/

//10.   Метод  деления отрезка пополам. В качестве примера, решите  уравнения cos(x) = 0, ln(x) = 0 и exp(x) - 1 / x = 0 на отрезке[a, b].

namespace task3_10 {
	double exp(double x) {
		return std::exp(x) - 1 / x;
	}
	double getRoots(double a, double b, double (*pf)(double), double epsilon = 1e-2) {
		__asm {
			finit;
			fld		epsilon;
			fld		a;
			fld		b;
			fcomi	st(0), st(1);
			jg		CORRECT_SECTION;
			// меняем местами края отрезка 
		CORRECT_SECTION:

		}
	}
}