#pragma once
#include <cmath>
/*���������� ������ ���������

     �����  ������ ��������� f(x)=0 �� ������� [a, b] � ������������ epsilon,
���� ��������, ��� ������ �� ��������� ������� ����� ����, �������, ���������
� �������.
     ������� �������� � ���� �������
     double  ���_������(double  a,  double b,  double  (*pf)(double),  
			double epsilon = 1e-2);.*/

//10.   �����  ������� ������� �������. � �������� �������, ������  ��������� cos(x) = 0, ln(x) = 0 � exp(x) - 1 / x = 0 �� �������[a, b].

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
			// ������ ������� ���� ������� 
		CORRECT_SECTION:

		}
	}
}