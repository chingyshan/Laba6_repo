#include <gtest/gtest.h>
#include "all_functions.h"
TEST(SampleTest, AddNumbers) {
    EXPECT_EQ(1 + 1, 2);
}
TEST(CountWordsFunction, CountsCorrectly) {
    EXPECT_EQ(countW("hello world"), 2);
}
TEST(CountWordsFunction, Empty) {
    EXPECT_EQ(countW(""), 0);
}
TEST(CountWordsFunction, space1) {
    EXPECT_EQ(countW(" "), 0);
}
TEST(CountWordsFunction, space2) {
    EXPECT_EQ(countW("  "), 0);
}
TEST(CountWordsFunction, space2_between_words) {
    EXPECT_EQ(countW("  pisun  lol"), 2);
}
TEST(CountWordsFunction, space1_between_words) {
    EXPECT_EQ(countW(" pisun lol"), 2);
}
TEST(CountWordsFunction, oneword) {
    EXPECT_EQ(countW("pisun"), 1);
}
TEST(CountWordsFunction, symbols) {
    EXPECT_EQ(countW("pisun_lox_ty_voobshe"), 1);
}
TEST(CountWordsFunction, weird) {
    EXPECT_EQ(countW("                                                                                                                            123"), 1);
}

TEST(DeleteFunction, FreesMemory) {
    int size = 10;
    char* text = create(size);
    DELETING(text, size);
    SUCCEED();
}