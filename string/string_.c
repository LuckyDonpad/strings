//
// Created by Donpad on 27.02.2022.
//
#define ASSERT_STRING ( a , b ) assertString ( expected , got , \
 __FILE__ , __FUNCTION__ , __LINE__ )

#include "string_.h"
#include <iso646.h>
#include <string.h>
#include <stdio.h>
#include "string.h"

# define MAX_STRING_SIZE 100
# define MAX_N_WORDS_IN_STRING 100
# define MAX_WORD_SIZE 20

char _stringBuffer[MAX_STRING_SIZE + 1];

int strcmp_(char *expected, char *got) {
    return strcmp(expected, got) != 0;
}

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

int isSpace(int a) {
    return a == ' ';
}

int isNotSpace(int a) {
    return !isSpace(a);
}

size_t strLen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin == ' ')
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != ' ' and *begin != '\0')
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend and *rbegin == ' ') {
        rbegin--;
    }

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend and *rbegin != ' ') {
        rbegin--;
    }

    return rbegin;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource + 1);

    return beginDestination + (endSource - beginSource) + 1;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            memcpy(beginDestination, beginSource, sizeof(char));
            beginDestination++;
        }
        beginSource++;
    }
    return beginSource;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource + 1 != rendSource) {
        if (f(*rbeginSource)) {
            memcpy(beginDestination, rbeginSource, sizeof(char));
            beginDestination++;
        }
        rbeginSource--;
    }
    return beginDestination;
}

int getWord(char *beginSearch, wordDescriptor *word) {
    int isFound = 0;
    while (*beginSearch != '\0' and isFound != 1) {
        if (!isSpace(*beginSearch))
            isFound = 1;
        else
            beginSearch += 1;
    }

    if (isFound)
        word->begin = beginSearch;

    while (isFound and *beginSearch != ' ' and *beginSearch != '\0') {
        beginSearch += 1;
    }

    if (isFound)
        word->end = beginSearch;

    return isFound;
}

int getWordReverse(char *rbegin, char *rend, wordDescriptor *word) {
    int isFound = 0;
    while (rbegin != rend and isFound != 1) {
        if (!isSpace(*rbegin))
            isFound = 1;
        else
            rbegin -= 1;
    }

    if (isFound)
        word->end = rbegin + 1;

    while (isFound and *rbegin != ' ' and rbegin != rend) {
        rbegin -= 1;
    }

    if (isFound)
        word->begin = rbegin + 1;

    return isFound;
}


/// task 1
void deleteSpaces(char *string) {
    copyIf(string, string + strLen_(string), string, isNotSpace);
}

/// task 2

void normalizeSpaces(char *string) {
    char *iRead = findSpace(string);
    char *iWrite = iRead + 1;
    while (*iRead != '\0' and *iWrite != '\0') {
        while (*iRead == ' ') {
            iRead += 1;
        }
        while (*iRead != ' ' and *iWrite != '\0' and *iRead != '\0') {
            *iWrite = *iRead;
            iRead += 1;
            iWrite += 1;
        }
        if (*iWrite != '\0' and *iRead != '\0') {
            *iWrite = *iRead;
            iWrite += 1;
        }
    }
    *iWrite = '\0';
}

/// task 3

void getMirroredWord(wordDescriptor word) {
    while (word.end > word.begin) {
        swap(word.end - 1, word.begin);
        word.end--;
        word.begin++;
    }
}

void getMirroredWords(char *begin) {
    wordDescriptor word;
    while (getWord(begin, &word)) {
        getMirroredWord(word);
        begin = word.end;
    }
}