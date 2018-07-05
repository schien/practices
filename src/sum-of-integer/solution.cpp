// https://leetcode.com/problems/sum-of-two-integers/

int useIteration(int a, int b) {
  int sum = a ^ b;
  int carry = (a & b) << 1;

  while (carry) {
    int tmp_sum = sum ^ carry;
    carry = (sum & carry) << 1;
    sum = tmp_sum;
  }
  return sum;
}

int useRecursion(int a, int b) {
  return (!b ? a : useRecursion(a^b, (a&b)<<1));
}

class Solution {
  public:
    int getSum(int a, int b) {
      return useIteration(a, b);
      //return useRecursion(a, b);
    }
};
