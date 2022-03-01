#include "string/string_.h"
#include <assert.h>
#include <string.h>
#include <iso646.h>

void test_strLen__smokeTest() {
    char *s1 = "Hi";
    char s2[10] = "\tHello\t";

    assert(strLen_(s1) == 2 && strLen_(s2) == 7);
}

void test_find_smokeTest() {
    char *s1 = "Hi";
    assert(find(s1, &s1[2], 'i') == &s1[1]);
}


void test_findNonSpace_smokeTest() {
    char *s1 = "Hi";
    assert(findNonSpace(s1) == &s1[0]);
}

void test_findNonSpace_onlySpaces() {
    char *s1 = "   ";
    assert(findNonSpace(s1) == &s1[3]);
}

void test_findSpace_onlySpaces() {
    char *s1 = "   ";
    assert(findSpace(s1) == &s1[0]);
}

void test_findSpace_noSpaces() {
    char *s1 = "test";
    assert(findSpace(s1) == &s1[4]);
}

void test_findNonSpaceReverse_noSpaces() {
    char *s1 = "test";
    assert(findNonSpaceReverse(s1 + 3, s1) == &s1[3]);
}

void test_findNonSpaceReverse_onlySpaces() {
    char *s1 = "  ";
    assert(findNonSpaceReverse(s1 + 1, s1) == &s1[0]);
}

void test_findSpaceReverse_onlySpaces() {
    char *s1 = "  ";
    assert(findSpaceReverse(s1 + 1, s1) == &s1[1]);
}

void test_findSpaceReverse_noSpaces() {
    char *s1 = "test";
    assert(findSpaceReverse(s1 + 3, s1) == &s1[0]);
}

void test_copy_smokeTest() {
    char s1[] = "test";
    char s2[] = "zoom";
    char *res = copy(&s1[0], &s1[3], &s2[0]);
    char s3[] = "test";
    assert(strcmp(s2, s3) == 0 and * res == '\0');
}

void test_copyIf_smokeTest() {
    char s1[] = "   t";
    char s2[] = "test";
    char *res = copyIf(&s1[0], &s1[3], &s2[0], isSpace);
    char s3[] = "   t";
    assert(strcmp(s2, s3) == 0 and * res == 't');
}

void test_copyIfReverse_smokeTest() {
    char s1[] = " 1 t";
    char s2[] = "test";
    char *res = copyIfReverse(&s1[3], &s1[0], &s2[0], isSpace);
    char s3[] = "  st";
    assert(strcmp(s2, s3) == 0 and *res == 's');
}

void test_deleteSpaces(){
    char s1[] = "t e s t ";
    char s2[] = "tests t ";
    deleteSpaces(s1);
    assert(strcmp(s2, s1) == 0);
}

void test() {
    test_find_smokeTest();
    test_strLen__smokeTest();
    test_findNonSpaceReverse_noSpaces();
    test_findNonSpaceReverse_onlySpaces();
    test_findNonSpace_onlySpaces();
    test_findNonSpace_smokeTest();
    test_findSpaceReverse_noSpaces();
    test_findSpaceReverse_onlySpaces();
    test_findSpace_noSpaces();
    test_findSpace_onlySpaces();
    test_copy_smokeTest();
    test_copyIf_smokeTest();
    test_copyIfReverse_smokeTest();
    test_deleteSpaces();
}

int main() {
    test();
}