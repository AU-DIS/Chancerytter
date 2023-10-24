#include "gtest/gtest.h"
#include "generaltests.h"



TEST(TestOfTest, AssertTrue) {
    ASSERT_TRUE(true);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}