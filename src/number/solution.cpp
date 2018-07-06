// https://leetcode.com/problems/happy-number/
// https://leetcode.com/problems/add-digits/

#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) {
            return false;
        }

	auto digitsum = [](int n) {
	  int sum = 0;
	  while (n) {
	    int d = n%10;
	    n /= 10;
	    sum += d*d;
	  }
	  return sum;
	};

        unordered_set<int> visited;
        while (n != 1 && visited.insert(n).second) {
            n = digitsum(n);
        }
        return n == 1;
    }
    int addDigits(int num) {
      auto digitsum = [](int n) {
        int sum = 0;
        while(n) {
          sum += n%10;
          n /= 10;
        }
        return sum;
      };

      while(num >= 10) {
        num = digitsum(num);
      }
      return num;
    }
};
