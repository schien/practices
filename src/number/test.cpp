#include "gtest/gtest.h"
#include <numeric>
#include <unordered_map>
#include <unordered_set>

#include "solution.cpp"

namespace {

TEST(HappyNumberTest, zero) {
  Solution solution;
  EXPECT_FALSE(solution.isHappy(0));
}

TEST(HappyNumberTest, one) {
  Solution solution;
  EXPECT_TRUE(solution.isHappy(1));
}

TEST(HappyNumberTest, two) {
  Solution solution;
  EXPECT_FALSE(solution.isHappy(2));
}

TEST(HappyNumberTest, negative) {
  Solution solution;
  EXPECT_FALSE(solution.isHappy(-1));
}

TEST(AddDigitsTest, num_lt_10) {
  Solution solution;
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(i, solution.addDigits(i));
  }
}

TEST(AddDigitsTest, 1m) {
  Solution solution;
  EXPECT_EQ(1, solution.addDigits(1000000));
}

TEST(UglyNumberTest, zero) {
  Solution solution;
  EXPECT_FALSE(solution.isUgly(0));
}

TEST(UglyNumberTest, one) {
  Solution solution;
  EXPECT_TRUE(solution.isUgly(1));
}

TEST(UglyNumberTest, ugly_lt_10) {
  Solution solution;
  for (auto n : vector<int>{2, 3, 4, 5, 6, 8, 9}) {
    EXPECT_TRUE(solution.isUgly(n));
  }
}

TEST(UglyNumberTest, seven) {
  Solution solution;
  EXPECT_FALSE(solution.isUgly(7));
}

TEST(UglyNumberTest, negative) {
  Solution solution;
  EXPECT_FALSE(solution.isUgly(-1));
}

TEST(NumOfSquaresTest, square) {
  Solution solution;

  for (int i = 1; i < 1000; ++i) {
    EXPECT_EQ(1, solution.numSquares(i*i));
    EXPECT_EQ(2, solution.numSquares((i*i) << 1));
  }
}

TEST(NumOfSquaresTest, bound) {
  Solution solution;

  for (int i = 1; i < 100000; ++i) {
    EXPECT_GE(4, solution.numSquares(i));
  }
}

TEST(HammingDistanceTest, example) {
  Solution solution;

  for (int i = 0; i < 32; ++i) {
    EXPECT_EQ(1, solution.hammingDistance(0, 1 << i));
  }

  for (int i = 0; i < 32; ++i) {
    EXPECT_EQ(0, solution.hammingDistance(1 << i, 1 << i));
  }
}

TEST(PerfectSquareTest, small) {
  Solution solution;

  int r = 0;
  int next_perfect_square = 0;

  for (int i = 0; i < 10000; ++i) {
    if (i == next_perfect_square) {
      EXPECT_TRUE(solution.isPerfectSquare(i));
      ++r;
      next_perfect_square = r*r;
    } else {
      EXPECT_FALSE(solution.isPerfectSquare(i));
    }
  }
}

TEST(SquareSumTest, boundary_condition) {
  Solution solution;

  EXPECT_TRUE(solution.judgeSquareSum(0));
  EXPECT_FALSE(solution.judgeSquareSum(-1));
}

TEST(SquareSumTest, small) {
  Solution solution;

  unordered_set<int> table;
  for (int i = 10; i >= 0; --i) {
    for (int j = i; j >= 0; --j) {
      table.insert(i*i+j*j);
    }
  }

  for (int i = 0; i <= 100; ++i) {
    if (table.find(i) != table.end()) {
      EXPECT_TRUE(solution.judgeSquareSum(i));
    } else {
      EXPECT_FALSE(solution.judgeSquareSum(i));
    }
  }
}

TEST(PerfectNumberTest, boundary_condition) {
  Solution solution;

  EXPECT_FALSE(solution.checkPerfectNumber(-1));
  EXPECT_FALSE(solution.checkPerfectNumber(0));
  EXPECT_FALSE(solution.checkPerfectNumber(1));
}

static vector<int> get_all_divisors(const int num) {
  if (num <= 1) {
    return {};
  }
  vector<int> divisors{1};
  int bound = static_cast<int>(sqrt(num));
  for (int i = 2; i <= bound; ++i) {
    if (num%i == 0) {
      divisors.emplace_back(i);
      if (num/i != i) {
        divisors.emplace_back(num/i);
      }
    }
  }
  return divisors;
}

