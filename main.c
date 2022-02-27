#include "string/tasks/string_.h"
#include <stdio.h>
#include <assert.h>

test_strlen__smokeTest() {
    char *s1 = "Hi";
    char s2[10] = "\tHello\t";

    assert(strlen_(s1) == 2 && strlen_(s2) == 7);
}

int main() {
    test_strlen__smokeTest();
}