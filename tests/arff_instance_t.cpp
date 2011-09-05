#include <gtest/gtest.h>
#include <arff_instance.h>


TEST(arff_instance, usage) {
    ArffInstance inst;
    EXPECT_EQ(0, inst.size());
    inst.add(new ArffValue((int32)10));
    EXPECT_EQ(1, inst.size());
    inst.add(new ArffValue(1.1f));
    EXPECT_EQ(2, inst.size());
    inst.add(new ArffValue("string"));
    EXPECT_EQ(3, inst.size());
    EXPECT_TRUE(*inst.get(0) == (int32)10);
    EXPECT_TRUE(*inst.get(1) == 1.1f);
    EXPECT_TRUE(*inst.get(2) == "string");
}