TEST(PerfectNumberTest, small) {
  Solution solution;

  for (int i = 2; i < 10000; ++i) {
    auto divisors = get_all_divisors(i);
    int sum = accumulate(divisors.begin(), divisors.end(), 0);
    EXPECT_EQ(sum == i, solution.checkPerfectNumber(i));
  }
}

TEST(PerfectNumberTest, large) {
  Solution solution;

  for (int i = 99900000; i < 100000000; ++i) {
    auto divisors = get_all_divisors(i);
    int sum = accumulate(divisors.begin(), divisors.end(), 0);
    EXPECT_EQ(sum == i, solution.checkPerfectNumber(i));
  }
}

TEST(ColumnTitleTest, example) {
  Solution solution;

  for (int i = 0; i < 26; ++i) {
    const char c = 'A' + i;
    EXPECT_EQ((string{c}), solution.convertToTitle(i+1));
  }

  EXPECT_EQ("", solution.convertToTitle(0));
  EXPECT_EQ("", solution.convertToTitle(-1));
  EXPECT_EQ("AB", solution.convertToTitle(28));
  EXPECT_EQ("ZY", solution.convertToTitle(701));
}

TEST(ComplementTest, example) {
  Solution solution;

  vector<pair<int,int>> tests {
    {1,0},
      {2,1},
      {3,0},
      {4,3},
      {5,2},
      {6,1},
      {7,0},
      {8,7},
      {9,6},
      {10,5},
      {11,4},
      {12,3},
      {13,2},
      {14,1},
      {15,0},
      {INT_MAX,0},
  };

  for (auto& p : tests) {
    EXPECT_EQ(p.second, solution.findComplement(p.first));
  }
}

TEST(BinaryGapTest, example) {
  Solution solution;

  EXPECT_EQ(0, solution.binaryGap(-1));
  EXPECT_EQ(0, solution.binaryGap(0));

  for (int i = 1; i > 0; i <<= 1) {
    EXPECT_EQ(0, solution.binaryGap(i));
  }

  for (int i = 0; i < 31; ++i) {
    EXPECT_EQ(i, solution.binaryGap((1<<i) | 0x1 ));
  }


  EXPECT_EQ(7, solution.binaryGap(1 | 1<<1 | 1<<3 | 1<<6 | 1<<10 | 1<<15 | 1<<21 | 1<<28));
  EXPECT_EQ(7, solution.binaryGap(1 | 1<<7 | 1<<13 | 1<<18 | 1<<22 | 1<<25 | 1<<27 | 1<<28));
}

TEST(ReachNumberTest, example) {
  Solution solution;

  for (int i = 0, input = 0; i < 10000; input += ++i ) {
    EXPECT_EQ(i, solution.reachNumber(input));
    EXPECT_EQ(i, solution.reachNumber(-input));
  }

  unordered_map<int,int> tests;
  unordered_set<int> q{0};
  for (int i = 0; i < 100; ++i) {
    unordered_set<int> next;
    for (auto n : q) {
      if (next.find(n+i) == next.end()) {
        next.insert(n+i);
        auto it = tests.find(n+i);
        if (it == tests.end()) {
          tests[n+i] = i;
        }
      }
      if (next.find(n-i) == next.end()) {
        next.insert(n-i);
        auto it = tests.find(n-i);
        if (it == tests.end()) {
          tests[n-i] = i;
        }
      }
    }
    q.swap(next);
  }

  for (auto& test : tests) {
    EXPECT_EQ(test.second, solution.reachNumber(test.first));
  }
}

TEST(AlternatingBitsTest, example) {
  Solution solution;

  unordered_set<int> alts {
    0,
    0x1, 0x5, 0x15, 0x55, 0x155, 0x555, 0x1555, 0x5555,
    0x15555, 0x55555, 0x155555, 0x555555, 0x1555555, 0x5555555, 0x15555555, 0x55555555,
    0x2, 0xA, 0x2A, 0xAA, 0x2AA, 0xAAA, 0x2AAA, 0xAAAA,
    0x2AAAA, 0xAAAAA, 0x2AAAAA, 0xAAAAAA, 0x2AAAAAA, 0xAAAAAAA, 0x2AAAAAAA, static_cast<int>(0xAAAAAAAA),
  };


  for (auto n : alts) {
    EXPECT_TRUE(solution.hasAlternatingBits(n));
  }

  for (int i = 0; i < 1000000; ++i) {
    if (alts.find(i) == alts.end()) {
      EXPECT_FALSE(solution.hasAlternatingBits(i));
    }
    if (alts.find(-i) == alts.end()) {
      EXPECT_FALSE(solution.hasAlternatingBits(-i));
    }
  }
}

}
