#include "gtest/gtest.h"
#include <cstdint>

#include "solution.cpp"

namespace {

TEST(RelationalOperatorTest, example) {
  Solution solution;

  const char eq = '=', lt = '<', gt = '>';

  EXPECT_EQ(eq, solution.relation(1, 1));
  EXPECT_EQ(eq, solution.relation(0, 0));
  EXPECT_EQ(eq, solution.relation(-1, -1));
  EXPECT_EQ(eq, solution.relation(INT_MAX, INT_MAX));
  EXPECT_EQ(eq, solution.relation(INT_MIN, INT_MIN));

  EXPECT_EQ(lt, solution.relation(0, 1));
  EXPECT_EQ(lt, solution.relation(-1, 0));
  EXPECT_EQ(lt, solution.relation(-2, -1));
  EXPECT_EQ(lt, solution.relation(INT_MIN, INT_MAX));

  EXPECT_EQ(gt, solution.relation(1, 0));
  EXPECT_EQ(gt, solution.relation(0, -1));
  EXPECT_EQ(gt, solution.relation(-1, -2));
  EXPECT_EQ(gt, solution.relation(INT_MAX, INT_MIN));
}

}
