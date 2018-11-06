#pragma once
/*Задание выполняется на Visual C++ (любая версия с 2003) использованием
ассемблерных вставок. В этом задании необходимо выполнить соответствующие
преобразования над строкой или строками. Решение задачи необходимо оформить
в виде одной или несколько подпрограмм, содержащих ассемблерные вставки. Как
правило, в каждом задании по одной или двум входным строкам надо
получить выходную строку, удовлетворяющую определенным условиям, причем
под выходную строку необходимо выделить память и сделать это надо внутри
ассемблерной вставки. Кроме того, программа должна иметь "дружелюбный"
интерфейс (например, предлагать выполнить повторное тестирование). Ввод
данных из файла не требуется, хотя приветствуется. Ввод/вывод с
консоли выполнять с помощью функций printf и scanf, вызов которых
тоже должен происходить внутри ассемблерных вставок.*/

namespace task1_10 {
	char* readString() {
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



	// 10. Из исходной строки удалить все вхождения заданной последовательности символов. 
	char* removeSubsequence() {
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
			cmp[esi], 0
				je		EXIT
				cmp		dh, [esi]
				je		CHECK

				BACK_TO_CYCLE :
			mov		dl, [esi]
				mov[eax], dl
				inc		eax
				inc		esi
				jmp		CYCLE

				CHECK :
			inc		ebx
				mov		dl, [esi + ebx]
				cmp		dl, [edi + ebx]
				je		CHECK
				jne		CHECK_ZERO

				SKIP_SEQ :
			add		esi, ebx
				xor		ebx, ebx
				jmp		CYCLE

				CHECK_ZERO :
			cmp[edi + ebx], 0
				jne		BACK_TO_CYCLE
				cmp[esi + ebx], 0
				jne		SKIP_SEQ

				EXIT :
			mov[eax], 0
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