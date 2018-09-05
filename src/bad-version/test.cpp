#include "gtest/gtest.h"

#include "solution.cpp"

static int bad_version = 0;

bool isBadVersion(int version) {
  return version >= bad_version;
}

namespace {

TEST(BadVersionTest, boundary_condition) {
  Solution solution;

  EXPECT_EQ(-1, solution.firstBadVersion(0));
  EXPECT_EQ(-1, solution.firstBadVersion(-1));

  bad_version = 1;
  EXPECT_EQ(1, solution.firstBadVersion(1));

  bad_version = INT_MAX;
  EXPECT_EQ(INT_MAX, solution.firstBadVersion(INT_MAX));
}

TEST(BadVersionTest, small) {
  Solution solution;

  for (int i = 1; i <= 100; ++i) {
    bad_version = i;
    EXPECT_EQ(bad_version, solution.firstBadVersion(100));
  }
}

TEST(BadVersionTest, large) {
  Solution solution;

  for (int i = 0; i < 31; ++i) {
    bad_version = 1 << i;
    EXPECT_EQ(bad_version, solution.firstBadVersion(INT_MAX));
  }

  bad_version = INT_MAX - 1;
  EXPECT_EQ(bad_version, solution.firstBadVersion(INT_MAX));
}

}
