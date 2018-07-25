#include "gtest/gtest.h"
#include <unordered_map>

#include "solution.cpp"

namespace {

TEST(RandomSetTest, insert_remove) {
  RandomizedSet rset;

  for (int i = 0; i < 1000; ++i) {
    EXPECT_TRUE(rset.insert(i));
  }

  for (int i = 0; i < 1000; ++i) {
    EXPECT_FALSE(rset.insert(i));
  }

  for (int i = 0; i < 1000; ++i) {
    EXPECT_TRUE(rset.remove(i));
  }

  for (int i = 0; i < 1000; ++i) {
    EXPECT_FALSE(rset.remove(i));
  }
}

TEST(RandomSetTest, getRandom) {
  RandomizedSet rset;

  for (int i = 0; i < 1000; ++i) {
    EXPECT_TRUE(rset.insert(i));
  }

  unordered_map<int, int> count;
  for (int i = 0; i < 1000000; ++i) {
    auto rnd = rset.getRandom();
    EXPECT_GE(rnd, 0);
    EXPECT_LT(rnd, 1000);
    ++count[rnd];
  }

  for (int i = 0; i < 1000; ++i) {
    EXPECT_GT(count[i], 0);
  }
}

}
