#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(FindMedianTest, example) {
  MedianFinder finder;

  EXPECT_EQ(0, finder.findMedian());

  finder.addNum(1);
  EXPECT_EQ(1, finder.findMedian());
  finder.addNum(1);
  EXPECT_EQ(1, finder.findMedian());
  finder.addNum(2);
  EXPECT_EQ(1, finder.findMedian());
  finder.addNum(2);
  EXPECT_EQ(1.5, finder.findMedian());
}

TEST(FindMedianTest, large) {
  MedianFinder finder;

  for (int i = 0; i < 10000; ++i) {
    finder.addNum(0);
  }
  EXPECT_EQ(0, finder.findMedian());
  for (int i = 0; i < 10000; ++i) {
    finder.addNum(1);
  }
  EXPECT_EQ(0.5, finder.findMedian());
  for (int i = 0; i < 10000; ++i) {
    finder.addNum(2);
  }
  EXPECT_EQ(1, finder.findMedian());
}

}
