#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(GasStationTest, empty) {
  Solution solution;
  vector<int> gas;
  vector<int> cost;

  EXPECT_EQ(-1, solution.canCompleteCircuit(gas, cost));
}

TEST(GasStationTest, one) {
  Solution solution;
  vector<int> gas{1};
  vector<int> cost{1};

  EXPECT_EQ(0, solution.canCompleteCircuit(gas, cost));
  cost[0] = 2;
  EXPECT_EQ(-1, solution.canCompleteCircuit(gas, cost));
}

TEST(GasStationTest, small) {
  Solution solution;
  vector<int> gas(10, 1);
  vector<int> cost(10, 1);

  for (int i = 0; i < 10; ++i) {
    cost[i] = 2;
    EXPECT_EQ(-1, solution.canCompleteCircuit(gas, cost));

    for (int j = 0; j < 10; ++j) {
      gas[j] = 2;
      int expected = (i < j) ? ((i+1)%10) : 0;
      EXPECT_EQ(expected, solution.canCompleteCircuit(gas, cost));
      gas[j] = 1;
    }
    cost[i] = 1;
  }
}

TEST(GasStationTest, large) {
  Solution solution;
  vector<int> gas(100, 1);
  vector<int> cost(100, 1);

  for (int i = 0; i < 100; ++i) {
    cost[i] = 2;
    for (int j = i+1; j < 100; ++j) {
      cost[j] = 2;
      EXPECT_EQ(-1, solution.canCompleteCircuit(gas, cost));

      for (int k = 0; k < 100; ++k) {
        gas[k] = 3;
        int expected = 0;
        if (k > j) {
          expected = (j+1)%100;
        } else if (k > i) {
          expected = (i+1)%100;
        }
        EXPECT_EQ(expected, solution.canCompleteCircuit(gas, cost));
        gas[k] = 1;
      }

      cost[j] = 1;
    }

    cost[i] = 1;
  }

  for (int i = 0; i < 100; ++i) {
    cost[i] = 2;
    for (int j = i+1; j < 100; ++j) {
      cost[j] = 2;

      for (int k = 0; k < 100; ++k) {
        gas[k] = 2;
        for (int l = k+1; l < 100; ++l) {
          gas[l] = 2;

          int expected = 0;
          if (k > j) {
            expected = (j+1)%100;
          } else if (k > i) {
            expected = (i+1)%100;
          } else if (l > j) {
            expected = (j+1)%100;
          }

          EXPECT_EQ(expected, solution.canCompleteCircuit(gas, cost));

          gas[l] = 1;
        }
        gas[k] = 1;
      }

      cost[j] = 1;
    }

    cost[i] = 1;
  }
}

}
