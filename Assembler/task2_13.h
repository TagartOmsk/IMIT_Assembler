#pragma once



namespace task2_13 {
	struct Human {
		char Name[30];
		int date;
	};

	Human create(char name[], int date) {
		Human human;
		__asm {
			lea		ebx, human
			mov		eax, ebx
			mov		esi, name //записываем строку в регистр 

			CYCLE :
			cmp		byte ptr[esi], 0
			je		NEXT

			mov		ch, [esi]
			mov		[ebx], ch
			inc		ebx
			inc		esi
			jmp		CYCLE

			NEXT :
			mov		[ebx], 0
			mov		ebx, eax
			add 	ebx, 32
			mov		edx, date
			mov		[ebx], edx //записываем дату 
			NO_MEMORY :

		}
		return human;
	}
}
