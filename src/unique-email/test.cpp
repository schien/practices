#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(UniqueEmailTest, example) {
  Solution solution;

  vector<string> nameA {
    "AAA",
    ".AAA",
    "A.AA",
    "AA.A",
    "AAA.",
    ".A.AA",
    ".AA.A",
    ".AAA.",
    "A.A.A",
    "A.AA.",
    "AA.A.",
    ".A.A.A",
    ".A.AA.",
    ".AA.A.",
    "A.A.A.",
    ".A.A.A.",
    ".A.A.A.+",
    ".A.A.A.+X",
    ".A.A.A.+Y",
    ".A.A.A.+.",
    ".A.A.A.++",
  };

  vector<string> input;
  for (auto& s : nameA) {
    input.push_back(s + "@example.com");
    input.push_back(s + "@example.net");
  }

  EXPECT_EQ(2, solution.numUniqueEmails(input));

  input.push_back("BBB@example.com");
  EXPECT_EQ(3, solution.numUniqueEmails(input));
}

}
