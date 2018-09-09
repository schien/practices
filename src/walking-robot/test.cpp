#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(WalkingRobotTest, no_obstacle) {
  Solution solution;
  vector<int> cmds;
  vector<vector<int>> obstacles;

  EXPECT_EQ(0, solution.robotSim(cmds, obstacles));

  cmds.emplace_back(0);
  for (int i = 1; i <= 9; ++i) {
    cmds.back() = i;
    EXPECT_EQ(i*i, solution.robotSim(cmds, obstacles));
  }

  cmds.emplace_back(-1);
  cmds.emplace_back(0);
  for (int i = 1; i <= 9; ++i) {
    cmds.back() = i;
    EXPECT_EQ(i*i+81, solution.robotSim(cmds, obstacles));
  }

  cmds.emplace_back(-1);
  cmds.emplace_back(0);
  for (int i = 1; i <= 9; ++i) {
    cmds.back() = i;
    EXPECT_EQ(81*2, solution.robotSim(cmds, obstacles));
  }

  cmds.emplace_back(-1);
  cmds.emplace_back(0);
  for (int i = 1; i <= 9; ++i) {
    cmds.back() = i;
    EXPECT_EQ(81*2, solution.robotSim(cmds, obstacles));
  }

  cmds.emplace_back(0);
  for (int i = 1; i <= 9; ++i) {
    cmds.back() = i;
    EXPECT_EQ(81*2, solution.robotSim(cmds, obstacles));
  }

  cmds.emplace_back(-2);
  cmds.emplace_back(0);
  for (int i = 1; i <= 9; ++i) {
    cmds.back() = i;
    EXPECT_EQ(81*2, solution.robotSim(cmds, obstacles));
  }

  cmds.emplace_back(1);
  EXPECT_EQ(81+100, solution.robotSim(cmds, obstacles));

  cmds.emplace_back(-2);
  cmds.emplace_back(0);
  for (int i = 1; i <= 9; ++i) {
    cmds.back() = i;
    EXPECT_EQ(81+100, solution.robotSim(cmds, obstacles));
  }

  cmds.emplace_back(-2);
  cmds.emplace_back(1);
  EXPECT_EQ(81+100, solution.robotSim(cmds, obstacles));

  cmds.emplace_back(0);
  for (int i = 1; i <= 9; ++i) {
    cmds.back() = i;
    EXPECT_EQ(81+100, solution.robotSim(cmds, obstacles));
  }
}

TEST(WalkingRobotTest, obstacles) {
  Solution solution;
  vector<int> cmds{3};
  vector<vector<int>> obstacles{{0,3}};
  EXPECT_EQ(4, solution.robotSim(cmds, obstacles));

  cmds = {-1, 3};
  obstacles = {{3, 0}};
  EXPECT_EQ(4, solution.robotSim(cmds, obstacles));

  cmds = {-2, 3};
  obstacles = {{-3, 0}};
  EXPECT_EQ(4, solution.robotSim(cmds, obstacles));

  cmds = {-1, -1, 3};
  obstacles = {{0, -3}};
  EXPECT_EQ(4, solution.robotSim(cmds, obstacles));
}

}
