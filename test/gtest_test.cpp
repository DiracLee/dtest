#include "gtest/gtest.h"

TEST(GTEST, TEST_EXPECT_EQ) {
  EXPECT_EQ(5, 5);
}

TEST(GTEST, TEST_EXPECT_NE) {
  EXPECT_NE(5, 5);
}


int main()
{
  return RUN_ALL_TESTS();
}