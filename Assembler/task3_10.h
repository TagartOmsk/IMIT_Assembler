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
			ja		CHECK_SECTION;
			//������ ������� ���� �������;
			finit;
		CHECK_SECTION:
			sub		esp, 8;
			fst		qword ptr [esp];
			call	pf;
			fld		st(2);
			fstp	qword ptr[esp];
			call	pf;
			add		esp, 8;
			fmulp	st(1), st(0);
			fldz;
			fcomip	st(0), st(1);
			jb		END;
			jz		ZERO;
			
			; TODO code here;
			fstp	st(0);

			
		ZERO:
			fstp	st(0);
			sub		esp, 8;
			fst		qword ptr [esp];
			call	pf;
			fldz;
			fcomip	st(0), st(1);
			fstp	st(0);
			jz		END;
			fstp	st(0);
			fstp	st(0);

			add		esp, 8;

		END:
		}
	}
}