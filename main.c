#include "string/string_.h"
#include <assert.h>
#include <string.h>
#include <iso646.h>
#include "string.h"
#include "stdio.h"

#define ASSERT_STRING(expected,got) assertString(expected, got, \
 __FILE__, __FUNCTION__, __LINE__ )


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
    assert(strcmp(s2, s3) == 0 and * res == 's');
}

void test_deleteSpaces() {
    char s1[] = "t e s t ";
    char s2[] = "tests t ";
    deleteSpaces(s1);
    assert(strcmp(s2, s1) == 0);
}

void test_normalizeSpaces_smokeTest() {
    char s1[] = "abc   efg  zxy o";
    char s2[] = "abc efg zxy o";
    normalizeSpaces(s1);
    assert(strcmp(s1, s2) == 0);
}

void test_normalizeSpaces_emptyString() {
    char s1[] = "";
    char s2[] = "";
    normalizeSpaces(s1);
    assert(strcmp(s1, s2) == 0);
}

void test_normalizeSpaces_onlySpaces() {
    char s1[] = "               ";
    char s2[] = " ";
    normalizeSpaces(s1);
    assert(strcmp(s1, s2) == 0);
}

void test_normalizeSpaces_noSpaces() {
    char s1[] = "testabc";
    char s2[] = "testabc";
    normalizeSpaces(s1);
    assert(strcmp(s1, s2) == 0);
}

void test_getWord_haveWord(){
    char s1[] = "   123";
    struct wordDescriptor word;

    assert(getWord(s1, &word) and *word.end == '\0' and *word.begin == '1');
}

void test_getWord_noWord(){
    char s1[] = "      ";
    struct wordDescriptor word;

    assert(getWord(s1, &word) == 0);
}

void test_getWordReverse_haveWord(){
    char s1[] = "   123";
    struct wordDescriptor word;

    assert(getWord(s1, &word) and *word.end == '\0' and *word.begin == '1');
}

void test_getWordReverse_noWord(){
    char s1[] = "      ";
    struct wordDescriptor word;

    assert(getWord(s1, &word) == 0);
}

void test_getMirroredWord_smokeTest(){
    char s1[] = "123456789";
    wordDescriptor word;
    getWord(s1, &word);
    getMirroredWord(word);
    ASSERT_STRING("987654321", s1);
}

void test_getMirroredWords_smokeTest(){
    char s1[] = "1 23 4567 89";
    wordDescriptor word;
    getWord(s1, &word);
    getMirroredWords(s1);
    ASSERT_STRING("1 32 7654 98", s1);
}

void test_areWordsEqual_wordsEqual(){
    char s1[] = "test";
    wordDescriptor word;
    getWord(s1, &word);
    assert(areWordsEqual(word, word) == 0);
}

void test_areWordsEqual_word1Bigger(){
    char s1[] = "testd";
    char s2[] = "testa";
    wordDescriptor word1;
    getWord(s1, &word1);
    wordDescriptor word2;
    getWord(s2, &word2);
    assert(areWordsEqual(word1, word2) == 1 );
}

void test_areWordsEqual_word1Lesser(){
    char s1[] = "testd";
    char s2[] = "testa";
    wordDescriptor word1;
    getWord(s1, &word1);
    wordDescriptor word2;
    getWord(s2, &word2);
    assert(areWordsEqual(word2, word1) == -1 );
}

void test_areWordsEqual_word1Shorter(){
    char s1[] = "test";
    char s2[] = "testtttt";
    wordDescriptor word1;
    getWord(s1, &word1);
    wordDescriptor word2;
    getWord(s2, &word2);
    assert(areWordsEqual(word1, word2) == -1 );
}

void test_areWordsEqual_word1Longer(){
    char s1[] = "testtttttttttt";
    char s2[] = "testtttt";
    wordDescriptor word1;
    getWord(s1, &word1);
    wordDescriptor word2;
    getWord(s2, &word2);
    assert(areWordsEqual(word1, word2) == 1 );
}

void test_areWordsIsOrderedLexicographically_isOrdered(){
    char s1[] = "abc efd h i j k l m nop";
    assert(areWordsIsOrderedLexicographically(s1));
}

void test_areWordsIsOrderedLexicographically_nonOrdered(){
    char s1[] = "abc efd x i z k l m nop";
    assert(!areWordsIsOrderedLexicographically(s1));
}

void test_splitter_smokeTest(){
    char s1[] = "abc,cd,efgg,";
    split(s1, ',');
    ASSERT_STRING("abc cd efgg ", s1);
}

void test_isPalindrome_Palindrome(){
    char s1[] = "abcxcba";
    wordDescriptor  word;
    getWord(s1, &word);
    assert(isPalindrome(word));
}

void test_getNPalindromes_3Palindromes(){
    char s1[] = "aba,zxz,xyz,ccc";
    assert(getNPalindromes(s1) == 3);
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
    test_normalizeSpaces_smokeTest();
    test_normalizeSpaces_emptyString();
    test_normalizeSpaces_onlySpaces();
    test_normalizeSpaces_noSpaces();
    test_getWord_haveWord();
    test_getWord_noWord();
    test_getWordReverse_noWord();
    test_getWordReverse_haveWord();
    test_getMirroredWord_smokeTest();
    test_getMirroredWords_smokeTest();
    test_areWordsEqual_word1Bigger();
    test_areWordsEqual_word1Lesser();
    test_areWordsEqual_word1Longer();
    test_areWordsEqual_word1Shorter();
    test_areWordsEqual_wordsEqual();
    test_areWordsIsOrderedLexicographically_isOrdered();
    test_areWordsIsOrderedLexicographically_nonOrdered();
    test_splitter_smokeTest();
    test_isPalindrome_Palindrome();
    test_getNPalindromes_3Palindromes();
}

int main() {
    test();
}