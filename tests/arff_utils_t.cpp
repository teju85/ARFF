#include <stdexcept>
#include <gtest/gtest.h>
#include <arff_utils.h>



TEST(arff_utils, throw_ex) {
    EXPECT_THROW(throw_ex("file", 1, "error!"), std::runtime_error);
}

TEST(arff_utils, num2str) {
    EXPECT_EQ("20", num2str<int>(20));
    EXPECT_EQ("20.1", num2str<float>(20.1));
}

TEST(arff_utils, str2num) {
    int num1;
    float num2;
    str2num("20", num1);
    EXPECT_EQ(20, num1);
    str2num("20.1", num2);
    EXPECT_FLOAT_EQ(20.1f, num2);
    EXPECT_THROW(str2num("abc", num1), std::runtime_error);
}

TEST(arff_utils, to_lower) {
    EXPECT_EQ('a', to_lower('A'));
    EXPECT_EQ('a', to_lower('a'));
    EXPECT_EQ('@', to_lower('@'));
}

TEST(arff_utils, icompare) {
    EXPECT_TRUE(icompare("ABC", "abc"));
    EXPECT_TRUE(icompare("AbC", "aBc"));
    EXPECT_TRUE(icompare("@ABC", "@abc"));
    EXPECT_FALSE(icompare("@ABC13", "@abc12"));
    EXPECT_FALSE(icompare("", "data!"));
    EXPECT_TRUE(icompare("", ""));
}
