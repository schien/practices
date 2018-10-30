#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

template<>
Employee next<Employee>() {
  int id = next<int>();
  int importance = next<int>();
  vector<int> subordinates = next_vector<int>();

  return {id, importance, subordinates};
}

int main() {
  vector<Employee> emp = next_vector<Employee>();

  vector<Employee*> input;
  for (int i = 0; i < emp.size(); ++i) {
    input.emplace_back(&emp[i]);
  }

  Solution solution;
  auto output = solution.getImportance(input, next<int>());
  std::cout << output << std::endl;

  return 0;
}
