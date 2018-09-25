// https://leetcode.com/problems/find-median-from-data-stream/

#include <queue>

using namespace std;

class MedianFinder {
  public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
      if (left.empty()) {
        left.push(num);
        return;
      }

      if (num < left.top()) {
        left.push(num);
      } else {
        right.push(num);
      }
      balance();
    }

    double findMedian() {
      if (left.empty()) { return 0; }

      if (left.size() == right.size()) {
        return (left.top() + right.top()) / 2.0;
      }
      return (left.size() > right.size()) ? left.top() : right.top();
    }
  private:
    void balance() {
      const int lsz = left.size();
      const int rsz = right.size();
      if (lsz - rsz > 1) {
        right.push(left.top());
        left.pop();
      } else if (lsz - rsz < -1) {
        left.push(right.top());
        right.pop();
      }
    }

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
