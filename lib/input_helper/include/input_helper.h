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

std::vector<int> next();

#endif //__INPUT_HELPER_H__
