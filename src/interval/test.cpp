#include "gtest/gtest.h"

#include "solution.cpp"

bool operator==(const Interval& lhs, const Interval& rhs) {
  return lhs.start == rhs.start && lhs.end == rhs.end;
}

namespace {

TEST(MergeTest, empty) {
  Solution solution;

  vector<Interval> input;
  EXPECT_EQ(vector<Interval>{}, solution.merge(input));
}

TEST(MergeTest, small) {
  Solution solution;

  vector<Interval> input{{1,3}, {5,7}};
  EXPECT_EQ((vector<Interval>{{1,3},{5,7}}), solution.merge(input));

  input = {{1,5},{5,7}};
  EXPECT_EQ((vector<Interval>{{1,7}}), solution.merge(input));
  input = {{1,6},{5,7}};
  EXPECT_EQ((vector<Interval>{{1,7}}), solution.merge(input));
  input = {{1,7},{5,7}};
  EXPECT_EQ((vector<Interval>{{1,7}}), solution.merge(input));
  input = {{1,8},{5,7}};
  EXPECT_EQ((vector<Interval>{{1,8}}), solution.merge(input));

  input = {{1,3},{0,7}};
  EXPECT_EQ((vector<Interval>{{0,7}}), solution.merge(input));
  input = {{1,3},{1,7}};
  EXPECT_EQ((vector<Interval>{{1,7}}), solution.merge(input));
  input = {{1,3},{2,7}};
  EXPECT_EQ((vector<Interval>{{1,7}}), solution.merge(input));
  input = {{1,3},{3,7}};
  EXPECT_EQ((vector<Interval>{{1,7}}), solution.merge(input));

  input = {{1,1}, {2,2}, {3,3}};
  EXPECT_EQ((vector<Interval>{{1,1},{2,2},{3,3}}), solution.merge(input));

  input = {{1,2},{2,2},{3,3}};
  EXPECT_EQ((vector<Interval>{{1,2},{3,3}}), solution.merge(input));

  input = {{1,3},{2,2},{3,3}};
  EXPECT_EQ((vector<Interval>{{1,3}}), solution.merge(input));

  input = {{1,1},{1,2},{3,3}};
  EXPECT_EQ((vector<Interval>{{1,2},{3,3}}), solution.merge(input));

  input = {{1,1},{2,3},{3,3}};
  EXPECT_EQ((vector<Interval>{{1,1},{2,3}}), solution.merge(input));

  input = {{1,1},{1,3},{3,3}};
  EXPECT_EQ((vector<Interval>{{1,3}}), solution.merge(input));

  input = {{1,1},{2,2},{1,3}};
  EXPECT_EQ((vector<Interval>{{1,3}}), solution.merge(input));

  input = {{1,1},{2,2},{2,3}};
  EXPECT_EQ((vector<Interval>{{1,1},{2,3}}), solution.merge(input));
}

TEST(MergeTest, large) {
  Solution solution;

  vector<Interval> input;
  for (int i = 0; i < 100000; ++i) {
    input.emplace_back(i, i);
  }
  EXPECT_EQ(input, solution.merge(input));

  for (int i = 0; i < 100000; ++i) {
    ++input[i].end;
  }
  EXPECT_EQ((vector<Interval>{{0,100000}}), solution.merge(input));
}

}
