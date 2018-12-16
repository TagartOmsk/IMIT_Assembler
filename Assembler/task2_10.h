#pragma once
#include <string.h>
/* ���������� � ����� ����������� �������� ������

     ������   ����   ������  ������������  ������  �  ��������  �������������
�����������   ����������   ��  ���������  �������������   ����.   �   �������
������������  �������  ����������  ��������  �������:  ��������  �   ��������
���������� ���������; ������ ���������� �� ������; ��������� ���� �����������
�� ��������, ���������� � ������� (���� ����); ��������, ��������� � �������.*/



namespace task2_10 {
	const int LINE_SIZE = 30;
	const int CARD_SIZE = LINE_SIZE*2;
	struct BookCard //������� ��������
     {
          char Author[LINE_SIZE];
		  char Title[LINE_SIZE];
     };

	/*10. ��������  �������,  ������� �� ���� �������� �������: ��� ������  �  ��������
	�����  (��������  ������  ���  ����������  �����  �����  �����)  �������  ���
	���������� ��������.*/
	BookCard *findCards(BookCard* cards, int arraySize, char *title, char *author, int &actualSize) {
		BookCard *res = new BookCard[arraySize];
		__asm {
			mov		eax, res;
			mov		esi, cards;
		NEXT_CARD:
			cmp	arraySize, 0;
			je	END;
		AUTHOR:
			xor		ecx, ecx;
			xor		ebx, ebx;
			mov		edi, author;
			mov		dh, byte ptr [edi];		first symbol
			mov		dl, byte ptr [edi];

			cmp		dh, 0;
			je		AUTH_ACCEPTANCE;
		AUTH_CYCLE:
			cmp		dh, byte ptr [esi + ebx];
			je		AUTH_CHECK;
            cmp     byte ptr[esi + ebx], 0;
            je      DENIAL;
			inc		ebx;
			jmp		AUTH_CYCLE;
		AUTH_CHECK:
			add		ecx, ebx;
			mov		dl, [esi + ecx];
			sub		ecx, ebx;
			cmp		dl, 0;
			je		AUTH_END;
			cmp		dl, [edi + ecx];
			jne		AUTH_POSTCHECK;
			inc		ecx;
			jmp		AUTH_CHECK;
		AUTH_POSTCHECK:
			cmp		byte ptr [edi + ecx], 0;
			je		AUTH_ACCEPTANCE;
			xor		ecx, ecx;
			jmp		AUTH_CYCLE;
		AUTH_END:
			cmp		dl, [edi + ecx];
			jne		DENIAL;
		AUTH_ACCEPTANCE:
			add		esi, LINE_SIZE;
            ; jmp		TITLE;

		TITLE:
			xor		ecx, ecx;
			xor		ebx, ebx;

			mov		edi, title;
			mov		dh, [edi];
			mov		dl, [edi];

			cmp		dh, 0;
			je		TITLE_ACCEPTANCE;
		TITLE_CYCLE:
			cmp		dh, byte ptr[esi + ebx];
			je		TITLE_CHECK;
            cmp     byte ptr[esi + ebx], 0;
            je      DENIAL;
			inc		ebx;
			jmp		TITLE_CYCLE;
		TITLE_CHECK:
			add		ecx, ebx;
			mov		dl, [esi + ecx];
			sub		ecx, ebx;
			cmp		dl, 0;
			je		TITLE_END;
			cmp		dl, [edi + ecx];
			jne		TITLE_POSTCHECK;
			inc		ecx;
			jmp		TITLE_CHECK;
		TITLE_POSTCHECK:
			cmp		byte ptr[edi + ecx], 0;
			je		TITLE_ACCEPTANCE;
			xor		ecx, ecx;
			jmp		TITLE_CYCLE;
		TITLE_END:
			cmp		dl, [edi + ecx];
			jne		DENIAL;
		TITLE_ACCEPTANCE:
			sub		esi, LINE_SIZE;
            mov     ebx, CARD_SIZE;
        ADD_RESULT:
            mov     dh, [esi];
            mov     [eax], dh;
            inc     eax;
            inc     esi;
            dec     ebx;
            cmp     ebx, 0;
            jne     ADD_RESULT;
            sub		arraySize, 1;
            mov     edi, actualSize;
            inc     [edi];
			jmp		NEXT_CARD;
		DENIAL:
			add		esi, CARD_SIZE;
			sub		arraySize, 1;
			jmp		NEXT_CARD;
        END:
		}
        return res;
	}
	
}