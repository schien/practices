// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2113

class Solution {
public:
  char relation(int a, int b) {
    return (a==b?'=':a>b?'>':'<');
  }
};
