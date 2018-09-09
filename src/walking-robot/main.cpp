#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

std::vector<int> read_commands() {
  int n = next<int>();
  std::vector<int> commands(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> commands[i];
  }
  return commands;
}

std::vector<std::vector<int>> read_obstacles() {
  int n = next<int>();
  std::vector<std::vector<int>> obs(n, vector<int>(2));
  for (int i = 0; i < n; ++i) {
    std::cin >> obs[i][0] >> obs[i][1];
  }
  return obs;
}

int main() {
  std::vector<int> commands = read_commands();
  std::vector<std::vector<int>> obstacles = read_obstacles();

  Solution solution;
  auto output = solution.robotSim(commands, obstacles);

  std::cout << output << std::endl;
  return 0;
}
