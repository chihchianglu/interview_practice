//
// Created by Lu, Chih-chiang on 2018-12-30.
//

/**
 * Insert Interval
 *
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 *
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 *
 * Example 2:
 *
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 *
 * Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
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
  static std::vector<Interval> insert(std::vector<Interval> &intervals, Interval newInterval) {
    std::vector<Interval> res;
    int n = intervals.size(), cur = 0;

    // add intervals ends before new starts
    while (cur < n && intervals[cur].end < newInterval.start) {
      res.push_back(intervals[cur++]);
    }

    // merge overlapping intervals
    while (cur < n && intervals[cur].start <= newInterval.end) {
      newInterval.start = std::min(intervals[cur].start, newInterval.start);
      newInterval.end = std::max(intervals[cur].end, newInterval.end);
      ++cur;
    }
    res.push_back(newInterval);

    // add the rests
    while (cur < n) {
      res.push_back(intervals[cur++]);
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  Interval ex1_1(1, 3);
  Interval ex1_2(6, 9);
  Interval ex1_new(2, 5);
  Interval ans1_1(1, 5);
  Interval ans1_2(6, 9);

  std::vector<Interval> vec1 = {ex1_1, ex1_2};
  std::vector<Interval> out1 = {ans1_1, ans1_2};
  auto res1 = Solution::insert(vec1, ex1_new);
  for (int i = 0; i < res1.size(); ++i) {
    if (res1[i].start != out1[i].start || res1[i].end != out1[i].end) {
      throw std::runtime_error("error 1");
    }
  }

  Interval ex2_1(1, 2);
  Interval ex2_2(3, 5);
  Interval ex2_3(6, 7);
  Interval ex2_4(8, 10);
  Interval ex2_5(12, 16);
  Interval ex2_new(4, 8);
  Interval ans2_1(1, 2);
  Interval ans2_2(3, 10);
  Interval ans2_3(12, 16);
  std::vector<Interval> vec2 = {ex2_1, ex2_2, ex2_3, ex2_4, ex2_5};
  std::vector<Interval> out2 = {ans2_1, ans2_2, ans2_3};
  auto res2 = Solution::insert(vec2, ex2_new);
  for (int i = 0; i < res2.size(); ++i) {
    if (res2[i].start != out2[i].start || res2[i].end != out2[i].end) {
      throw std::runtime_error("error 2");
    }
  }

  return 0;
}
