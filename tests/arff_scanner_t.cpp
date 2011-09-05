#include <stdexcept>
#include <gtest/gtest.h>
#include <arff_scanner.h>


TEST(arff_scanner, good_usage) {
    ArffScanner sc("cases/case1.arff");
    char c = 'a';
    for(int i=0;i<26;++i,++c) {
        EXPECT_EQ(c, sc.next());
        EXPECT_EQ(1, sc.line());
        EXPECT_EQ(i+1, sc.column());
    }
    EXPECT_EQ('\n', sc.next());
    EXPECT_EQ('z', sc.previous());
    EXPECT_EQ('\n', sc.current());
    EXPECT_FALSE(sc.eof());
    c = 'A';
    for(int i=0;i<26;++i,++c) {
        EXPECT_EQ(c, sc.next());
        EXPECT_EQ(2, sc.line());
        EXPECT_EQ(i+1, sc.column());
    }
    EXPECT_EQ('\n', sc.next());
    EXPECT_FALSE(sc.eof());
    EXPECT_TRUE(sc.next() < 0);
    EXPECT_TRUE(sc.eof());
    EXPECT_TRUE(sc.is_newline(ArffScanner::NEWLINE));
    EXPECT_FALSE(sc.is_newline('\0'));
}

TEST(arff_scanner, bad_usage) {
    EXPECT_THROW(ArffScanner("does_not_exist"), std::runtime_error);
}
