// https://leetcode.com/problems/power-of-three/

#include <cmath>
#include <limits>
#include <stdlib.h>
#include <iostream>

using namespace std;

static int x=[](){ std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

bool useIntegerLimit(int n) {
  static const int max_pow_of_3 =
    pow(3, static_cast<int>(floor(log(std::numeric_limits<int>::max())/log(3))));
  return n > 0 && max_pow_of_3 % n == 0;
}

bool naive(int n) {
  while (n > 1) {
    div_t result = div(n, 3);
    if (result.rem) {
      return false;
    }
    n = result.quot;
  }

  return n == 1;
}

class Solution {
public:
  bool isPowerOfThree(int n) {
    //return naive(n);
    return useIntegerLimit(n);
  }
};
