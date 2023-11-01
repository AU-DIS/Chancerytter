#include "gtest/gtest.h"
#include "generaltests.h"
#include "experiment_test/experiment_test.cpp"

TEST(TestOfTest, AssertTrue)
{
    ASSERT_TRUE(true);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}