#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "usage: interval m n s_1 e_1 ... s_n e_n\n"
            << std::flush;
}

vector<Interval> read_intervals() {
  int n = next<int>();
  vector<Interval> result;
  for (int i = 0; i < n; ++i) {
    result.emplace_back(next<int>(), next<int>());
  }
  return result;
}

void output_intervals(vector<Interval>& intervals) {
  for (auto& interval : intervals) {
    std::cout << '[' << interval.start << ',' << interval.end << ']' << ' ';
  }
  std::cout << std::endl;
}
void runMerge() {
  vector<Interval> intervals = read_intervals();

  Solution solution;
  auto output = solution.merge(intervals);
  output_intervals(output);
}

int main() {
  char op;
  std::cin >> op;

  switch (op) {
    case 'm':
      runMerge();
      break;
    default:
      usage();
      break;
  }
  return 0;
}
