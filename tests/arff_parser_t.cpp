#include <stdexcept>
#include <gtest/gtest.h>
#include <arff_parser.h>



TEST(arff_parser, usage) {
    ArffParser parser("cases/case3.arff");
    ArffData* data = parser.parse();
    EXPECT_NE((ArffData*)NULL, data);
}

TEST(arff_parser, missing_usage) {
    ArffParser parser("cases/case4.arff");
    ArffData* data = parser.parse();
    EXPECT_NE((ArffData*)NULL, data);
}
