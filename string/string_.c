//
// Created by Donpad on 27.02.2022.
//

#include "string_.h"
#include <iso646.h>

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
    while (*begin != ' ' and *begin !='\0')
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend){
    while (rbegin!=rend and *rbegin==' '){
        rbegin--;
    }
    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend){
    while (rbegin!=rend and *rbegin!=' '){
        rbegin--;
    }
    return rbegin;
}