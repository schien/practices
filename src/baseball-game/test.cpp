#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(BaseballGameTest, example) {
  Solution solution;

  vector<string> ops;
  EXPECT_EQ(0, solution.calPoints(ops));

  ops = {"1","2","3","4","5"};
  EXPECT_EQ(1+2+3+4+5, solution.calPoints(ops));
  ops = {"1","-2"};
  EXPECT_EQ(1-2, solution.calPoints(ops));

  ops = {"1", "C"};
  EXPECT_EQ(0, solution.calPoints(ops));
  ops = {"1", "D"};
  EXPECT_EQ(1+(1*2), solution.calPoints(ops));
  ops = {"1", "2", "+"};
  EXPECT_EQ(1+2+(1+2), solution.calPoints(ops));

  ops = {"1", "2", "C", "D"};
  EXPECT_EQ(1+(1*2), solution.calPoints(ops));
  ops = {"1", "D", "C"};
  EXPECT_EQ(1, solution.calPoints(ops));
  ops = {"1", "2", "3", "C", "+"};
  EXPECT_EQ(1+2+(1+2), solution.calPoints(ops));
  ops = {"1", "2", "+", "C"};
  EXPECT_EQ(1+2, solution.calPoints(ops));
  ops = {"1", "D", "+"};
  EXPECT_EQ(1+(1*2)+(1+1*2), solution.calPoints(ops));
  ops = {"1", "2", "+", "D"};
  EXPECT_EQ(1+2+(1+2)+((1+2)*2), solution.calPoints(ops));

  ops = {"5","2","C","D","+"};
  EXPECT_EQ(30, solution.calPoints(ops));

  ops = {"5","-2","4","C","D","9","+","+"};
  EXPECT_EQ(27, solution.calPoints(ops));
}

}
