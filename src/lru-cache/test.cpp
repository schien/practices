#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(LruCacheTest, empty) {
  LRUCache cache(0);
  EXPECT_EQ(-1, cache.get(0));
  cache.put(0, 0);
  EXPECT_EQ(-1, cache.get(0));
}

TEST(LruCacheTest, one) {
  LRUCache cache(1);
  EXPECT_EQ(-1, cache.get(0));

  cache.put(0, 0);
  EXPECT_EQ(0, cache.get(0));

  cache.put(0, 1);
  EXPECT_EQ(1, cache.get(0));

  cache.put(1, 1);
  EXPECT_EQ(1, cache.get(1));
  EXPECT_EQ(-1, cache.get(0));
}

TEST(LruCacheTest, small) {
  LRUCache cache(100);

  for (int i = 0; i < 100; ++i) {
    cache.put(i, i);
    EXPECT_EQ(i, cache.get(i));
  }

  for (int i = 0; i < 100; ++i) {
    cache.put(i, i<<1);
    EXPECT_EQ(i<<1, cache.get(i));
  }

  for (int i = 99; i >= 0; --i) {
    EXPECT_EQ(i<<1, cache.get(i));
  }

  cache.put(100, 100);
  EXPECT_EQ(100, cache.get(100));
  for (int i = 0; i < 100; ++i) {
    if (i < 99) {
      EXPECT_EQ(i<<1, cache.get(i));
    } else {
      EXPECT_EQ(-1, cache.get(i));
    }
  }
}

TEST(LruCacheTest, large) {
  LRUCache cache(100000);

  for (int i = 0; i < 100000; ++i) {
    cache.put(i, i);
    EXPECT_EQ(i, cache.get(i));
  }

  for (int i = 0; i < 100000; ++i) {
    cache.put(i, i<<1);
    EXPECT_EQ(i<<1, cache.get(i));
  }

  for (int i = 99999; i >= 0; --i) {
    EXPECT_EQ(i<<1, cache.get(i));
  }

  for (int i = 0; i < 10000; ++i) {
    cache.put(100000+i, 100000+i);
    EXPECT_EQ(100000+i, cache.get(100000+i));
  }

  for (int i = 0; i < 100000; ++i) {
    if (i < 90000) {
      EXPECT_EQ(i<<1, cache.get(i));
    } else {
      EXPECT_EQ(-1, cache.get(i));
    }
  }
}

}
