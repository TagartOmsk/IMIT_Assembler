#pragma once
/*������� ����������� �� Visual C++ (����� ������ � 2003) ��������������
������������ �������. � ���� ������� ���������� ��������� ���������������
�������������� ��� ������� ��� ��������. ������� ������ ���������� ��������
� ���� ����� ��� ��������� �����������, ���������� ������������ �������. ���
�������, � ������ ������� �� ����� ��� ���� ������� ������� ����
�������� �������� ������, ��������������� ������������ ��������, ������
��� �������� ������ ���������� �������� ������ � ������� ��� ���� ������
������������ �������. ����� ����, ��������� ������ ����� "�����������"
��������� (��������, ���������� ��������� ��������� ������������). ����
������ �� ����� �� ���������, ���� ��������������. ����/����� �
������� ��������� � ������� ������� printf � scanf, ����� �������
���� ������ ����������� ������ ������������ �������.*/

namespace task1_10 
{
	char* readString() 
	{
		char *string;
		const char *strLiteral = "%s", *anotherLiteral = " %[^\t\n]";
		__asm {
			mov eax, 1000
			push eax
			call malloc
			add esp, 4
			mov string, eax
			push eax
			mov eax, anotherLiteral
			push eax
			call scanf
			add esp, 8
		}
		return string;
	}



	// 10. �� �������� ������ ������� ��� ��������� �������� ������������������ ��������. 
	char* removeSubsequence() 
	{
		char *orig = readString(), *sub = readString(), *res;
		__asm {
			mov		eax, 1000
			push	eax
			call	malloc
			add		esp, 4
			mov		res, eax

			xor		ecx, ecx
			xor		ebx, ebx
			mov		esi, orig
			mov		edi, sub
			mov		eax, res

			mov		dh, [edi]; beginning of subsequence to remove
			mov		dl, [edi]; buffer

		CYCLE :
			cmp		byte ptr [esi], 0
			je		EXIT
			cmp		dh, [esi]
			je		CHECK

		BACK_TO_CYCLE :
			mov		dl, [esi]
			mov		[eax], dl
			inc		eax
			inc		esi
			jmp		CYCLE;

		CHECK :
			cmp		dl, 0;
			je		EXIT
			inc		ebx
			mov		dl, [esi + ebx]
			cmp		dl, [edi + ebx]
			jne		CHECK_ZERO
			je		CHECK
			

		SKIP_SEQ :
			add		esi, ebx
			xor		ebx, ebx
			jmp		CYCLE

		CHECK_ZERO :
			cmp		byte ptr [edi + ebx], 0
			jne		BACK_TO_CYCLE
			cmp		byte ptr [esi + ebx], 0
			jne		SKIP_SEQ

		EXIT :
			mov		byte ptr [eax], 0
			push	sub
			call	free
			add		esp, 4
			push	orig
			call	free
			add		esp, 4
		}
		return res;
	}
}