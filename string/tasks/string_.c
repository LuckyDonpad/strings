//
// Created by Donpad on 27.02.2022.
//

#include "string_.h"

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
    end++;
    return end - begin;
}