#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

using namespace std;

int main() {
  vector<int> nums = next_vector<int>();

  Solution solution;
  auto output = solution.isJolly(nums);
  cout << (output?"Jolly":"Not jolly") << '\n';

  return 0;
}
