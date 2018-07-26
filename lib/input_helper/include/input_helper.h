#ifndef __INPUT_HELPER_H__
#define __INPUT_HELPER_H__

#include <string>
#include <iostream>
#include <vector>

template<typename T>
T next() {
  T val;
  std::cin >> val;
  return val;
}

template<typename T>
std::vector<T> next_vector() {
  int n = next<int>();
  std::vector<T> vec;
  vec.reserve(n);
  for (int i = 0; i < n; ++i) {
    vec.push_back(next<T>());
  }
  return vec;
}

#endif //__INPUT_HELPER_H__
