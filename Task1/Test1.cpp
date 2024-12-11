#include <gtest/gtest.h>
#include "all_functions1.h"
TEST(SampleTest, TestEquality) {
    EXPECT_EQ(1 + 1, 2);
}

TEST(CountTest, TestNormPodschet) {
    const char* str1 = "11111 00000";
    EXPECT_EQ(Count(str1), 2);
}

TEST(CountTest, Testpustota) {
    const char* str6 = "";
    EXPECT_EQ(Count(str6), 0);
}
TEST(CountTest, TestInvalidInput1) {
    const char* str9 = "111110000011111";
    EXPECT_EQ(Count(str9), 0);
}
TEST(CountTest, TestInvalidInput2) {
    const char* str11 = "111 000 111";
    EXPECT_EQ(Count(str11), 0);
}
TEST(CountTest, TestInvalidInput3) {
    const char* str11 = "111000000 111    1111 0 0 0";
    EXPECT_EQ(Count(str11), 0);
}
TEST(CountTest, TestEdinica) {
    const char* str11 = "11111";
    EXPECT_EQ(Count(str11), 1);
}
TEST(CountTest, TestLimit) {
    const char* str11 = "11111 00000 11111 00000 11111 00000 11111 00000 11111 00000 11111 00000 111";
    EXPECT_EQ(Count(str11), 12);
}
TEST(CountTest, TestLimitNull1) {
    const char* str11 = "1 1 1 1 1 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0";
    EXPECT_EQ(Count(str11), 0);
}
TEST(CountTest, TestLimitNull2) {
    const char* str11 = "11111000001111100000111110000011111000001111100000111110000011111000001111100000";
    EXPECT_EQ(Count(str11), 0);
}
TEST(CountTest, TestSrednie) {
    const char* str11 = "11111 0000 11111 0000 11111 0000 11111 0000 11111 0000 11111 0000 1111";
    EXPECT_EQ(Count(str11), 6);
}



