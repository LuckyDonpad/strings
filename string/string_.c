//
// Created by Donpad on 27.02.2022.
//

#include "string_.h"

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