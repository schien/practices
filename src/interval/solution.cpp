// https://leetcode.com/problems/merge-intervals/
/**
 * Definition for an interval.
 */
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
  public:
    vector<Interval> merge(vector<Interval>& intervals) {
      if (intervals.empty()) { return {}; }

      sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
          return lhs.start < rhs.start;
      });

      vector<Interval> result;
      int start = intervals[0].start;
      int end = intervals[0].end;
      const int sz = intervals.size();
      for (int i = 1; i < sz; ++i) {
        auto& interval = intervals[i];
        if (interval.start > end) {
          result.emplace_back(start, end);
          start = interval.start;
          end = interval.end;
        } else {
          end = max(end, interval.end);
        }
      }
      result.emplace_back(start, end);
      return result;
    }
};
