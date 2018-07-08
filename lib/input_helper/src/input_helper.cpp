#include "input_helper.h"

std::vector<int> next() {
  int n = next<int>();
  std::vector<int> vec;
  vec.reserve(n);
  for (int i = 0; i < n; ++i) {
    vec.push_back(next<int>());
  }
  return vec;
}
