#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include "task1_10.h"
#include "task2_10.h"
#include "task3_10.h"
//Устюгов

/*Задание    выполняется    на  Visual C++ (любая версия с 2003) использованием
ассемблерных  вставок.  В этом   задании необходимо выполнить соответствующие
преобразования над  строкой или строками. Решение задачи необходимо  оформить
в  виде одной или несколько подпрограмм, содержащих ассемблерные вставки. Как
правило,  в   каждом  задании   по  одной  или   двум  входным  строкам  надо
получить   выходную  строку, удовлетворяющую  определенным  условиям,  причем
под  выходную строку необходимо  выделить  память и сделать это  надо  внутри
ассемблерной  вставки. Кроме   того,  программа  должна  иметь  "дружелюбный"
интерфейс   (например, предлагать  выполнить  повторное  тестирование).  Ввод
данных   из   файла    не  требуется,   хотя   приветствуется.  Ввод/вывод  с
консоли   выполнять   с  помощью функций  printf  и  scanf,   вызов   которых
тоже  должен  происходить   внутри ассемблерных вставок.*/

// 10.     Из     исходной     строки    удалить   все    вхождения     заданной последовательности символов.


int main() {
	//printf("just read: %s\n", task1_10::readString());
	//printf("just read: %s\n", task1_10::readString());
	//printf("%s\n", task1_10::removeSubsequence());
	/*const int ARR_SIZE = 4;
	task2_10::BookCard *cardList = new task2_10::BookCard[ARR_SIZE];
	
	strcpy_s(cardList[0].Title, task2_10::LINE_SIZE, "Call of Chtulhu");
	strcpy_s(cardList[0].Author, task2_10::LINE_SIZE, "H.Lovecraft");
	strcpy_s(cardList[1].Title, task2_10::LINE_SIZE, "Call of Duty");
	strcpy_s(cardList[1].Author, task2_10::LINE_SIZE, "A.Lovelace");
	strcpy_s(cardList[2].Title, task2_10::LINE_SIZE, "Inline Assembly");
	strcpy_s(cardList[2].Author, task2_10::LINE_SIZE, "V.Ustyugov");
	strcpy_s(cardList[3].Title, task2_10::LINE_SIZE, "Meow");
	strcpy_s(cardList[3].Author, task2_10::LINE_SIZE, "L.Meow");
	int res_size = 0;
	task2_10::BookCard *result = task2_10::findCards(cardList, ARR_SIZE, (char*)"C", (char*)"A", res_size);
    printf("found %d cards\n", res_size);
    for(int i = 0; i < res_size; i++)
    {
        printf("Author: %s\n", result[i].Author);
        printf("Title: %s\n\n", result[i].Title);
    }*/

	printf("%.12f\n", task3_10::getRoots(0.01, 2, std::log, 0.001));	
	//printf("%.12f\n", std::log(0.003));
	//printf("%.12f\n", std::log(3));
	system("pause");
	return 0;
}