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
    return beginDestination;
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
    char *destination = copyIf(string, string + strLen_(string), string, isNotSpace);
    *destination = '\0';
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

/// task 4
/// task 5
//TODO разобраться как это сделать безопасно и без утечек памяти

/// task 6

int areWordsEqual(wordDescriptor word1, wordDescriptor word2) {
    int word1Len = word1.end - word1.begin;
    int word2Len = word2.end - word2.begin;
    int minLen = word1Len < word2Len ? word1Len : word2Len;
    int isEqual = 0;

    for (int i = 0; i < minLen; ++i) {
        if (*word1.begin != *word2.begin) {
            isEqual = *word1.begin > *word2.begin ? 1 : -1;
            break;
        } else {
            word1.begin++;
            word2.begin++;
        }
    }

    if (isEqual == 0) {
        if (word1Len != word2Len)
            isEqual = word1Len > word2Len ? 1 : -1;
    }

    return isEqual;
}

int areWordsIsOrderedLexicographically(char *string) {
    int isOrdered = 0;
    wordDescriptor word1;
    getWord(string, &word1);

    wordDescriptor word2;

    while (getWord(string, &word2) and isOrdered == 0) {
        string = word1.end;
        isOrdered = areWordsEqual(word1, word2) == 1;
        word1 = word2;
    }
    return isOrdered == 0;
}

/// task 7
void printWord(wordDescriptor word) {
    while (word.begin < word.end) {
        printf("%c", *word.begin);
        word.begin++;
    }
    printf("\n");
}

void printWordsFromEnd(char *string) {
    wordDescriptor word;
    char *strEnd = string + strLen_(string);
    getWordReverse(strEnd, string - 1, &word);
    while (getWordReverse(strEnd, string - 1, &word)) {
        printWord(word);
        strEnd = word.begin - 1;
    }
}

/// task 8
void split(char *string, char splitter) {
    while (*string != '\0') {
        if (*string == splitter)
            *string = ' ';
        string++;
    }
}

int isPalindrome(wordDescriptor word) {
    word.end--;
    int isPalindrome = 1;
    while (word.begin < word.end and isPalindrome) {
        isPalindrome = *word.begin == *word.end;
        word.end--;
        word.begin++;
    }
    return isPalindrome;
}

int getNPalindromes(char *string) {
    split(string, ',');
    wordDescriptor word;
    int nPalindromes = 0;
    while (getWord(string, &word)) {
        nPalindromes += isPalindrome(word);
        string = word.end;
    }
    return nPalindromes;
}

/// task 9
void mergeStringsByWord(char *s1, char *s2, char *resStr) {
    wordDescriptor word1, word2;
    int isFoundW1, isFoundW2;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isFoundW1 = getWord(beginSearch1, &word1)), (isFoundW2 = getWord(beginSearch2, &word2)), (isFoundW1 ||
                                                                                                      isFoundW2)) {
        if (isFoundW1) {
            resStr = copy(word1.begin, word1.end - 1, resStr);
            *resStr = ' ';
            resStr++;
            beginSearch1 = word1.end;
        }

        if (isFoundW2) {
            resStr = copy(word2.begin, word2.end - 1, resStr);
            *resStr = ' ';
            resStr++;
            beginSearch2 = word2.end;
        }
        *resStr = '\0';
    }
}

/// task 10

void makeWordsBackward(char *string) {
    int length = strLen_(string);
    copy(string, string+ length, _stringBuffer);
    *(_stringBuffer+length) = ' ';
    *(_stringBuffer+length + 1) = '\0';
    wordDescriptor word;

    if (getWordReverse(_stringBuffer+length, string, &word)){
        string = copy(word.begin,word.end,string);
        while(getWordReverse(word.begin - 1, _stringBuffer - 1, &word)){
            string = copy(word.begin,word.end,string);
        }
        *(string - (length != 1)) = '\0';
    }
}