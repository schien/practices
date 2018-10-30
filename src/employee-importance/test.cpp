#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(EmployeeImportanceTest, example) {
  Solution solution;

  vector<Employee> employees{
    {1, 5, {2,3}},
    {2, 3, {}},
    {3, 3, {}},
  };

  vector<Employee*> input;
  for (int i = 0; i < employees.size(); ++i) {
    input.emplace_back(&employees[i]);
  }

  EXPECT_EQ(5+3+3, solution.getImportance(input, 1));
  EXPECT_EQ(3, solution.getImportance(input, 2));
  EXPECT_EQ(3, solution.getImportance(input, 3));
  EXPECT_EQ(0, solution.getImportance(input, 4));
}

}
