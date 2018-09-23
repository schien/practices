#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(HeatersTest, empty) {
  Solution solution;
  vector<int> houses;
  vector<int> heaters;

  EXPECT_EQ(0, solution.findRadius(houses, heaters));

  houses.emplace_back(1);
  EXPECT_EQ(-1, solution.findRadius(houses, heaters));
}

TEST(HeatersTest, small) {
  Solution solution;
  vector<int> houses;
  vector<int> heaters;

  houses = {0};
  heaters = {1,3,5,7,9};
  for (int i = 0; i <= 10; ++i) {
    houses[0] = i;
    if (i&1) {
      EXPECT_EQ(0, solution.findRadius(houses, heaters));
    } else {
      EXPECT_EQ(1, solution.findRadius(houses, heaters));
    }
  }

  houses = {1,3,5,7,9};
  heaters = {0};
  for (int i = 0; i <= 10; ++i) {
    heaters[0] = i;
    EXPECT_EQ(max(abs(i-1), abs(i-9)), solution.findRadius(houses, heaters));
  }
}

TEST(HeatersTest, large) {
  Solution solution;
  vector<int> houses;
  vector<int> heaters;

  houses = {0};
  heaters.resize(25000);
  for (int i = 0; i < 25000; ++i) {
    heaters[i] = (2*i+1);
  }
  for (int i = 0; i <= 50000; ++i) {
    houses[0] = i;
    if (i&1) {
      EXPECT_EQ(0, solution.findRadius(houses, heaters));
    } else {
      EXPECT_EQ(1, solution.findRadius(houses, heaters));
    }
  }

  swap(houses, heaters);
  for (int i = 0; i <= 10; ++i) {
    heaters[0] = i;
    EXPECT_EQ(max(abs(i-1), abs(i-49999)), solution.findRadius(houses, heaters));
  }
}

}
