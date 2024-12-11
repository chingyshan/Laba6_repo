#include <gtest/gtest.h>
#include "all_functions.h"
TEST(SampleTest, Addition) {
    EXPECT_EQ(1 + 1, 2);
}
TEST(TextTest, SingleSymbol_Kirrilica) {
    const char* str1 = "а";
    EXPECT_EQ(calculate_sum(str1), 384);
}
TEST(TextTest, SingleSymbol_Latinica) {
    const char* str1 = "a";
    EXPECT_EQ(calculate_sum(str1), 97);
}
TEST(TextTest, ZerkaloTest_Kirillica_only) {
    const char* input = "Привет";
    int size = 12;
    char* reversed = zerkalo(input, size);
    const char* expected = "тевирП";
    EXPECT_STREQ(reversed, expected);
}
TEST(TextTest, ZerkaloTest_Kirillica_only2) {
    const char* input = "лололошка";
    int size = 18;
    char* reversed = zerkalo(input, size);
    const char* expected ="акшололол";
    EXPECT_STREQ(reversed, expected);
}
TEST(TextTest, Empty) {
    const char* input = "";
    int size = 0;
    char* reversed = zerkalo(input, size);
    EXPECT_STREQ(reversed, "");
    delete[] reversed;
}
TEST(TextTest, Mixed) {

    const char* input = "abcПривет";
    int size = 15;
    char* reversed = zerkalo(input, size);
    const char* expected = "тевирПcba";
    EXPECT_STREQ(reversed, expected);
    delete[] reversed;
}
TEST(TextTest, ZerkaloTest_Latinica_only) {
    const char* input = "hello world";
    int size = 11;
    char* reversed = zerkalo(input, size);
    const char* expected = "dlrow olleh";
    EXPECT_STREQ(reversed, expected);
    delete[] reversed;
}
TEST(TextTest, ZerkaloTest_Latinica_only2) {
    const char* input = "all my niggas";
    int size = 13;
    char* reversed = zerkalo(input, size);
    const char* expected = "saggin ym lla";
    EXPECT_STREQ(reversed, expected);
    delete[] reversed;
}
TEST(TextTest, Mixed2) {

    const char* input = "йоу у меня есть glock-18";
    int size = 36;
    char* reversed = zerkalo(input, size);
    const char* expected = "81-kcolg ьтсе янем у уой";
    EXPECT_STREQ(reversed, expected);
    delete[] reversed;
}
TEST(TextTest, MixedSymbols) {
    const char* str1 = "друг--friend";
    EXPECT_EQ(calculate_sum(str1), 2174);
}
