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

template<>
std::vector<int> next<std::vector<int>>();

template<>
std::vector<std::string> next<std::vector<std::string>>();

#endif //__INPUT_HELPER_H__
