#include <gtest/gtest.h>
#include <arff_attr.h>



TEST(arff_attr, usage) {
    ArffAttr attr("abc", INTEGER);
    EXPECT_EQ("abc", attr.name());
    EXPECT_EQ(INTEGER, attr.type());
}
