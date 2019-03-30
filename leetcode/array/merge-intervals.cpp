//
// Created by Lu, Chih-chiang on 2019-01-02.
//

/**
 * Merge Intervals
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */

#include <vector>
#include <algorithm>
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
  static std::vector<Interval> merge(std::vector<Interval> &intervals) {
    if (intervals.empty()) {
      return {};
    }
    std::sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) { return a.start < b.start; });

    int n = intervals.size();
    std::vector<Interval> res{intervals[0]};
    for (int i = 1; i < n; ++i) {
      if (res.back().end >= intervals[i].start) {
        res.back().end = std::max(res.back().end, intervals[i].end);
      } else {
        res.push_back(intervals[i]);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Interval ex_1(1, 3);
  Interval ex_2(2, 6);
  Interval ex_3(8, 10);
  Interval ex_4(15, 18);
  Interval ans_1(1, 6);
  Interval ans_2(8, 10);
  Interval ans_3(15, 18);
  std::vector<Interval> vec = {ex_1, ex_2, ex_3, ex_4};
  std::vector<Interval> out = {ans_1, ans_2, ans_3};
  auto res = Solution::merge(vec);
  for (int i = 0; i < res.size(); ++i) {
    if (res[i].start != out[i].start || res[i].end != out[i].end) {
      throw std::runtime_error("error");
    }
  }
  return 0;
}
