#include <gtest/gtest.h>
#include <arff_lexer.h>


#define TEST_ARFF(lex, e, s)                    \
    {                                           \
        ArffToken tok = lex.next_token();       \
        EXPECT_EQ(e, tok.token_enum());         \
        EXPECT_EQ(s, tok.token_str());          \
    }

TEST(arff_lexer, usage1) {
    ArffLexer lex("cases/case1.arff");
    TEST_ARFF(lex, VALUE_TOKEN, "abcdefghijklmnopqrstuvwxyz");
    TEST_ARFF(lex, VALUE_TOKEN, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    TEST_ARFF(lex, END_OF_FILE, "");
}

TEST(arff_lexer, usage2) {
    ArffLexer lex("cases/case2.arff");
    TEST_ARFF(lex, RELATION, "@relation");
    TEST_ARFF(lex, VALUE_TOKEN, "name");
    TEST_ARFF(lex, VALUE_TOKEN, "simple");
    TEST_ARFF(lex, VALUE_TOKEN, "tokens");
    TEST_ARFF(lex, VALUE_TOKEN, "are'nt present");
    TEST_ARFF(lex, VALUE_TOKEN, "lots");
    TEST_ARFF(lex, VALUE_TOKEN, "of");
    TEST_ARFF(lex, VALUE_TOKEN, "csv");
    TEST_ARFF(lex, VALUE_TOKEN, "data!");
    TEST_ARFF(lex, END_OF_FILE, "");
}

#undef TEST_ARFF
