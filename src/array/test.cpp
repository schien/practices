#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(ArrayUniqueIntersectTest, empty) {
  Solution solution;
  vector<int> empty;
  vector<int> ones(1000000, 1);

  EXPECT_EQ(vector<int>{}, solution.intersection(empty, empty));
  EXPECT_EQ(vector<int>{}, solution.intersection(ones, empty));
  EXPECT_EQ(vector<int>{}, solution.intersection(empty, ones));
}

TEST(ArrayUniqueIntersectTest, same) {
  Solution solution;
  vector<int> ones(1000000, 1);

  EXPECT_EQ(vector<int>{1}, solution.intersection(ones, ones));
}

TEST(ArrayUniqueIntersectTest, no_intersection) {
  Solution solution;

  vector<int> ones(1000000, 1);
  vector<int> zeros(1000000, 0);

  EXPECT_EQ(vector<int>{}, solution.intersection(ones, zeros));
}

TEST(ArrayUniqueIntersectTest, subset) {
  Solution solution;

  vector<int> all;
  vector<int> odds;

  all.reserve(1000000);
  odds.reserve(1000000);
  for (int i = 0; i < 1000000; ++i) {
    all.push_back(i);
    if (i&1) {
      odds.push_back(i);
    }
  }

  EXPECT_EQ(odds, solution.intersection(all, odds));
}

TEST(ArrayMultiIntersectTest, empty) {
  Solution solution;
  vector<int> empty;
  vector<int> ones(1000000, 1);

  EXPECT_EQ(vector<int>{}, solution.intersect(empty, empty));
  EXPECT_EQ(vector<int>{}, solution.intersect(ones, empty));
  EXPECT_EQ(vector<int>{}, solution.intersect(empty, ones));
}

TEST(ArrayMultiIntersectTest, same) {
  Solution solution;
  vector<int> ones(1000000, 1);

  EXPECT_EQ(ones, solution.intersect(ones, ones));
}

TEST(ArrayMultiIntersectTest, no_intersection) {
  Solution solution;

  vector<int> ones(1000000, 1);
  vector<int> zeros(1000000, 0);

  EXPECT_EQ(vector<int>{}, solution.intersect(ones, zeros));
}

TEST(ArrayMultiIntersectTest, subset) {
  Solution solution;

  vector<int> all;
  vector<int> double_all;

  all.reserve(1000000);
  double_all.reserve(1000000*2);
  for (int i = 0; i < 1000000; ++i) {
    all.push_back(i);
    double_all.push_back(i);
    double_all.push_back(i);
  }


  EXPECT_EQ(all, solution.intersection(all, double_all));
  EXPECT_EQ(all, solution.intersection(double_all, all));
}

}
