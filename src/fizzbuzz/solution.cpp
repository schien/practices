// https://leetcode.com/problems/fizz-buzz/

#include <vector>
#include <string>
#include <sstream>

using namespace std;

static string fizz_str{"Fizz"};
static string buzz_str{"Buzz"};
static string fizzbuzz_str{"FizzBuzz"};

uint32_t next_divisible(const uint32_t n, const uint32_t divisor) {
  uint32_t distant = divisor - (n%divisor);
  if (distant == divisor) {
    distant = 0;
  }
  return n + distant;
}

void no_modulo(const uint32_t begin, const uint32_t end, vector<string>& result) {
  uint32_t next_fizz = next_divisible(begin, 3);
  uint32_t next_buzz = next_divisible(begin, 5);

  stringstream buf;
  for (uint32_t i = begin; i <= end; ++i) {
    bool is_fizz_or_buzz = false;
    if (i == next_fizz) {
      next_fizz += 3;
      buf << fizz_str;
      is_fizz_or_buzz = true;
    }

    if (i == next_buzz) {
      next_buzz += 5;
      buf << buzz_str;
      is_fizz_or_buzz = true;
    }

    if (!is_fizz_or_buzz) {
      buf << i;
    }

    result.push_back(buf.str());
    buf.str("");
    buf.clear();
  }
}

void append(const uint32_t begin, const uint32_t end, vector<string>& result) {
  stringstream buf;
  for (uint32_t i = begin; i <= end; ++i) {
    const bool fizz = (i%3==0);
    const bool buzz = (i%5==0);
    if (fizz) {
      buf << fizz_str;
    }
    if (buzz) {
      buf << buzz_str;
    }
    if (!(fizz || buzz)) {
      buf << i;
    }
    result.push_back(buf.str());
    buf.str("");
    buf.clear();
  }
}

void store_common_result(const uint32_t begin, const uint32_t end, vector<string>& result) {
  for (uint32_t i = begin; i <= end; ++i) {
    const bool fizz = (i%3==0);
    const bool buzz = (i%5==0);
    if (fizz && buzz) {
      result.push_back(fizzbuzz_str);
    } else if (fizz) {
      result.push_back(fizz_str);
    } else if (buzz) {
      result.push_back(buzz_str);
    } else {
      result.push_back(to_string(i));
    }
  }
}

void naive(const uint32_t begin, const uint32_t end, vector<string>& result) {
  for (uint32_t i = begin; i <= end; ++i) {
    if (i % 3 == 0 && i % 5 == 0) {
      result.push_back(fizzbuzz_str);
    } else if (i % 3 == 0) {
      result.push_back(fizz_str);
    } else if (i % 5 == 0) {
      result.push_back(buzz_str);
    } else {
      result.push_back(to_string(i));
    }
  }
}

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> result;
    result.reserve(n);
    //naive(1, n, result);
    //store_common_result(1, n, result);
    //append(1, n, result);
    no_modulo(1, n, result);
    return result;
  }
};
