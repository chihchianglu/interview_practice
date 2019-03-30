//
// Created by Lu, Chih-chiang on 2019-01-31.
//

/**
 * Non-overlapping Intervals
 *
 * Given a collection of intervals, find the minimum number of intervals you need to remove to make
 * the rest of the intervals non-overlapping.
 *
 * Actually this problem is the same as "Given a collection of intervals, find the maximum number of
 * intervals that are non-overlapping." see:
 * https://en.wikipedia.org/wiki/Interval_scheduling#Interval_Scheduling_Maximization
 *
 * Note:
 * You may assume the interval's end point is always bigger than its start point.
 * Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
 * Example 1:
 * Input: [ [1,2], [2,3], [3,4], [1,3] ]
 *
 * Output: 1
 *
 * Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
 *
 * Example 2:
 *
 * Input: [ [1,2], [1,2], [1,2] ]
 * Output: 2
 *
 * Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
 *
 * Example 3:
 *
 * Input: [ [1,2], [2,3] ]
 * Output: 0
 *
 * Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 */

#include <vector>
#include <stdexcept>

// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
 public:
  static int eraseOverlapIntervals(std::vector<Interval> &intervals) {
    int res = 0;
    std::sort(intervals.begin(),
              intervals.end(),
              [](const Interval &a, const Interval &b) { return a.start < b.start; });
    auto cur = intervals.begin();
    for (auto itr = intervals.begin() + 1; cur != intervals.end() && itr != intervals.end(); ++itr) {
      // overlap
      if (cur->end > itr->start) {
        ++res;
        if (cur->end > itr->end) { // remove the wider interval
          cur = itr;
        }
      } else {
        cur = itr;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<Interval> interval1 = {Interval(1, 2), Interval(2, 3), Interval(3, 4), Interval(1, 3)};
  std::vector<Interval> interval2 = {Interval(1, 2), Interval(1, 2), Interval(1, 2)};
  std::vector<Interval> interval3 = {Interval(1, 2), Interval(2, 3)};
  if (Solution::eraseOverlapIntervals(interval1) != 1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::eraseOverlapIntervals(interval2) != 2) {
    throw std::runtime_error("error 2");
  }
  if (Solution::eraseOverlapIntervals(interval3) != 0) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
