#include "gtest/gtest.h"
#include <algorithm>

#include "solution.cpp"

namespace {

TEST(AssignCookieTest, example) {
  Solution solution;

  vector<int> g;
  vector<int> s;

  EXPECT_EQ(0, solution.findContentChildren(g,s));

  g = {1,2};
  s = {0};
  EXPECT_EQ(0, solution.findContentChildren(g,s));
  s = {0,0};
  EXPECT_EQ(0, solution.findContentChildren(g,s));
  s = {0,0,0};
  EXPECT_EQ(0, solution.findContentChildren(g,s));
  s = {1};
  EXPECT_EQ(1, solution.findContentChildren(g,s));
  s = {2};
  EXPECT_EQ(1, solution.findContentChildren(g,s));
  s = {0,1};
  EXPECT_EQ(1, solution.findContentChildren(g,s));
  s = {0,1,1};
  EXPECT_EQ(1, solution.findContentChildren(g,s));
  s = {0,2};
  EXPECT_EQ(1, solution.findContentChildren(g,s));
  s = {1,2};
  EXPECT_EQ(2, solution.findContentChildren(g,s));
  s = {0,1,2};
  EXPECT_EQ(2, solution.findContentChildren(g,s));

  vector<int> g1 = vector<int>(1000, 999);
  fill_n(g1.begin(), 1, 1);
  vector<int> g100 = vector<int>(1000, 999);
  fill_n(g100.begin(), 100, 1);
  vector<int> g1000 = vector<int>(1000, 1);

  vector<int> s0 = vector<int>(100);
  vector<int> s1 = vector<int>(100);
  fill_n(s1.begin(), 1, 1);
  vector<int> s10 = vector<int>(100);
  fill_n(s10.begin(), 10, 1);
  vector<int> s100 = vector<int>(100);
  fill_n(s100.begin(), 100, 1);
  vector<int> s500 = vector<int>(1000);
  fill_n(s500.begin(), 500, 1);
  vector<int> s1000 = vector<int>(1000);
  fill_n(s1000.begin(), 1000, 1);
  vector<int> s2000 = vector<int>(2000);
  fill_n(s2000.begin(), 2000, 1);
  for (int k = 0; k < 100; ++k) {
    random_shuffle(g1.begin(), g1.end());
    EXPECT_EQ(0, solution.findContentChildren(g1,s0));
    EXPECT_EQ(1, solution.findContentChildren(g1,s1));
    EXPECT_EQ(1, solution.findContentChildren(g1,s10));
    EXPECT_EQ(1, solution.findContentChildren(g1,s100));
    EXPECT_EQ(1, solution.findContentChildren(g1,s500));
    EXPECT_EQ(1, solution.findContentChildren(g1,s1000));
    EXPECT_EQ(1, solution.findContentChildren(g1,s2000));

    random_shuffle(g100.begin(), g100.end());
    EXPECT_EQ(0, solution.findContentChildren(g100,s0));
    EXPECT_EQ(1, solution.findContentChildren(g100,s1));
    EXPECT_EQ(10, solution.findContentChildren(g100,s10));
    EXPECT_EQ(100, solution.findContentChildren(g100,s100));
    EXPECT_EQ(100, solution.findContentChildren(g100,s500));
    EXPECT_EQ(100, solution.findContentChildren(g100,s1000));
    EXPECT_EQ(100, solution.findContentChildren(g100,s2000));


    random_shuffle(g1000.begin(), g1000.end());
    EXPECT_EQ(0, solution.findContentChildren(g1000,s0));
    EXPECT_EQ(1, solution.findContentChildren(g1000,s1));
    EXPECT_EQ(10, solution.findContentChildren(g1000,s10));
    EXPECT_EQ(100, solution.findContentChildren(g1000,s100));
    EXPECT_EQ(500, solution.findContentChildren(g1000,s500));
    EXPECT_EQ(1000, solution.findContentChildren(g1000,s1000));
    EXPECT_EQ(1000, solution.findContentChildren(g1000,s2000));


  }
}

}
