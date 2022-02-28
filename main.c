#include "string/string_.h"
#include <assert.h>

void test_strLen__smokeTest() {
    char *s1 = "Hi";
    char s2[10] = "\tHello\t";

    assert(strLen_(s1) == 2 && strLen_(s2) == 7);
}

void test_find_smokeTest() {
    char *s1 = "Hi";
    assert(find(s1, &s1[2], 'i' ) == &s1[1]);
}


//void test_findNonSpace_smokeTest() {
//    char *s1 = "Hi";
//    assert(findNonSpace(s1) == &s1[0]);
//}
//
//void test_findNonSpace_onlySpaces() {
//    char *s1 = "   ";
//    assert(findNonSpace(s1) == &s1[3]);
//}
//
//void test_findSpace_onlySpaces() {
//    char *s1 = "   ";
//    assert(findSpace(s1) == &s1[0]);
//}
//
//void test_findSpace_noSpaces() {
//    char *s1 = "test";
//    assert(findSpace(s1) == &s1[4]);
//}
//
//void test_findNonSpaceReverse_noSpaces() {
//    char *s1 = "test";
//    assert(findNonSpaceReverse(s1 + 3, s1) == &s1[3]);
//}
//
//void test_findNonSpaceReverse_onlySpaces() {
//    char *s1 = "  ";
//    assert(findNonSpaceReverse(s1 + 2, s1) == &s1[2]);
//}
//
//void test_findSpaceReverse_onlySpaces() {
//    char *s1 = "  ";
//    assert(findSpaceReverse(s1 + 1, s1) == &s1[1]);
//}
//
//void test_findSpaceReverse_noSpaces() {
//    char *s1 = "test";
//    assert(findSpaceReverse(s1+4, s1) == &s1[4]);
//}

void test(){
    test_find_smokeTest();
    test_strLen__smokeTest();
    //test_findNonSpaceReverse_noSpaces();
    //test_findNonSpaceReverse_onlySpaces();
    //test_findNonSpace_onlySpaces();
    //test_findNonSpace_smokeTest();
    //test_findSpaceReverse_noSpaces();
    //test_findSpaceReverse_onlySpaces();
    //test_findSpace_noSpaces();
    //test_findSpace_onlySpaces();
}
int main() {
    test();
}