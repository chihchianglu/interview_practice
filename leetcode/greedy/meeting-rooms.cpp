//
// Created by Lu, Chih-chiang on 2019-01-31.
//

/**
 * Meeting Rooms
 *
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
 * determine if a person could attend all meetings.
 *
 * For example,
 * Given [[0, 30],[5, 10],[15, 20]],
 * return false.
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
  static bool canAttendMeetings(std::vector<Interval> &intervals) {
    int n = intervals.size();
    std::sort(intervals.begin(),
              intervals.end(),
              [](const Interval &a, const Interval &b) { return a.start < b.start; });
    for (int i = 1; i < n; ++i) {
      if (intervals[i - 1].end > intervals[i].start) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  std::vector<Interval> vec = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
  if (Solution::canAttendMeetings(vec)) {
    throw std::runtime_error("error");
  }
  return 0;
}
