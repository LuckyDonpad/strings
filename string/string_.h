//
// Created by Donpad on 27.02.2022.
//
#include <stdlib.h>

#ifndef PROJECT_STRING__H
#define PROJECT_STRING__H

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

// возвращает значение "истина" если символ a - пробел, иначе "ложь"
int isSpace(int a);

// возвращает значение истина если строки expected и got не равны, иначе "ложь"
int strcmp_(char *expected, char *got);

// крутой ассерт
void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

// возвращает длину строки begin
size_t strLen_(char *begin);

// возвращает указатель
// на первый элемент с кодом ch, расположенным на ленте памяти между
// адресами begin и end не включая end. Если символ не найден, возвращается значение end.
char *find(char *begin, char *end, int ch);

// возвращает адресс первого символа отличного от пробела в строке begin если возможно,
// иначе возвращает адрес первого ноль-символа
char *findNonSpace(char *begin);

// возвращает адресс первого символа пробела в строке begin если возможно,
// иначе возвращает адрес первого ноль-символа
char *findSpace(char *begin);

// возвращает адресс первого, с конца, символа отличного от пробела в строке begin если возможно,
// иначе возвращает адрес первого ноль-символа
char *findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает адресс первого, с конца, символа пробела в строке begin если возможно,
// иначе возвращает адрес первого ноль-символа
char *findSpaceReverse(char *rbegin, const char *rend);

//– записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource.
//Возвращает указатель на следующий свободный фрагмент памяти в destination
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

//– записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource
//заканчивая endSource, удовлетворяющие функции-предикату f. Функция возвращает указатель на
// следующий свободный для записи фрагмент в памяти.
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
// заканчивая rendSource, удовлетворяющие функции-предикату f. Функция возвращает
// значение beginDestination по окончанию работы функции.
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

// если в строке, насинающейся в beginSearch, есть слово (последовательность непробельных символов)
// возвращает значение "истина" и запишет в структуру word позиции начала и конца этого слова, иначе "ложь"
int getWord(char *beginSearch, WordDescriptor *word);

/// task 1

// удаляет все пробельные символы из строки string
void deleteSpaces(char *string);


/// task 2
// оставляет один пробел из каждой серии пробелов в строке string
void normalizeSpaces(char *string);

/// task 3

//

#endif //PROJECT_STRING__H
