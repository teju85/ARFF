#include <stdexcept>
#include <gtest/gtest.h>
#include <arff_token.h>

TEST(arff_token, arff_token2str) {
    EXPECT_EQ("RELATION", arff_token2str(RELATION));
    EXPECT_EQ("ATTRIBUTE", arff_token2str(ATTRIBUTE));
    EXPECT_EQ("DATA_TOKEN", arff_token2str(DATA_TOKEN));
    EXPECT_EQ("MISSING_TOKEN", arff_token2str(MISSING_TOKEN));
    EXPECT_EQ("NUMERIC_TOKEN", arff_token2str(NUMERIC_TOKEN));
    EXPECT_EQ("STRING_TOKEN", arff_token2str(STRING_TOKEN));
    EXPECT_EQ("DATE_TOKEN", arff_token2str(DATE_TOKEN));
    EXPECT_EQ("VALUE_TOKEN", arff_token2str(VALUE_TOKEN));
    EXPECT_EQ("BRKT_OPEN", arff_token2str(BRKT_OPEN));
    EXPECT_EQ("BRKT_CLOSE", arff_token2str(BRKT_CLOSE));
    EXPECT_EQ("END_OF_FILE", arff_token2str(END_OF_FILE));
    EXPECT_EQ("UNKNOWN", arff_token2str(UNKNOWN_TOKEN));
}


TEST(arff_token, ArffToken) {
    ArffToken at("@relation", RELATION);
    EXPECT_EQ("@relation", at.token_str());
    EXPECT_EQ(RELATION, at.token_enum());

    ArffToken copy(at);
    EXPECT_EQ("@relation", copy.token_str());
    EXPECT_EQ(RELATION, copy.token_enum());

    ArffToken num("12", VALUE_TOKEN);
    EXPECT_EQ(12, num.token_int32());
    EXPECT_FLOAT_EQ(12.0f, num.token_float());
    EXPECT_THROW(copy.token_int32(), std::runtime_error);
    EXPECT_THROW(copy.token_float(), std::runtime_error);
}
